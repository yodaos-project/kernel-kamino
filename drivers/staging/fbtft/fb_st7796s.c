/*
 * FB driver for the ST7789V LCD Controller
 *
 * Copyright (C) 2015 Dennis Menschel
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <video/mipi_display.h>

#include "fbtft.h"

#define DRVNAME "fb_st7796s"

#define DEFAULT_GAMMA \
	"70 2C 2E 15 10 09 48 33 53 0B 19 18 20 25\n" \
	"70 2C 2E 15 10 09 48 33 53 0B 19 18 20 25"

/**
 * enum st7789v_command - ST7789V display controller commands
 *
 * @PORCTRL: porch setting
 * @GCTRL: gate control
 * @VCOMS: VCOM setting
 * @VDVVRHEN: VDV and VRH command enable
 * @VRHS: VRH set
 * @VDVS: VDV set
 * @VCMOFSET: VCOM offset set
 * @PWCTRL1: power control 1
 * @PVGAMCTRL: positive voltage gamma control
 * @NVGAMCTRL: negative voltage gamma control
 *
 * The command names are the same as those found in the datasheet to ease
 * looking up their semantics and usage.
 *
 * Note that the ST7789V display controller offers quite a few more commands
 * which have been omitted from this list as they are not used at the moment.
 * Furthermore, commands that are compliant with the MIPI DCS have been left
 * out as well to avoid duplicate entries.
 */

enum st7796s_command {
	SLPOUT	= 	0x11,	//sleep out
	CSCON	=	0xF0,	//Command Set Control
	MADCTL	=	0x36,	//Memory Data Access Control
	COLMOD	=	0x3A,	//Interface Pixel Format
	MODESEL	=	0xB9,	//Mode Selection
	DIC	=	0xB4,	//Display Inversion Control
	PWR1	=	0xC0,	//Power Control 1
	PWR2	=	0xC1,	//Power Control 2
	PWR3	=	0xC2,	//Power Control 3
	VCMPCTL	=	0xC5,	//VCOM Control
	DOCA	=	0xE8,	//Display Output Ctrl Adjust
	PGC	=	0xE0,	//Positive Gamma Control
	NGC	=	0xE1,	//Negtive Gamma Control
	INVON	=	0x21,	//Display Inversion On
	DISPON	=	0x29,	//Display On
};

/*
enum st7789v_command {
	PORCTRL = 0xB2,
	GCTRL = 0xB7,
	VCOMS = 0xBB,
	VDVVRHEN = 0xC2,
	VRHS = 0xC3,
	VDVS = 0xC4,
	VCMOFSET = 0xC5,
	PWCTRL1 = 0xD0,
	PVGAMCTRL = 0xE0,
	NVGAMCTRL = 0xE1,
};

*/

#define MADCTL_BGR BIT(3) /* bitmask for RGB/BGR order */
#define MADCTL_MV BIT(5) /* bitmask for page/column order */
#define MADCTL_MX BIT(6) /* bitmask for column address order */
#define MADCTL_MY BIT(7) /* bitmask for page address order */

/**
 * init_display() - initialize the display controller
 *
 * @par: FBTFT parameter object
 *
 Most of the commands in this init function set their parameters to the
 * same default values which are already in place after the display has been
 * powered up. (The main exception to this rule is the pixel format which
 * would default to 18 instead of 16 bit per pixel.)
 * Nonetheless, this sequence can be used as a template for concrete
 * displays which usually need some adjustments.
 *
 * Return: 0 on success, < 0 if error occurred.
 */
static int init_display(struct fbtft_par *par)
{
	par->fbtftops.reset(par);

    write_reg(par, SLPOUT);
	mdelay(120);

	write_reg(par, CSCON, 0xC3);
	write_reg(par, CSCON, 0x96);
	write_reg(par, MADCTL, 0x40); //0x48->0x40  bgr->rgb,0x40->0x0 column address order.
	write_reg(par, COLMOD, 0x55); //0x66->0x55
	write_reg(par, MODESEL, 0x02);

	//LCDSPI_InitCMD(0xB0);//MCU和SPI需屏蔽
	//LCDSPI_InitDAT(0x11);
	//LCDSPI_InitDAT(0xF0);
	//
	//LCDSPI_InitCMD(0xB1);//MCU和SPI需屏蔽
	//LCDSPI_InitDAT(0xC0);
	//LCDSPI_InitDAT(0x02);
	//LCDSPI_InitDAT(0x14);

	write_reg(par, DIC, 0x01);

	//LCDSPI_InitCMD(0xB7);
	//LCDSPI_InitDAT(0x35);

	//LCDSPI_InitCMD(0xBB);
	//LCDSPI_InitDAT(0x19);

	write_reg(par, PWR1, 0x80, 0x70);	//AVDD=6.6V, AVCL=-4.4V
						//VGH=15V, VGL=-7.6V

	write_reg(par, PWR2, 0x19);			//VRH=5.1V
	write_reg(par, PWR3, 0xA7);	

	write_reg(par, VCMPCTL, 0x0A);	//VCOM Control
								//VCOM=1.125V

	write_reg(par, DOCA, 0x40, 0x8A, 0x00, 0x00, 0x29, 0x10, 0x32, 0x33);	//Display Output Ctrl Adjust

	//Positive Voltage Gamma Control
	write_reg(par, PGC, 0xF0, 0x09, 0x10, 0x08, 0x0A, 0x16, 0x37, 0x40, 0x4D, 0x28, 0x13, 0x14, 0x31, 0x32);

	//Negative Voltage Gamma Control
	write_reg(par, NGC, 0xF0, 0x09, 0x0F, 0x0B, 0x0A, 0x16, 0x37, 0x46, 0x4D, 0x28, 0x13, 0x15, 0x32, 0x33);


	write_reg(par, CSCON, 0xC3);
	write_reg(par, CSCON, 0x96);

	write_reg(par, INVON);	//Display Inversion On
	mdelay(120);
	write_reg(par, SLPOUT);	//Sleep Out
	mdelay(120);           // Delay 120ms
	write_reg(par, DISPON);	// Display ON

	printk("machao +++++++++++%s....\n",__func__);
	return 0;
}

/**
 * set_var() - apply LCD properties like rotation and BGR mode
 *
 * @par: FBTFT parameter object
 *
 * Return: 0 on success, < 0 if error occurred.
 */
static int set_var(struct fbtft_par *par)
{
	u8 madctl_par = 0;

	if (par->bgr)
		madctl_par |= MADCTL_BGR;
	switch (par->info->var.rotate) {
	case 0:
		break;
	case 90:
		madctl_par |= (MADCTL_MV | MADCTL_MY);
		break;
	case 180:
		madctl_par |= (MADCTL_MX | MADCTL_MY);
		break;
	case 270:
		madctl_par |= (MADCTL_MV | MADCTL_MX);
		break;
	default:
		return -EINVAL;
	}
	write_reg(par, MIPI_DCS_SET_ADDRESS_MODE, madctl_par);
    printk("machao +++++++++++%s....\n",__func__);
	return 0;
}

/**
 * set_gamma() - set gamma curves
 *
 * @par: FBTFT parameter object
 * @curves: gamma curves
 *
 * Before the gamma curves are applied, they are preprocessed with a bitmask
 * to ensure syntactically correct input for the display controller.
 * This implies that the curves input parameter might be changed by this
 * function and that illegal gamma values are auto-corrected and not
 * reported as errors.
 *
 * Return: 0 on success, < 0 if error occurred.
 */
static int set_gamma(struct fbtft_par *par, unsigned long *curves)
{
	int i;
	int j;
	int c; /* curve index offset */

	/*
	 * Bitmasks for gamma curve command parameters.
	 * The masks are the same for both positive and negative voltage
	 * gamma curves.
	 */
	const u8 gamma_par_mask[] = {
		0xFF, /* V63[3:0], V0[3:0]*/
		0x3F, /* V1[5:0] */
		0x3F, /* V2[5:0] */
		0x1F, /* V4[4:0] */
		0x1F, /* V6[4:0] */
		0x3F, /* J0[1:0], V13[3:0] */
		0x7F, /* V20[6:0] */
		0x77, /* V36[2:0], V27[2:0] */
		0x7F, /* V43[6:0] */
		0x3F, /* J1[1:0], V50[3:0] */
		0x1F, /* V57[4:0] */
		0x1F, /* V59[4:0] */
		0x3F, /* V61[5:0] */
		0x3F, /* V62[5:0] */
	};

	for (i = 0; i < par->gamma.num_curves; i++) {
		c = i * par->gamma.num_values;
		for (j = 0; j < par->gamma.num_values; j++)
			curves[c + j] &= gamma_par_mask[j];
		write_reg(
			par, PGC + i,
			curves[c + 0], curves[c + 1], curves[c + 2],
			curves[c + 3], curves[c + 4], curves[c + 5],
			curves[c + 6], curves[c + 7], curves[c + 8],
			curves[c + 9], curves[c + 10], curves[c + 11],
			curves[c + 12], curves[c + 13]);
	}
    printk("machao +++++++++++%s....\n",__func__);
	return 0;
}

/**
 * blank() - blank the display
 *
 * @par: FBTFT parameter object
 * @on: whether to enable or disable blanking the display
 *
 * Return: 0 on success, < 0 if error occurred.
 */
static int blank(struct fbtft_par *par, bool on)
{
	if (on)
		write_reg(par, MIPI_DCS_SET_DISPLAY_OFF);
	else
		write_reg(par, MIPI_DCS_SET_DISPLAY_ON);
    printk("machao +++++++++++%s....\n",__func__);
	return 0;
}

static struct fbtft_display display = {
	.regwidth = 8,
	.width = 320,
	.height = 320,
	.gamma_num = 2,
	.gamma_len = 14,
	.gamma = DEFAULT_GAMMA,
	.fbtftops = {
		.init_display = init_display,
		.set_var = set_var,
		.set_gamma = set_gamma,
		.blank = blank,
	},
};

FBTFT_REGISTER_DRIVER(DRVNAME, "sitronix,st7796s", &display);

MODULE_ALIAS("spi:" DRVNAME);
MODULE_ALIAS("platform:" DRVNAME);
MODULE_ALIAS("spi:st7796s");
MODULE_ALIAS("platform:st7796s");

MODULE_DESCRIPTION("FB driver for the ST7796S LCD Controller");
MODULE_AUTHOR("TJT");
MODULE_LICENSE("GPL");

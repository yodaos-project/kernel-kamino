#ifndef __NAU8822_H__
#define __NAU8822_H__
#include <linux/i2c.h>
/*
 * Register values.
 */
#define NAU8822_REG_RESET                       0x00
#define NAU8822_REG_POWER_MANAGEMENT_1          0x01
#define NAU8822_REG_POWER_MANAGEMENT_2          0x02
#define NAU8822_REG_POWER_MANAGEMENT_3          0x03
#define NAU8822_REG_AUDIO_INTERFACE             0x04
#define NAU8822_REG_COMPANDING_CONTROL          0x05
#define NAU8822_REG_CLOCKING                    0x06
#define NAU8822_REG_ADDITIONAL_CONTROL          0x07
#define NAU8822_REG_GPIO_CONTROL                0x08
#define NAU8822_REG_JACK_DETECT_CONTROL_1       0x09
#define NAU8822_REG_DAC_CONTROL                 0x0A
#define NAU8822_REG_LEFT_DAC_DIGITAL_VOLUME     0x0B
#define NAU8822_REG_RIGHT_DAC_DIGITAL_VOLUME    0x0C
#define NAU8822_REG_JACK_DETECT_CONTROL_2       0x0D
#define NAU8822_REG_ADC_CONTROL                 0x0E
#define NAU8822_REG_LEFT_ADC_DIGITAL_VOLUME     0x0F
#define NAU8822_REG_RIGHT_ADC_DIGITAL_VOLUME    0x10
#define NAU8822_REG_EQ1                         0x12
#define NAU8822_REG_EQ2                         0x13
#define NAU8822_REG_EQ3                         0x14
#define NAU8822_REG_EQ4                         0x15
#define NAU8822_REG_EQ5                         0x16
#define NAU8822_REG_DAC_LIMITER_1               0x18
#define NAU8822_REG_DAC_LIMITER_2               0x19
#define NAU8822_REG_NOTCH_FILTER_1              0x1B
#define NAU8822_REG_NOTCH_FILTER_2              0x1C
#define NAU8822_REG_NOTCH_FILTER_3              0x1D
#define NAU8822_REG_NOTCH_FILTER_4              0x1E
#define NAU8822_REG_ALC_CONTROL_1               0x20
#define NAU8822_REG_ALC_CONTROL_2               0x21
#define NAU8822_REG_ALC_CONTROL_3               0x22
#define NAU8822_REG_NOISE_GATE                  0x23
#define NAU8822_REG_PLL_N                       0x24
#define NAU8822_REG_PLL_K1                      0x25
#define NAU8822_REG_PLL_K2                      0x26
#define NAU8822_REG_PLL_K3                      0x27
#define NAU8822_REG_3D_CONTROL                  0x29
#define NAU8822_REG_R_SPEAKER_CONTROL           0x2B
#define NAU8822_REG_INPUT_CONTROL               0x2C
#define NAU8822_REG_LEFT_INP_PGA_CONTROL        0x2D
#define NAU8822_REG_RIGHT_INP_PGA_CONTROL       0x2E
#define NAU8822_REG_LEFT_ADC_BOOST_CONTROL      0x2F
#define NAU8822_REG_RIGHT_ADC_BOOST_CONTROL     0x30
#define NAU8822_REG_OUTPUT_CONTROL              0x31
#define NAU8822_REG_LEFT_MIXER_CONTROL          0x32
#define NAU8822_REG_RIGHT_MIXER_CONTROL         0x33
#define NAU8822_REG_LHP_VOLUME                  0x34
#define NAU8822_REG_RHP_VOLUME                  0x35
#define NAU8822_REG_LSPKOUT_VOLUME              0x36
#define NAU8822_REG_RSPKOUT_VOLUME              0x37
#define NAU8822_REG_AUX2_MIXER                  0x38
#define NAU8822_REG_AUX1_MIXER                  0x39
#define NAU8822_REG_POWER_MANAGEMENT_4          0x3A
#define NAU8822_REG_LEFT_TIME_SLOT              0x3B
#define NAU8822_REG_MISC                        0x3C
#define NAU8822_REG_RIGHT_TIME_SLOT             0x3D
#define NAU8822_REG_DEVICE_REVISION             0x3E
#define NAU8822_REG_DEVICE_ID                   0x3F
#define NAU8822_REG_DAC_DITHER                  0x41
#define NAU8822_REG_ALC_ENHANCE_1               0x46
#define NAU8822_REG_ALC_ENHANCE_2               0x47
#define NAU8822_REG_192KHZ_SAMPLING             0x48
#define NAU8822_REG_MISC_CONTROL                0x49
#define NAU8822_REG_INPUT_TIEOFF                0x4A
#define NAU8822_REG_POWER_REDUCTION             0x4B
#define NAU8822_REG_AGC_PEAK2PEAK               0x4C
#define NAU8822_REG_AGC_PEAK_DETECT             0x4D
#define NAU8822_REG_AUTOMUTE_CONTROL            0x4E
#define NAU8822_REG_OUTPUT_TIEOFF               0x4F
#define NAU8822_REG_MAX_REGISTER                NAU8822_REG_OUTPUT_TIEOFF

#define NAU8822_REFIMP_MASK         0x3
#define NAU8822_REFIMP_80K          0x1
#define NAU8822_MAX_DB_INDEX        0xFF
#define HP_DETECT_DELAY             20

/* codec private data */
struct nau8822_priv {
	struct i2c_client *i2c;
	struct device *dev;
	enum snd_soc_bias_level status;
	struct gpio_desc *gpio_hp_det;
	struct snd_soc_jack jack;
	struct timer_list timer;
	unsigned int mute_index;
	unsigned int vol_index;
	unsigned int playback_index;
	unsigned int gpio_val;
	bool         need_hp_det;
};

#endif	/* __NAU8822_H__ */

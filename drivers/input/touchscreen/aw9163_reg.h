#ifndef _AW9163_REG_H_
#define _AW9163_REG_H_

/********************************************
 * Register List
 *******************************************/
#define     AW9163_REG_RSTR             0x00
#define     AW9163_REG_GCR              0x01
#define     AW9163_REG_SLPR             0x02
#define     AW9163_REG_INTER            0x03
#define     AW9163_REG_OSR1             0x04
#define     AW9163_REG_OSR2             0x05
#define     AW9163_REG_OSR3             0x06
#define     AW9163_REG_AKSR             0x07
#define     AW9163_REG_SLSR             0x08
#define     AW9163_REG_INITTMR          0x09
#define     AW9163_REG_THR0             0x0a
#define     AW9163_REG_THR1             0x0b
#define     AW9163_REG_THR2             0x0c
#define     AW9163_REG_THR3             0x0d
#define     AW9163_REG_THR4             0x0e
#define     AW9163_REG_THR5             0x0f
#define     AW9163_REG_NOISTHR          0x10
#define     AW9163_REG_SCFG1            0x11
#define     AW9163_REG_SCFG2            0x12
#define     AW9163_REG_OFR1             0x13
#define     AW9163_REG_OFR2             0x14
#define     AW9163_REG_OFR3             0x15
#define     AW9163_REG_DOFCF0           0x16
#define     AW9163_REG_DOFCF1           0x17
#define     AW9163_REG_IDLECR           0x18
#define     AW9163_REG_MPTR             0x19
#define     AW9163_REG_DISMAX           0x1a
#define     AW9163_REG_SETCNT           0x1b
#define     AW9163_REG_BLCTH            0x1c
#define     AW9163_REG_BLDTH            0x1d
#define     AW9163_REG_MCR              0x1e
#define     AW9163_REG_ANAR             0x1f
#define     AW9163_REG_GDCFGR           0x20
#define     AW9163_REG_GDTR             0x21
#define     AW9163_REG_TDTR             0x22
#define     AW9163_REG_GESTR1           0x23
#define     AW9163_REG_GESTR2           0x24
#define     AW9163_REG_GESTR3           0x25
#define     AW9163_REG_GESTR4           0x26
#define     AW9163_REG_TAPR1            0x27
#define     AW9163_REG_GESTR5           0x28
#define     AW9163_REG_GESTR6           0x29
#define     AW9163_REG_GESTR7           0x2a
#define     AW9163_REG_GESTR8           0x2b
#define     AW9163_REG_TAPR2            0x2c
#define     AW9163_REG_GIER             0x2d
#define     AW9163_REG_GISR             0x2e
#define     AW9163_REG_GTIMR            0x2f
#define     AW9163_REG_RAWST            0x30
#define     AW9163_REG_AKSST            0x31
#define     AW9163_REG_ISR              0x32
#define     AW9163_REG_COR              0x33
#define     AW9163_REG_FGPRSR           0x34
#define     AW9163_REG_MOVCNTR          0x35
#define     AW9163_REG_KDATA0           0x36
#define     AW9163_REG_KDATA1           0x37
#define     AW9163_REG_KDATA2           0x38
#define     AW9163_REG_KDATA3           0x39
#define     AW9163_REG_KDATA4           0x3a
#define     AW9163_REG_KDATA5           0x3b
#define     AW9163_REG_DUM0             0x3c
#define     AW9163_REG_DUM1             0x3d
#define     AW9163_REG_SA_COX           0x3f
#define     AW9163_REG_LER1             0x50
#define     AW9163_REG_LER2             0x51
#define     AW9163_REG_LCR              0x52
#define     AW9163_REG_PMR              0x53
#define     AW9163_REG_RMR              0x54
#define     AW9163_REG_CTRS1            0x55
#define     AW9163_REG_CTRS2            0x56
#define     AW9163_REG_IMAX1            0x57
#define     AW9163_REG_IMAX2            0x58
#define     AW9163_REG_IMAX3            0x59
#define     AW9163_REG_IMAX4            0x5a
#define     AW9163_REG_IMAX5            0x5b
#define     AW9163_REG_TIER             0x5c
#define     AW9163_REG_INTVEC           0x5d
#define     AW9163_REG_LISR2            0x5e
#define     AW9163_REG_SADDR            0x5f
#define     AW9163_REG_PCR              0x60
#define     AW9163_REG_CMDR             0x61
#define     AW9163_REG_RA               0x62
#define     AW9163_REG_RB               0x63
#define     AW9163_REG_RC               0x64
#define     AW9163_REG_RD               0x65
#define     AW9163_REG_R1               0x66
#define     AW9163_REG_R2               0x67
#define     AW9163_REG_R3               0x68
#define     AW9163_REG_R4               0x69
#define     AW9163_REG_R5               0x6a
#define     AW9163_REG_R6               0x6b
#define     AW9163_REG_R7               0x6c
#define     AW9163_REG_R8               0x6d
#define     AW9163_REG_GRPMSK1          0x6e
#define     AW9163_REG_GRPMSK2          0x6f
#define     AW9163_REG_TCR              0x70
#define     AW9163_REG_TAR              0x71
#define     AW9163_REG_TDR              0x72
#define     AW9163_REG_TDATA            0x73
#define     AW9163_REG_TANA             0x74
#define     AW9163_REG_TKST             0x75
#define     AW9163_REG_FEXT             0x76
#define     AW9163_REG_WP               0x7d
#define     AW9163_REG_WADDR            0x7e
#define     AW9163_REG_WDATA            0x7f

/********************************************
 * Register Access
 *******************************************/
#define REG_NONE_ACCESS 0
#define REG_RD_ACCESS  1 << 0
#define REG_WR_ACCESS  1 << 1
const unsigned char aw9163_reg_access[AW9163_REG_MAX] = {
	    [AW9163_REG_RSTR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GCR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SLPR] = REG_RD_ACCESS,
	    [AW9163_REG_INTER] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_OSR1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_OSR2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_OSR3] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_AKSR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SLSR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_INITTMR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_THR0] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_THR1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_THR2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_THR3] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_THR4] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_THR5] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_NOISTHR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SCFG1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SCFG2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_OFR1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_OFR2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_OFR3] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_DOFCF0] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_DOFCF1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_IDLECR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_MPTR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_DISMAX] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SETCNT] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_BLCTH] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_BLDTH] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_MCR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_ANAR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GDCFGR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GDTR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TDTR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR3] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR4] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TAPR1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR5] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR6] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR7] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GESTR8] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TAPR2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GIER] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GISR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_GTIMR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_RAWST] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_AKSST] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_ISR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_COR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_FGPRSR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_MOVCNTR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_KDATA0] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_KDATA1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_KDATA2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_KDATA3] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_KDATA4] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_KDATA5] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_DUM0] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_DUM1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SA_COX] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_LER1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_LER2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_LCR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_PMR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_RMR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_CTRS1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_CTRS2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_IMAX1] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_IMAX2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_IMAX3] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_IMAX4] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_IMAX5] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TIER] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_INTVEC] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_LISR2] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_SADDR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_PCR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_CMDR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_RA] = REG_RD_ACCESS,
	    [AW9163_REG_RB] = REG_RD_ACCESS,
	    [AW9163_REG_RC] = REG_RD_ACCESS,
	    [AW9163_REG_RD] = REG_RD_ACCESS,
	    [AW9163_REG_R1] = REG_RD_ACCESS,
	    [AW9163_REG_R2] = REG_RD_ACCESS,
	    [AW9163_REG_R3] = REG_RD_ACCESS,
	    [AW9163_REG_R4] = REG_RD_ACCESS,
	    [AW9163_REG_R5] = REG_RD_ACCESS,
	    [AW9163_REG_R6] = REG_RD_ACCESS,
	    [AW9163_REG_R7] = REG_RD_ACCESS,
	    [AW9163_REG_R8] = REG_RD_ACCESS,
	    [AW9163_REG_GRPMSK1] = REG_RD_ACCESS,
	    [AW9163_REG_GRPMSK2] = REG_RD_ACCESS,
	    [AW9163_REG_TCR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TAR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TDR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TDATA] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TANA] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_TKST] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_FEXT] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_WP] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_WADDR] = REG_RD_ACCESS | REG_WR_ACCESS,
	    [AW9163_REG_WDATA] = REG_RD_ACCESS | REG_WR_ACCESS
};


/******************************************************
 * Register Detail
 *****************************************************/
#endif	/*  */

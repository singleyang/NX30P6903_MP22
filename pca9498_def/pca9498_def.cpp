/*			pca9498_def.cpp
 *			Created: 2016/07/30
 *          Author: Erik Lam
 *        
 *			Contains global variables, helper functions and constants. 
 *			All together they make up a model of the pca9498's registers and 
 *			the data fields therein.
 */

#include "pca9498_def.h"
#include "pca9498_types.h"
#include <stdio.h>

#ifdef _DEBUG
//#define PCA9498_AUTO_INC          0x00
#define PCA9498_AUTO_INC          0x80
#else
#define PCA9498_AUTO_INC          0x80
#endif

pca_data_bits_t pca_data_bits_default[] = {
	/* 00 */ 0x03, 0x00, 0x00, 0x00, 
	/* 04 */ 0x00, 0xFE, 0x2C, 0x8F, 
	/* 08 */ 0xFF, 0xA0, 0x34, 0x14, 
	/* 0C */ 0x3C, 0x14, 0x0A, 0x28, 
	/* 10 */ 0x46, 0x1E, 0x23, 
	/* 13 */ 0x0000, 
	/* 15 */ 0x0000, 
	/* 17 */ 0x0000, 
	/* 19 */ 0x0000, 
	/* 1B */ 0x0000, 
	/* 1D */ 0x0000, 
	/* 1F */ 0x0000, 
	/* 21 */ 0x0000, 
	/* 23 */ 0x19,
};

void pca_tf_Three_bits(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 2) {
			sprintf_s(textbuffer, sz, "%03d", index);
		}
	}
}

void pca_tf_byte(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 5) {
			sprintf_s(textbuffer, sz, "0x%02X", index);
		}
	}
}

void pca_tf_vbus_ovp(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			if (index <= 92)
				sprintf_s(textbuffer, sz, "%0.3fV", 4.2 + (index * 0.025));
			else
				sprintf_s(textbuffer, sz, "%s", "Illegal value");
		}
	}
}

void pca_tf_vout_reg(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			if (index <= 80)
				sprintf_s(textbuffer, sz, "%0.2fV", 4.2 + (index * 0.010));
			else
				sprintf_s(textbuffer, sz, "%s", "Illegal value");
		}
	}
}

void pca_tf_ibat_reg(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			if (index <= 127)
				sprintf_s(textbuffer, sz, "%0.2fA", index * 0.050);
			else
				sprintf_s(textbuffer, sz, "%s", "Illegal value");
		}
	}
}

void pca_tf_tbus_reg(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			if (index <= 120)
				sprintf_s(textbuffer, sz, "%0.2fV", index * 0.020);
			else
				sprintf_s(textbuffer, sz, "%s", "Illegal value");
		}
	}
}

void pca_tf_V_adc(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			float val = (index & 0x1FFF);
			if ((index & 0x8000) == 0x8000) val *= -1;
			sprintf_s(textbuffer, sz, "%0.3fV", val / 1000);
		}
	}
}

void pca_tf_V10_adc(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			float val = index & 0x3FF;
			if ((index & 0x8000) == 0x8000) val *= -1;
			sprintf_s(textbuffer, sz, "%0.3fV", val / 1000);
		}
	}
}

void pca_tf_A_adc(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			float val = index & 0x1FFF;
			if ((index & 0x8000) == 0x8000) val *= -1;
			sprintf_s(textbuffer, sz, "%0.3fA", val / 1000);
		}
	}
}

void pca_tf_T_adc(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			float val = index & 0x0FFF;
			if ((index & 0x8000) == 0x8000) val *= -1;
			sprintf_s(textbuffer, sz, "%0.3fV", val / 1000);
		}
	}
}

void pca_tf_die_temp(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			sprintf_s(textbuffer, sz, "%d °C", index);
		}
	}
}

void pca_tf_vdrop_ovp(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			if (index <= 200)
				sprintf_s(textbuffer, sz, "%0.3fV", (index * 0.005));
			else
				sprintf_s(textbuffer, sz, "%s", "Illegal value");
		}
	}
}

void pca_tf_Current(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			sprintf_s(textbuffer, sz, "%0.2fA", (index * 10.0) / 1000.0);
		}
	}
}

void pca_tf_OVP_level(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			switch (index)
			{
				case 0:
					sprintf_s(textbuffer, sz, "%s", "Off");
					break;
				case 1:
					sprintf_s(textbuffer, sz, "%s", "15%");
					break;
				case 2:
					sprintf_s(textbuffer, sz, "%s", "20%");
					break;
				default:
					sprintf_s(textbuffer, sz, "%s", "25%");
					break;
			}
		}
	}
}

void pca_tf_OCP_level(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			sprintf_s(textbuffer, sz, "%0.1f A", index * 0.5);
		}
	}
}

void pca_tf_En_Dis(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 9) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Enabled");
			else
				sprintf_s(textbuffer, sz, "%s", "Disabled");	
		}
	}
}

void pca_tf_OCP_res(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 14) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Blanking mode");
			else
				sprintf_s(textbuffer, sz, "%s", "Hiccup mode");	
		}
	}
}

void pca_tf_vbus_ovp_dly(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 14) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "4 µs");
			else
				sprintf_s(textbuffer, sz, "%s", "20 µs");	
		}
	}
}

void pca_tf_adc_samples(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 3) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "8");
			else
				sprintf_s(textbuffer, sz, "%s", "16");	
		}
	}
}

void pca_tf_adc_rate(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 9) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Single shot");
			else
				sprintf_s(textbuffer, sz, "%s", "Continuous");	
		}
	}
}

void pca_tf_Irev(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 3) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "0A");
			else
				sprintf_s(textbuffer, sz, "%s", "3A");	
		}
	}
}

void pca_tf_watchdog(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 9) {
			switch (index)
			{
				case 0:
					sprintf_s(textbuffer, sz, "%s", "Disabled");
					break;
				case 1:
					sprintf_s(textbuffer, sz, "%s", "0.5s");
					break;
				case 2:
					sprintf_s(textbuffer, sz, "%s", "1.0s");
					break;
				default:
					sprintf_s(textbuffer, sz, "%s", "2.0s");
					break;
			}
		}
	}
}

void pca_tf_sense_R(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "5 mOhm");
			else
				sprintf_s(textbuffer, sz, "%s", "10 mOhm");
		}
	}
}

void pca_tf_Vbus_OVP(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 21) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "no fault");
			else
				sprintf_s(textbuffer, sz, "%s", "Vbus > VBUS_OVP fault");
		}
	}
}

void pca_tf_regulation(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 22) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "not in regulation mode");
			else
				sprintf_s(textbuffer, sz, "%s", "in regulation mode");
		}
	}
}

void pca_tf_no_yes(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 4) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "No");
			else
				sprintf_s(textbuffer, sz, "%s", "Yes");
		}
	}
}

void pca_tf_temperature(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 9) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Ok");
			else
				sprintf_s(textbuffer, sz, "%s", "Too high");
		}
	}
}

void pca_adc_done(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 13) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Not complete");
			else
				sprintf_s(textbuffer, sz, "%s", "Completed");
		}
	}
}

void pca_tf_wd(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 23) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Disabled or not expired");
			else
				sprintf_s(textbuffer, sz, "%s", "Expired");
		}
	}
}

void pca_tf_unset_set(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 9) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Not set");
			else
				sprintf_s(textbuffer, sz, "%s", "Set");
		}
	}
}

void pca_tf_vbusbat_ins(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 13) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Not present");
			else
				sprintf_s(textbuffer, sz, "%s", "Present");
		}
	}
}

void pca_tf_tshut(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 27) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Ok. < 125°C");
			else
				sprintf_s(textbuffer, sz, "%s", "Too high. Thermal shutdown");
		}
	}
}

void pca_tf_Ibus(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 20) {
			if (index == 0) 
				sprintf_s(textbuffer, sz, "%s", "Within limits");
			else
				sprintf_s(textbuffer, sz, "%s", "Over current fault!");
		}
	}
}

pca_data_field_t pca_DataFields[] = {
	/*27 datafiled in total*/
	{ 0x00, 0,  3,   0, dev_id, "Device ID",  pca_tf_Three_bits  },
	{ 0x00, 3,  3,   0, dev_rev, "Device revision",  pca_tf_Three_bits  },
	{ 0x01, 7,  1,   0, vbus_ovp_mask, "Vbus OVP",  pca_tf_En_Dis  },
	{ 0x01, 6,  1,   0, ibus_reg_mask, "Ibus regulation",  pca_tf_En_Dis  },
	{ 0x01, 5,  1,   0, vbat_reg_mask, "Vbat regulation", pca_tf_En_Dis },
	{ 0x01, 4,  1,   0, ibat_reg_mask, "Ibat regulation", pca_tf_En_Dis },
	{ 0x01, 3,  1,   0, vout_reg_mask, "Vout regulation", pca_tf_En_Dis },
	{ 0x01, 2,  1,   0, vbus_otp_mask, "Vbus OTP", pca_tf_En_Dis},
	{ 0x01, 1,  1,   0, tbat_otp_mask, "Battery OTP", pca_tf_En_Dis},
	{ 0x01, 0,  1,   0, ibus_rev_mask, "Ibus reverse", pca_tf_En_Dis},
	{ 0x02, 7,  1,   0, wd_mask, "Watchdog", pca_tf_En_Dis },
	{ 0x02, 6,  1,   0, adc_done_mask, "ADC done", pca_tf_En_Dis },
	{ 0x02, 5,  1,   0, vdrop_alm_mask, "Vdrop alarm", pca_tf_En_Dis },
	{ 0x02, 4,  1,   0, vdrop_ovp_mask, "Vdrop OVP", pca_tf_En_Dis },
	{ 0x02, 3,  1,   0, vbus_ins_mask, "Vbus insert", pca_tf_En_Dis },
	{ 0x02, 2,  1,   0, bat_ins_mask, "Battery insert", pca_tf_En_Dis },
	{ 0x02, 1,  1,   0, tshut_mask, "Thermal shutdown", pca_tf_En_Dis },
	{ 0x02, 0,  1,   0, ioc_mask, "Ibus OCP", pca_tf_En_Dis },
	{ 0x03, 7,  1,   0, vbus_ovp_flt, "Vbus over voltage", pca_tf_Vbus_OVP },
	{ 0x03, 6,  1,   0, ibus_reg_ldo, "Ibus in regulation", pca_tf_regulation },
	{ 0x03, 5,  1,   0, vbat_reg_ldo, "Vbat in regulation", pca_tf_regulation },
	{ 0x03, 4,  1,   0, ibat_reg_ldo, "Ibat in regulation",  pca_tf_regulation },
	{ 0x03, 3,  1,   0, vout_reg_ldo, "Vout in regulation", pca_tf_regulation},
	{ 0x03, 2,  1,   0, tbus_otp_flt, "Vbus over temperature", pca_tf_temperature },
	{ 0x03, 1,  1,   0, tbat_otp_flt, "Battery over temperature", pca_tf_temperature },
	{ 0x03, 0,  1,   0, ibus_irev_flt, "Ibus reverse current", pca_tf_no_yes },
	{ 0x04, 7,  1,   0, wd_flt, "Watchdog expired", pca_tf_wd },
	{ 0x04, 6,  1,   0, adc_done, "ADC conversion done", pca_adc_done },
	{ 0x04, 5,  1,   0, vdrop_alm_flt, "Vdrop alarm", pca_tf_unset_set },
	{ 0x04, 4,  1,   0, vdrop_ovp_flt, "Vdrop OVP", pca_tf_unset_set },
	{ 0x04, 3,  1,   0, vbus_ins, "Vbus source insert", pca_tf_vbusbat_ins},
	{ 0x04, 2,  1,   0, bat_ins, "Battery insert", pca_tf_vbusbat_ins },
	{ 0x04, 1,  1,   0, tshut_flt, "Die over temperature", pca_tf_tshut },
	{ 0x04, 0,  1,   0, ioc_flt, "Ibus over current", pca_tf_Ibus },
	{ 0x05, 7,  1,   0, vbus_ovp_en, "Vbus OVP", pca_tf_En_Dis },
	{ 0x05, 6,  1,   0, ibus_reg_en, "Ibus regulation", pca_tf_En_Dis },
	{ 0x05, 5,  1,   0, vbat_reg_en, "Vbat regulation", pca_tf_En_Dis },
	{ 0x05, 4,  1,   0, ibat_reg_en, "Ibat regulation", pca_tf_En_Dis },
	{ 0x05, 3,  1,   0, vout_reg_en, "Vout regulation", pca_tf_En_Dis },
	{ 0x05, 2,  1,   0, tbus_otp_en, "Tbus OTP", pca_tf_En_Dis },
	{ 0x05, 1,  1,   0, tbat_otp_en, "Tbat OTP", pca_tf_En_Dis },
	{ 0x05, 0,  1,   0, vbus_pd_en, "Vbus pull-down ctrl", pca_tf_En_Dis },
	{ 0x06, 7,  1,   0, vdrop_ovp_en, "Vdrop OVP", pca_tf_En_Dis },
	{ 0x06, 6,  1,   0, vdrop_alm_en, "Vdrop alarm", pca_tf_En_Dis },
	{ 0x06, 5,  1,   0, sense_r, "Sense resistor", pca_tf_sense_R },
	{ 0x06, 4,  1,   0, chg_en, "Charging enabled", pca_tf_En_Dis},
	{ 0x06, 2,  2,   0, watchdog, "Watchdog timer", pca_tf_watchdog },
	{ 0x06, 1,  1,   0, irev_set, "Reverse current protection", pca_tf_Irev },
	{ 0x06, 0,  1,   0, reg_rst, "Reset all registers", pca_tf_no_yes},
	{ 0x07, 7,  1,   0, tdie_adc_en, "Die temperature", pca_tf_En_Dis },
	{ 0x07, 3,  1,   0, adc_en, "ADC enabled", pca_tf_En_Dis},
	{ 0x07, 2,  1,   0, adc_rate, "ADC rate", pca_tf_adc_rate },
	{ 0x07, 1,  1,   0, adc_avg_en, "ADC averaging", pca_tf_En_Dis },
	{ 0x07, 0,  1,   0, adc_samples, "ADC samples/channel", pca_tf_adc_samples },
	{ 0x08, 7,  1,   0, vbus_adc_en, "Vbus", pca_tf_En_Dis },
	{ 0x08, 6,  1,   0, ibus_adc_en, "Ibus", pca_tf_En_Dis },
	{ 0x08, 5,  1,   0, vout_adc_en, "Vout", pca_tf_En_Dis },
	{ 0x08, 4,  1,   0, vdrop_adc_en, "Vdrop", pca_tf_En_Dis },
	{ 0x08, 3,  1,   0, vbat_adc_en, "Vbat", pca_tf_En_Dis },
	{ 0x08, 2,  1,   0, ibat_adc_en, "Ibat", pca_tf_En_Dis },
	{ 0x08, 1,  1,   0, tbus_adc_en, "Tbus", pca_tf_En_Dis },
	{ 0x08, 0,  1,   0, tbat_adc_en, "Tbat", pca_tf_En_Dis },
	{ 0x09, 4,  4,   0, ibus_ocp, "OCP level", pca_tf_OCP_level },
	{ 0x09, 1,  1,   0, ocp_res, "OCP response", pca_tf_OCP_res },
	{ 0x09, 0,  1,   0, vbus_ovp_dly, "Vbus OVP de-glitch", pca_tf_vbus_ovp_dly },
	{ 0x0A, 0,  7,  93, vbus_ovp, "Vbus OVP level", pca_tf_vbus_ovp },
	{ 0x0B, 0,  7,  81, vout_reg, "Vout LDO threshold", pca_tf_vout_reg },
	{ 0x0C, 0,  8, 201, vdrop_ovp, "Vdrop OVP threshold", pca_tf_vdrop_ovp },
	{ 0x0D, 0,  8, 201, vdrop_alm, "Vdrop alarm threshold", pca_tf_vdrop_ovp },
	{ 0x0E, 0,  7,  81, vbat_reg, "Vbat LDO threshold", pca_tf_vout_reg },
	{ 0x0F, 0,  8, 128, ibat_reg, "Ibat regulator threshold", pca_tf_ibat_reg },
	{ 0x10, 0,  8, 128, ibus_reg, "Ibus regulator threshold", pca_tf_ibat_reg },
	{ 0x11, 0,  7, 121, tbus_reg, "Tbus OTP threshold", pca_tf_tbus_reg },
	{ 0x12, 0,  7, 121, tbat_otp, "Tbat OTP threshold", pca_tf_tbus_reg },
	{ 0x13, 0, 16,   0, vbus_adc, "Vbus ADC", pca_tf_V_adc},
	{ 0x14, 0, 16,   0, ibus_adc, "Ibus ADC", pca_tf_A_adc},
	{ 0x15, 0, 16,   0, vout_adc, "Vout ADC", pca_tf_V_adc },
	{ 0x16, 0, 16,   0, vdrop_adc, "Vdrop ADC", pca_tf_V10_adc },
	{ 0x17, 0, 16,   0, vbat_adc, "Vbat ADC", pca_tf_V_adc },
	{ 0x18, 0, 16,   0, ibat_adc, "Ibat ADC", pca_tf_A_adc },
	{ 0x19, 0, 16,   0, tbus_adc, "Tbus ADC", pca_tf_T_adc },
	{ 0x1A, 0, 16,   0, tbat_adc, "Tbat ADC", pca_tf_T_adc },
	{ 0x1B, 0,  8,   0, die_temp, "Die temperature", pca_tf_die_temp },
	/* Registers 36 registers in total */
	{ 0x00, 0,  8,   0, reg_0, "DEVICE_INFO", pca_tf_byte },
	{ 0x01, 0,  8,   0, reg_1, "EVENT_1_MASK", pca_tf_byte },
	{ 0x02, 0,  8,   0, reg_2, "EVENT_2_MASK", pca_tf_byte },
	{ 0x03, 0,  8,   0, reg_3, "EVENT_1", pca_tf_byte },
	{ 0x04, 0,  8,   0, reg_4, "EVENT_2", pca_tf_byte },
	{ 0x05, 0,  8,   0, reg_5, "EVENT_1_EN", pca_tf_byte },
	{ 0x06, 0,  8,   0, reg_6, "CONTROL", pca_tf_byte },
	{ 0x07, 0,  8,   0, reg_7, "ADC_CTRL", pca_tf_byte },
	{ 0x08, 0,  8,   0, reg_8, "SAMPLE_EN", pca_tf_byte },
	{ 0x09, 0,  8,   0, reg_9, "PROT_DLY&OCP", pca_tf_byte },
	{ 0x0A, 0,  8,   0, reg_a, "VBUS_OVP", pca_tf_byte },
	{ 0x0B, 0,  8,   0, reg_b, "VOUT_REG", pca_tf_byte },
	{ 0x0C, 0,  8,   0, reg_c, "VDROP_OVP", pca_tf_byte },
	{ 0x0D, 0,  8,   0, reg_d, "VDROP_ALARM", pca_tf_byte },
	{ 0x0E, 0,  8,   0, reg_e, "VBAT_REG", pca_tf_byte },
	{ 0x0F, 0,  8,   0, reg_f, "IBAT_REG", pca_tf_byte },
	{ 0x10, 0,  8,   0, reg_10, "IBUS_REG", pca_tf_byte },
	{ 0x11, 0,  8,   0, reg_11, "TBUS_OTP", pca_tf_byte },
	{ 0x12, 0,  8,   0, reg_12, "TBAT_OTP", pca_tf_byte },
	{ 0x13, 8,  8,   0, reg_13, "VBUS_ADC_H", pca_tf_byte },
	{ 0x13, 0,  8,   0, reg_14, "VBUS_ADC_L", pca_tf_byte },
	{ 0x14, 8,  8,   0, reg_15, "IBUS_ADC_H", pca_tf_byte },
	{ 0x14, 0,  8,   0, reg_16, "IBUS_ADC_L", pca_tf_byte },
	{ 0x15, 8,  8,   0, reg_17, "VOUT_ADC_H", pca_tf_byte },
	{ 0x15, 0,  8,   0, reg_18, "VOUT_ADC_L", pca_tf_byte },
	{ 0x16, 8,  8,   0, reg_19, "VDROP_ADC_H", pca_tf_byte },
	{ 0x16, 0,  8,   0, reg_1a, "VDROP_ADC_L", pca_tf_byte },
	{ 0x17, 8,  8,   0, reg_1b, "VBAT_ADC_H", pca_tf_byte },
	{ 0x17, 0,  8,   0, reg_1c, "VBAT_ADC_L", pca_tf_byte },
	{ 0x18, 8,  8,   0, reg_1d, "IBAT_ADC_H", pca_tf_byte },
	{ 0x18, 0,  8,   0, reg_1e, "IBAT_ADC_L", pca_tf_byte },
	{ 0x19, 8,  8,   0, reg_1f, "TBUS_ADC_H", pca_tf_byte },
	{ 0x19, 0,  8,   0, reg_20, "TBUS_ADC_L", pca_tf_byte },
	{ 0x1A, 8,  8,   0, reg_21, "TBAT_ADC_H", pca_tf_byte },
	{ 0x1A, 0,  8,   0, reg_22, "TBAT_ADC_L", pca_tf_byte },
	{ 0x1B, 0,  8,   0, reg_23, "DIE_TEM_ADC", pca_tf_byte },
};

pca_register_t pca_registers[] = {
	{ true,  PCA9498_AUTO_INC | 0x00,  8, pca_data_bits_default[ 0] },
	{ false, PCA9498_AUTO_INC | 0x01,  8, pca_data_bits_default[ 1] },
	{ false, PCA9498_AUTO_INC | 0x02,  8, pca_data_bits_default[ 2] },
	{ true,  PCA9498_AUTO_INC | 0x03,  8, pca_data_bits_default[ 3] },
	{ true,  PCA9498_AUTO_INC | 0x04,  8, pca_data_bits_default[ 4] },
	{ false, PCA9498_AUTO_INC | 0x05,  8, pca_data_bits_default[ 5] },
	{ false, PCA9498_AUTO_INC | 0x06,  8, pca_data_bits_default[ 6] },
	{ false, PCA9498_AUTO_INC | 0x07,  8, pca_data_bits_default[ 7] },
	{ false, PCA9498_AUTO_INC | 0x08,  8, pca_data_bits_default[ 8] },
	{ false, PCA9498_AUTO_INC | 0x09,  8, pca_data_bits_default[ 9] },
	{ false, PCA9498_AUTO_INC | 0x0A,  8, pca_data_bits_default[10] },
	{ false, PCA9498_AUTO_INC | 0x0B,  8, pca_data_bits_default[11] },
	{ false, PCA9498_AUTO_INC | 0x0C,  8, pca_data_bits_default[12] },
	{ false, PCA9498_AUTO_INC | 0x0D,  8, pca_data_bits_default[13] },
	{ false, PCA9498_AUTO_INC | 0x0E,  8, pca_data_bits_default[14] },
	{ false, PCA9498_AUTO_INC | 0x0F,  8, pca_data_bits_default[15] },
	{ false, PCA9498_AUTO_INC | 0x10,  8, pca_data_bits_default[16] },
	{ false, PCA9498_AUTO_INC | 0x11,  8, pca_data_bits_default[17] },
	{ false, PCA9498_AUTO_INC | 0x12,  8, pca_data_bits_default[18] },
	{ true,  PCA9498_AUTO_INC | 0x13, 16, pca_data_bits_default[19] },
	{ true,  PCA9498_AUTO_INC | 0x15, 16, pca_data_bits_default[20] },
	{ true,  PCA9498_AUTO_INC | 0x17, 16, pca_data_bits_default[21] },
	{ true,  PCA9498_AUTO_INC | 0x19, 16, pca_data_bits_default[22] },
	{ true,  PCA9498_AUTO_INC | 0x1B, 16, pca_data_bits_default[23] },
	{ true,  PCA9498_AUTO_INC | 0x1D, 16, pca_data_bits_default[24] },
	{ true,  PCA9498_AUTO_INC | 0x1F, 16, pca_data_bits_default[25] },
	{ true,  PCA9498_AUTO_INC | 0x21, 16, pca_data_bits_default[26] },
	{ true,  PCA9498_AUTO_INC | 0x23,  8, pca_data_bits_default[27] }
};

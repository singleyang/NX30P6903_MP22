/*			pca9468_mp12_def.cpp
 *			Created: 2017/01/31
 *          Author: Yang Yin
 *        
 *			Contains global variables, helper functions and constants. 
 *			All together they make up a model of the pca9498's registers and 
 *			the data fields therein.
 */

#include "pca9468_mp12_def.h"
#include "pca9468_mp12_types.h"
#include <stdio.h>

#ifdef _DEBUG
//#define PCA9498_AUTO_INC          0x00
#define PCA9498_AUTO_INC          0x80
#define PCA9468_MP12_AUTO_INC			0x00
#else
#define PCA9498_AUTO_INC          0x80
#endif

pca_data_bits_t pca_data_bits_default[] = {
	/* 00 */ 0x18, 0x00, 0x00, 0x00, 
	/* 04 */ 0x00, 0x00, 0x00, 0x00, 
	/* 08 */ 0x00, 0x00, 0x00, 0x00, 
	/* 0C */ 0x00, 0x00, 0x00, 0x00, 
	/* 10 */ 0x00, 
	/* 20 */ 0x3C, 0x9E, 0xB0, 0x02,
	/* 24 */ 0xFF, 0x01, 0x00, 0x7B,
	/* 28 */ 0x02, 0xFF, 0x03
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
	/*24 Datafiled in totoal, all callbacks need to be reviewed YY*/
	/*REG 0x00, Device Info*/
	{ 0x00, 0,  3,   0, dev_id, "Device ID",  pca_tf_Three_bits  },
	{ 0x00, 3,  3,   0, dev_rev, "Device Revision",  pca_tf_Three_bits  },
	/*REG 0x01, INT1 (RC) - (should read the INT1_STS for actual interrupt status)*/
	{ 0x01, 7,  1,   0, v_ok_int, "V OK INT",  pca_tf_En_Dis  },	
	{ 0x01, 6, 1, 0, ntc_temp_int, "NTC TEMP INT", pca_tf_En_Dis },
	{ 0x01, 5, 1, 0, chg_phase_int, "CHG PHASE INT", pca_tf_En_Dis },
	{ 0x01, 4, 1, 0, pwr_collapse_int, "PWR COLLAPSE INT ", pca_tf_En_Dis },
	{ 0x01, 3, 1, 0, ctrl_limit_int, "CTRL LIMIT INT ", pca_tf_En_Dis },
	{ 0x01, 2, 1, 0, temp_reg_int, "TEMP REG INT ", pca_tf_En_Dis },
	{ 0x01, 1, 1, 0, adc_done_int, "ADC DONE INT ", pca_tf_En_Dis },
	{ 0x01, 0, 1, 0, timer_int, "TIMER INT ", pca_tf_En_Dis },
	/*REG 0x02, INT1_MASK (R/W)*/
	{ 0x02, 7, 1, 0, v_ok_m, "V OK Int mask", pca_tf_En_Dis },
	{ 0x02, 6, 1, 0, ntc_temp_m, "NTC temp Int mask", pca_tf_En_Dis },
	{ 0x02, 5, 1, 0, chg_phase_m, "Chg phase Int mask", pca_tf_En_Dis },
	{ 0x02, 4, 1, 0, pwr_collapse_m, "Pwr collaspe Int mask", pca_tf_En_Dis },
	{ 0x02, 3, 1, 0, ctrl_limit_m, "Ctrl limit Int mask", pca_tf_En_Dis },
	{ 0x02, 2, 1, 0, temp_reg_m, "Temp reg Int mask", pca_tf_En_Dis },
	{ 0x02, 1, 1, 0, adc_done_m, "Adc done Int mask", pca_tf_En_Dis },
	{ 0x02, 0, 1, 0, timer_m, "Timer Int mask", pca_tf_En_Dis },
	/*REG 0x03, INT1_STS (R)*/
	{ 0x03, 7, 1, 0, v_ok_sts, "V_OK status", pca_tf_Vbus_OVP },
	{ 0x03, 6, 1, 0, ntc_temp_sts, "NTC temp status", pca_tf_regulation },
	{ 0x03, 5, 1, 0, chg_phase_sts, "CHG phrase status(NA)", pca_tf_regulation },
	{ 0x03, 4, 1, 0, pwr_collapse_sts, "Power collapse status", pca_tf_regulation },
	{ 0x03, 3, 1, 0, ctrl_limit_sts, "CTRL limit status", pca_tf_regulation },
	{ 0x03, 2, 1, 0, temp_reg_sts, "TEMP regulation status", pca_tf_temperature },
	{ 0x03, 1, 1, 0, adc_done_sts, "ADC done status", pca_tf_temperature },
	{ 0x03, 0, 1, 0, timer_sts, "Timer status", pca_tf_no_yes },
	/*REG 0x04, STS_A (R)*/
	{ 0x04, 7, 1, 0, iin_loop_sts, "IIN loop status", pca_tf_wd },
	{ 0x04, 6, 1, 0, chg_loop_sts, "ICHG loop status", pca_adc_done },
	{ 0x04, 5, 1, 0, vflt_loop_sts, "V_Float loop status", pca_tf_unset_set },
	{ 0x04, 4, 1, 0, rsvd_1, "Reserved", pca_tf_unset_set },
	{ 0x04, 3, 1, 0, vout_uv_sts, "VOut below V_OK status", pca_tf_vbusbat_ins },
	{ 0x04, 2, 1, 0, vbat_ov_sts, "VBat above VBat_OVLO  ", pca_tf_vbusbat_ins },
	{ 0x04, 1, 1, 0, vin_ov_sts, "VIn above VIn_OVLO", pca_tf_tshut },
	{ 0x04, 0, 1, 0, vin_uv_sts, "Ibus over current", pca_tf_Ibus },
	/*REG 0x05, STS_B (R)*/
	{ 0x05, 7, 1, 0, batt_miss_sts, "Battery miss status", pca_tf_En_Dis },
	{ 0x05, 6, 1, 0, ocp_fast_sts, "Fast over current status", pca_tf_En_Dis },
	{ 0x05, 5, 1, 0, ocp_avg_sts, "Avarage over current status", pca_tf_En_Dis },
	{ 0x05, 4, 1, 0, active_state_sts, "Charge active status", pca_tf_En_Dis },
	{ 0x05, 3, 1, 0, shutdown_state_sts, "Charge shutdown status", pca_tf_En_Dis },
	{ 0x05, 2, 1, 0, standby_state_sts, "Charge standby status", pca_tf_En_Dis },
	{ 0x05, 1, 1, 0, charge_timer_sts, "Charge timer status", pca_tf_En_Dis },
	{ 0x05, 0, 1, 0, watchdog_timer_sts, "Watchdog timer status", pca_tf_En_Dis },
	/*REG 0x06, STS_C (R)*/
	{ 0x06, 2, 6, 0, iin_sts, "iin status", pca_tf_En_Dis },
	/*REG 0x07, STS_D (R)*/
	{ 0x07, 1, 7, 0, ichg_sts, "ICHG status", pca_tf_En_Dis },
	/*REG 0x08-0x10, STS_ADC_1-9 (R)*/ 
	{ 0x08, 0, 16, 0, adc_iin, "iin ADC", pca_tf_V_adc },
	{ 0x09, 0, 16, 0, adc_iout, "Iout ADC", pca_tf_A_adc },
	{ 0x0A, 0, 16, 0, adc_vin, "Vin ADC", pca_tf_V_adc },
	{ 0x0B, 0, 16, 0, adc_vout, "Vout ADC", pca_tf_V10_adc },
	{ 0x0C, 0, 16, 0, adc_vbat, "Vbat ADC", pca_tf_V_adc },
	{ 0x0D, 0, 16, 0, adc_dietemp, "DieTemp ADC", pca_tf_A_adc },
	{ 0x0E, 0, 16, 0, adc_ntcv, "NTCV ADC", pca_tf_T_adc },
	/*REG 0x20, ICHG_CTRL (R/W)*/
	{ 0x0F, 7, 1, 0, ichg_ss, "Charge current step time", pca_tf_En_Dis },
	{ 0x0F, 0, 7, 0, ichg_cfg, "Charge current set", pca_tf_En_Dis },
	/*REG 0x20, ICHG_CTRL (R/W)*/
	{ 0x10, 7, 1, 0, limit_increment_en, "Input increment enable", pca_tf_En_Dis },
	{ 0x10, 6, 1, 0, iin_ss, "iin step time", pca_tf_En_Dis },
	{ 0x10, 0, 6, 0, iin_cfg, "Charge current set", pca_tf_En_Dis },
	/*REG 0x22, START_CTRL (R/W)*/
	{ 0x11, 7, 1, 0, snsres, "Current sense resistance", pca_tf_En_Dis },
	{ 0x11, 6, 1, 0, en_cfg, "Enable pin polarity", pca_tf_En_Dis },
	{ 0x11, 5, 1, 0, standby_en, "Enable standby mode", pca_tf_En_Dis },
	{ 0x11, 4, 1, 0, rev_iin_det, "Enable reverse current detection", pca_tf_En_Dis },
	{ 0x11, 0, 4, 0, fsw_cfg, "Switching freq select", pca_tf_En_Dis },
	/*REG 0x23, ADC_CTRL (R/W)*/
	{ 0x12, 6, 2, 0, force_adc_mode, "Force ADC mode", pca_tf_En_Dis },
	{ 0x12, 3, 2, 0, hibernate_delay, "Hibernate Delay", pca_tf_En_Dis },
	{ 0x12, 2, 1, 0, adc_offset_cfg, "ADC offset cfg", pca_tf_En_Dis },
	{ 0x12, 1, 1, 0, adc_osr_cfg, "ADC osc select", pca_tf_En_Dis },
	{ 0x12, 0, 1, 0, adc_en, "Enable ADC", pca_tf_En_Dis },
	/*REG 0x24, ADCCH_CFG (R/W)*/
	{ 0x13, 7, 1, 0, ch7_en, "Enable NTC Voltage ADC", pca_tf_En_Dis },
	{ 0x13, 6, 1, 0, ch6_en, "Enable Sys Voltage ADC", pca_tf_En_Dis },
	{ 0x13, 5, 1, 0, ch5_en, "Enable Die Temp ADC", pca_tf_En_Dis },
	{ 0x13, 4, 1, 0, ch4_en, "Enable Charge Current ADC", pca_tf_En_Dis },
	{ 0x13, 3, 1, 0, ch3_en, "Enable Input Current ADC", pca_tf_En_Dis },
	{ 0x13, 2, 1, 0, ch2_en, "Enable Battery Voltage ADC", pca_tf_En_Dis },
	{ 0x13, 1, 1, 0, ch1_en, "Enable Input Voltage ADC", pca_tf_En_Dis },
	/*REG 0x25, TEMP_CTRL (R/W)*/
	{ 0x14, 6, 2, 0, temp_reg, "Die Temp Regulation", pca_tf_En_Dis },
	{ 0x14, 4, 2, 0, temp_delta, "Die Temp Regulation Delta", pca_tf_En_Dis },
	{ 0x14, 3, 1, 0, temp_reg_en, "Enable Die Temp Regulation", pca_tf_En_Dis },
	{ 0x14, 2, 1, 0, ntc_protection_en, "Enable Ext Thermistor Temp Protection", pca_tf_En_Dis },
	{ 0x14, 1, 1, 0, temp_max_en, "Enable Die Temp Standby Mode", pca_tf_En_Dis },
	/*REG 0x26, PWR_COLLAPSE (R/W)*/
	{ 0x15, 6, 2, 0, uv_delta, "VIN UnderVoltage Setting", pca_tf_En_Dis },
	{ 0x15, 5, 1, 0, collapse_det_en, "Enable Power Collapse Detection", pca_tf_En_Dis },
	{ 0x15, 4, 1, 0, iin_force_count, "Enable Force IIN increment", pca_tf_En_Dis },
	{ 0x15, 3, 1, 0, bat_miss_det_en, "Enable Battery Missing Detection", pca_tf_En_Dis },
	{ 0x15, 2, 1, 0, batt_miss_shdn_en, "Enable Battery Missing Shutdown", pca_tf_En_Dis },
	/*REG 0x27, V_FLOAT (R/W)*/
	{ 0x16, 0, 8, 255, v_float, "V Float voltage set", pca_tf_En_Dis },
	/*REG 0x28, SAFETY_CTRL (R/W)*/
	{ 0x17, 7, 1, 0, watchdog_en, "Enable watchdog", pca_tf_En_Dis },
	{ 0x17, 5, 2, 0, watchdog_cfg, "Watchdog timer select", pca_tf_En_Dis },
	{ 0x17, 4, 1, 0, chg_timer_en, "Enable Charger timer", pca_tf_En_Dis },
	{ 0x17, 2, 2, 0, chg_timer_cfg, "Charger timer select", pca_tf_En_Dis },
	{ 0x17, 0, 2, 0, ov_delta, "VIN Overvoltage Set", pca_tf_En_Dis },
	/*REG 0x29-0x2A, NTC_THRESHOLD_1(R/W)*/
	{ 0x18, 0, 16, 0, ntc_threshold, "Ext NTC voltage threshold", pca_tf_En_Dis },
	/* Registers */
	{ 0x00, 0,  8,   0, reg_0, "DEVICE_INFO", pca_tf_byte },
	{ 0x01, 0,  8,   0, reg_1, "INT1", pca_tf_byte },
	{ 0x02, 0,  8,   0, reg_2, "INT1_MSK", pca_tf_byte },
	{ 0x03, 0,  8,   0, reg_3, "INT1_STS", pca_tf_byte },
	{ 0x04, 0,  8,   0, reg_4, "STS_A", pca_tf_byte },
	{ 0x05, 0,  8,   0, reg_5, "STS_B", pca_tf_byte },
	{ 0x06, 0,  8,   0, reg_6, "STS_C", pca_tf_byte },
	{ 0x07, 0,  8,   0, reg_7, "STS_D", pca_tf_byte },
	/*some issue here with ADC reading mapping. need to resolve later YY.*/
	{ 0x08, 0,  8,   0, reg_8, "STS_ADC_1", pca_tf_byte },
	{ 0x09, 0,  8,   0, reg_9, "STS_ADC_2", pca_tf_byte },
	{ 0x0A, 0,  8,   0, reg_a, "STS_ADC_3", pca_tf_byte },
	{ 0x0B, 0,  8,   0, reg_b, "STS_ADC_4", pca_tf_byte },
	{ 0x0C, 0,  8,   0, reg_c, "STS_ADC_5", pca_tf_byte },
	{ 0x0D, 0,  8,   0, reg_d, "STS_ADC_6", pca_tf_byte },
	{ 0x0E, 0,  8,   0, reg_e, "STS_ADC_7", pca_tf_byte },
	{ 0x0E, 0,  8,   0, reg_f, "STS_ADC_8", pca_tf_byte },
	{ 0x0E, 0,  8,   0, reg_10, "STS_ADC_9", pca_tf_byte },
	{ 0x0F, 0,  8,   0, reg_20, "ICHG_CTRL", pca_tf_byte },
	{ 0x10, 8,  8,   0, reg_21, "IIN_CTRL", pca_tf_byte },
	{ 0x11, 0,  8,   0, reg_22, "START_CTRL", pca_tf_byte },
	{ 0x12, 0,  8,   0, reg_23, "ADC_CTRL", pca_tf_byte },
	{ 0x13, 0,  8,   0, reg_20, "ADC_CFG", pca_tf_byte },
	{ 0x14, 8,  8,   0, reg_21, "TEMP_CTRL", pca_tf_byte },
	{ 0x15, 0,  8,   0, reg_22, "PWR_COLLAPSE", pca_tf_byte },
	{ 0x16, 0,  8,   0, reg_23, "V_VFLOAT", pca_tf_byte },
	{ 0x17, 0,  8,   0, reg_22, "SAFETY_CTRL", pca_tf_byte },
	{ 0x18, 0,  8,   0, reg_23, "NTC_TH_1", pca_tf_byte },
	{ 0x18, 0,  8,   0, reg_23, "NTC_TH_2", pca_tf_byte },
};

pca_register_t pca_registers[] = {
	{ true,  PCA9498_AUTO_INC | 0x00,  8, pca_data_bits_default[ 0] },
	{ true,  PCA9498_AUTO_INC | 0x01,  8, pca_data_bits_default[ 1] },
	{ false, PCA9498_AUTO_INC | 0x02,  8, pca_data_bits_default[ 2] },
	{ true,  PCA9498_AUTO_INC | 0x03,  8, pca_data_bits_default[ 3] },
	{ true,  PCA9498_AUTO_INC | 0x04,  8, pca_data_bits_default[4] },
	{ true,  PCA9498_AUTO_INC | 0x05,  8, pca_data_bits_default[5] },
	{ true,  PCA9498_AUTO_INC | 0x06,  8, pca_data_bits_default[6] },
	{ true,  PCA9498_AUTO_INC | 0x07,  8, pca_data_bits_default[7] },
	{ true,  PCA9498_AUTO_INC | 0x08, 16, pca_data_bits_default[8] },
	{ true,  PCA9498_AUTO_INC | 0x09, 16, pca_data_bits_default[9] },
	{ true,  PCA9498_AUTO_INC | 0x0A, 16, pca_data_bits_default[10] },
	{ true,  PCA9498_AUTO_INC | 0x0B, 16, pca_data_bits_default[11] },
	{ true,  PCA9498_AUTO_INC | 0x0D, 16, pca_data_bits_default[12] },
	{ true,  PCA9498_AUTO_INC | 0x0E, 16, pca_data_bits_default[13] },
	{ true,  PCA9498_AUTO_INC | 0x0F, 16, pca_data_bits_default[14] },
	{ false, PCA9498_AUTO_INC | 0x20,  8, pca_data_bits_default[15] },
	{ false, PCA9498_AUTO_INC | 0x21,  8, pca_data_bits_default[16] },
	{ false, PCA9498_AUTO_INC | 0x22,  8, pca_data_bits_default[17] },
	{ false, PCA9498_AUTO_INC | 0x23,  8, pca_data_bits_default[18] },
	{ false, PCA9498_AUTO_INC | 0x24,  8, pca_data_bits_default[19] },
	{ false, PCA9498_AUTO_INC | 0x25,  8, pca_data_bits_default[20] },
	{ false, PCA9498_AUTO_INC | 0x26,  8, pca_data_bits_default[21] },
	{ false, PCA9498_AUTO_INC | 0x27,  8, pca_data_bits_default[22] },
	{ false, PCA9498_AUTO_INC | 0x28,  8, pca_data_bits_default[23] },
	{ false, PCA9498_AUTO_INC | 0x29, 16, pca_data_bits_default[24] },
};

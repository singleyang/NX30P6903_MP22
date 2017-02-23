/*			nx30p6903_def.cpp
*			Created: 2017/02/23
*          Author: Yang Yin
*
*			Contains global variables, helper functions and constants.
*			All together they make up a model of the pca9498's registers and
*			the data fields therein.
*/

#include "nx30p6903_def.h"
#include "nx30p6903_types.h"
#include <stdio.h>

#ifdef _DEBUG
//#define PCA9498_AUTO_INC          0x00
#define PCA9498_AUTO_INC          0x80
#else
#define PCA9498_AUTO_INC          0x80
#define MP22_AUTO_INC			0x00
#endif

pca_data_bits_t pca_data_bits_default[] = {
	/* 00 */ 0x03, 0x00, 0x00, 0x00,
	/* 04 */ 0x00, 0xFE, 0x2C, 0x8F,
	/* 08 */ 0xFF, 0xA0
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
	/*10 datafiled in total*/
	{ 0x00, 0, 3, 0, dev_id, "Device ID", pca_tf_Three_bits },
	{ 0x00, 3, 5, 0, dev_rev, "Device revision", pca_tf_Three_bits },
	{ 0x01, 7, 1, 0, vout_en, "Vout Enable", pca_tf_En_Dis },
	{ 0x01, 6, 1, 0, detc_en, "Idect Enable", pca_tf_En_Dis },
	{ 0x02, 7, 1, 0, pwron_sts, "PowerOn Status", pca_tf_En_Dis },
	{ 0x02, 6, 1, 0, overtag_sts, "OverTag Status", pca_tf_En_Dis },
	{ 0x02, 5, 1, 0, tmrout_sts, "Timeout Status", pca_tf_En_Dis },
	{ 0x02, 4, 1, 0, swon_sts, "SwitchOn Status", pca_tf_En_Dis },
	{ 0x03, 2, 1, 0, ov_flg, "Over Voltage Flag", pca_tf_En_Dis },
	{ 0x03, 1, 1, 0, oc_flg, "Over Current Flag", pca_tf_En_Dis },
	{ 0x03, 0, 1, 0, ot_flg, "Over Temperature Flag", pca_tf_En_Dis },
	{ 0x04, 7, 1, 0, pwron_mask, "PowerOn Int Mask", pca_tf_En_Dis },
	{ 0x04, 6, 1, 0, overtag_mask, "OverTag Int Mask", pca_tf_En_Dis },
	{ 0x04, 5, 1, 0, tmrout_mask, "TimeOut Int Mask", pca_tf_En_Dis },
	{ 0x04, 4, 1, 0, swon_mask, "SwitchOn Int Mask", pca_tf_En_Dis },
	{ 0x04, 2, 1, 0, ov_mask, "Over Voltage Int Mask", pca_tf_En_Dis },
	{ 0x04, 1, 1, 0, oc_mask, "Over Current Int Mask", pca_tf_En_Dis },
	{ 0x04, 0, 1, 0, ot_mask, "Over Temperature Int Mask", pca_tf_En_Dis },
	{ 0x05, 4, 3, 0, ovlo_rng, "OVLO Fine Tune", pca_tf_Vbus_OVP },
	{ 0x05, 3, 1, 0, ovlo_sel, "OVLO Adj Selection", pca_tf_regulation },
	{ 0x05, 0, 2, 0, ovlo_ov, "OVLO Threshold", pca_tf_regulation },
	{ 0x06, 0, 4, 0, isrc_val , "Isource Current", pca_tf_regulation },
	{ 0x07, 4, 4, 0, isrc_det, "Isource Pulse Width", pca_tf_regulation },
	{ 0x07, 0, 4, 0, vin_duty, "Vin Duty Cycle", pca_tf_temperature },
	{ 0x08, 0, 8, 0, adc_vin, "Vin Voltage", pca_tf_temperature },
	{ 0x09, 0, 8, 0, tag_vin, "Vin Tag", pca_tf_no_yes },
	/* Registers 10 registers in total */
	{ 0x00, 0, 8, 0, reg_0, "DEVICE_INFO", pca_tf_byte },
	{ 0x01, 0, 8, 0, reg_1, "ENABLE REG", pca_tf_byte },
	{ 0x02, 0, 8, 0, reg_2, "STATUS REG", pca_tf_byte },
	{ 0x03, 0, 8, 0, reg_3, "FLAG", pca_tf_byte },
	{ 0x04, 0, 8, 0, reg_4, "INT MASK", pca_tf_byte },
	{ 0x05, 0, 8, 0, reg_5, "OVLO LEVEL", pca_tf_byte },
	{ 0x06, 0, 8, 0, reg_6, "ISRC TO VIN", pca_tf_byte },
	{ 0x07, 0, 8, 0, reg_7, "ISRC WORKING TIME", pca_tf_byte },
	{ 0x08, 0, 8, 0, reg_8, "VOLTAGE TO VIN", pca_tf_byte },
	{ 0x09, 0, 8, 0, reg_9, "SET TAG ON VIN", pca_tf_byte },
};

pca_register_t pca_registers[] = {
	{ true,  MP22_AUTO_INC | 0x00, 8, pca_data_bits_default[0] },
	{ false, MP22_AUTO_INC | 0x01, 8, pca_data_bits_default[1] },
	{ true,  MP22_AUTO_INC | 0x02, 8, pca_data_bits_default[2] },
	{ true,  MP22_AUTO_INC | 0x03, 8, pca_data_bits_default[3] },
	{ false, MP22_AUTO_INC | 0x04, 8, pca_data_bits_default[4] },
	{ false, MP22_AUTO_INC | 0x05, 8, pca_data_bits_default[5] },
	{ false, MP22_AUTO_INC | 0x06, 8, pca_data_bits_default[6] },
	{ false, MP22_AUTO_INC | 0x07, 8, pca_data_bits_default[7] },
	{ true,  MP22_AUTO_INC | 0x08, 8, pca_data_bits_default[8] },
	{ false, MP22_AUTO_INC | 0x09, 8, pca_data_bits_default[9] }
};

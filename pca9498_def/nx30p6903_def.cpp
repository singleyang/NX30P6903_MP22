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

pca_data_bits_t pca_data_bits_default[] = {
	/* 00 */ 0x00, 0x00, 0x00, 0x00,
	/* 04 */ 0xF7, 0x30, 0x00, 0x00,
	/* 08 */ 0x00, 0xFF, 0x00, 0x00,
	/* 0C */ 0x00, 0x00, 0x00, 0x02
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

/*Enable/Disable check box*/
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

/*ovlo rng cmb*/
void pca_tf_ovlo_rng(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			switch (index){
				case 0:
					sprintf_s(textbuffer, sz, "%s", "-600mV");
					break;
				case 1:
					sprintf_s(textbuffer, sz, "%s", "-400mV");
					break;
				case 2:
					sprintf_s(textbuffer, sz, "%s", "-200mV");
					break;
				case 3:
					sprintf_s(textbuffer, sz, "%s", "0mV");
					break;
				case 4:
					sprintf_s(textbuffer, sz, "%s", "200mV");
					break;
				case 5:
					sprintf_s(textbuffer, sz, "%s", "400mV");
					break;
				case 6:
					sprintf_s(textbuffer, sz, "%s", "600mV");
					break;
				case 7:
					sprintf_s(textbuffer, sz, "%s", "800mV");
					break;
				default:
					break;
			}
		}
	}
}

/*ovlo ov cmb*/
void pca_tf_ovlo_thres(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 8) {
			switch (index){
			case 0:
				sprintf_s(textbuffer, sz, "%s", "6.8V");
				break;
			case 1:
				sprintf_s(textbuffer, sz, "%s", "11.5V");
				break;
			case 2:
				sprintf_s(textbuffer, sz, "%s", "17V");
				break;
			case 3:
				sprintf_s(textbuffer, sz, "%s", "23V");
				break;
			default:
				break;
			}
		}
	}
}

/*ovlo sel cmb*/
void pca_tf_ovlo_sel(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 25) {
			if (index == 0)
				sprintf_s(textbuffer, sz, "%s", "OVLO set by ADJ pin");
			else
				sprintf_s(textbuffer, sz, "%s", "OVLO set by I2C reg");
		}
	}
}

/*isrc value cmb*/
void pca_tf_isrc_val(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			switch (index){
				case 0:sprintf_s(textbuffer, sz, "%s", "0uA"); break;
				case 1:sprintf_s(textbuffer, sz, "%s", "1uA"); break;
				case 2:sprintf_s(textbuffer, sz, "%s", "2uA"); break;
				case 3:sprintf_s(textbuffer, sz, "%s", "3uA"); break;
				case 4:sprintf_s(textbuffer, sz, "%s", "4uA"); break;
				case 5:sprintf_s(textbuffer, sz, "%s", "5uA"); break;
				case 6:sprintf_s(textbuffer, sz, "%s", "10uA"); break;
				case 7:sprintf_s(textbuffer, sz, "%s", "20uA"); break;
				case 8:sprintf_s(textbuffer, sz, "%s", "50uA"); break;
				case 9:sprintf_s(textbuffer, sz, "%s", "100uA"); break;
				case 10:sprintf_s(textbuffer, sz, "%s", "200uA"); break;
				case 11:sprintf_s(textbuffer, sz, "%s", "500uA"); break;
				case 12:sprintf_s(textbuffer, sz, "%s", "1000uA"); break;
				case 13:sprintf_s(textbuffer, sz, "%s", "2000uA"); break;
				case 14:sprintf_s(textbuffer, sz, "%s", "5000uA"); break;
				case 15:sprintf_s(textbuffer, sz, "%s", "10000uA"); break;
				default: break;
			}
		}
	}
}

/*isrc value cmb*/
void pca_tf_isrc_tdet(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 12) {
			switch (index){
				case 0:sprintf_s(textbuffer, sz, "%s", "200us"); break;
				case 1:sprintf_s(textbuffer, sz, "%s", "400us"); break;
				case 2:sprintf_s(textbuffer, sz, "%s", "1000us"); break;
				case 3:sprintf_s(textbuffer, sz, "%s", "2000us"); break;
				case 4:sprintf_s(textbuffer, sz, "%s", "4000us"); break;
				case 5:sprintf_s(textbuffer, sz, "%s", "10ms"); break;
				case 6:sprintf_s(textbuffer, sz, "%s", "20ms"); break;
				case 7:sprintf_s(textbuffer, sz, "%s", "40ms"); break;
				case 8:sprintf_s(textbuffer, sz, "%s", "100ms"); break;
				case 9:sprintf_s(textbuffer, sz, "%s", "200ms"); break;
				case 10:sprintf_s(textbuffer, sz, "%s", "400ms"); break;
				case 11:sprintf_s(textbuffer, sz, "%s", "1000ms"); break;
				case 12:sprintf_s(textbuffer, sz, "%s", "2000ms"); break;
				case 13:sprintf_s(textbuffer, sz, "%s", "4000ms"); break;
				case 14:sprintf_s(textbuffer, sz, "%s", "10s"); break;
				case 15:sprintf_s(textbuffer, sz, "%s", "Always On"); break;
				default: break;
			}
		}
	}
}

/*duty cmb*/
void pca_tf_duty(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 12) {
			switch (index){
			case 0:sprintf_s(textbuffer, sz, "%s", "Single Pulse"); break;
			case 1:sprintf_s(textbuffer, sz, "%s", "10ms"); break;
			case 2:sprintf_s(textbuffer, sz, "%s", "20ms"); break;
			case 3:sprintf_s(textbuffer, sz, "%s", "50ms"); break;
			case 4:sprintf_s(textbuffer, sz, "%s", "100ms"); break;
			case 5:sprintf_s(textbuffer, sz, "%s", "200ms"); break;
			case 6:sprintf_s(textbuffer, sz, "%s", "500ms"); break;
			case 7:sprintf_s(textbuffer, sz, "%s", "1000ms"); break;
			case 8:sprintf_s(textbuffer, sz, "%s", "2000ms"); break;
			case 9:sprintf_s(textbuffer, sz, "%s", "3000ms"); break;
			case 10:sprintf_s(textbuffer, sz, "%s", "6000ms"); break;
			case 11:sprintf_s(textbuffer, sz, "%s", "12000ms"); break;
			case 12:sprintf_s(textbuffer, sz, "%s", "30000ms"); break;
			case 13:sprintf_s(textbuffer, sz, "%s", "60000ms"); break;
			case 14:sprintf_s(textbuffer, sz, "%s", "12s"); break;
			case 15:sprintf_s(textbuffer, sz, "%s", "30s"); break;
			default: break;
			}
		}
	}
}


/*additional ovp cmb*/
void pca_tf_adt_ovp(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 18) {
			switch (index){
			case 0:sprintf_s(textbuffer, sz, "%s", "OVP Set by OVLO"); break;
			case 1:sprintf_s(textbuffer, sz, "%s", "OVP Set by OVLO"); break;
			case 2:sprintf_s(textbuffer, sz, "%s", "10V"); break;
			case 3:sprintf_s(textbuffer, sz, "%s", "14V"); break;
			default: break;
			}
		}
	}
}

/*slew rate tune cmb*/
void pca_tf_sr_tune(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 6) {
			switch (index){
			case 0:sprintf_s(textbuffer, sz, "%s", "0.5ms"); break;
			case 1:sprintf_s(textbuffer, sz, "%s", "1ms"); break;
			case 2:sprintf_s(textbuffer, sz, "%s", "1.5ms"); break;
			case 3:sprintf_s(textbuffer, sz, "%s", "2ms"); break;
			case 4:sprintf_s(textbuffer, sz, "%s", "2.5ms"); break;
			case 5:sprintf_s(textbuffer, sz, "%s", "3ms"); break;
			case 6:sprintf_s(textbuffer, sz, "%s", "3.5ms"); break;
			case 7:sprintf_s(textbuffer, sz, "%s", "4ms"); break;
			default: break;
			}
		}
	}
}

/*Vin Tag trackbar*/
void pca_tf_tag_vin(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			float val = index & 0xFF;
			if (index <= 0xff)
				/*range from 0 - 2.5V with 10mV per step*/
				sprintf_s(textbuffer, sz, "%0.2fV", (val * 0.01));
		}
	}
}

/*ADC Voltage text*/
void pca_tf_vin_adc(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 10) {
			float val = (index & 0xFF);
			sprintf_s(textbuffer, sz, "%0.2fV", val*0.01);
		}
	}
}

/*Change Vout En lbl*/
void pca_tf_Vout_En_Dis(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 15) {
			if (index == 0)
			sprintf_s(textbuffer, sz, "%s", "Vout Enabled");
			else
			sprintf_s(textbuffer, sz, "%s", "Vout Disabled");
		}
	}
}
/*Change Idect En lbl*/
void pca_tf_Idect_En_Dis(char *textbuffer, size_t sz, int index)
{
	if (textbuffer && sz > 0) {
		*textbuffer = '\0';
		if (sz >= 15) {
			if (index == 0)
				sprintf_s(textbuffer, sz, "%s", "Idect Disabled");
			else
				sprintf_s(textbuffer, sz, "%s", "Idect Enabled");
		}
	}
}

pca_data_field_t pca_DataFields[] = {
	/*10 datafiled in total*/
	{ 0x00, 0, 4, 0, dev_id, "Device ID", pca_tf_Three_bits },
	{ 0x00, 4, 4, 0, dev_rev, "Device revision", pca_tf_Three_bits },
	{ 0x01, 7, 1, 0, vout_en, "Vout Disabled", pca_tf_Vout_En_Dis },
	{ 0x01, 6, 1, 0, detc_en, "Idect Disabled", pca_tf_Idect_En_Dis },
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
	{ 0x05, 4, 3, 0, ovlo_rng, "OVLO Fine Tune", pca_tf_ovlo_rng },
	{ 0x05, 3, 1, 0, ovlo_sel, "OVLO Adj Selection", pca_tf_ovlo_sel },
	{ 0x05, 0, 2, 0, ovlo_ov, "OVLO Threshold", pca_tf_ovlo_thres },
	{ 0x06, 0, 4, 0, isrc_val, "Isource Current", pca_tf_isrc_val },
	{ 0x07, 4, 4, 0, isrc_det, "Isource Pulse Width", pca_tf_isrc_tdet },
	{ 0x07, 0, 4, 0, vin_duty, "Vin Duty Cycle", pca_tf_duty },
	{ 0x08, 0, 8, 0, adc_vin, "Vin Voltage", pca_tf_vin_adc },
	{ 0x09, 0, 8, 0, tag_vin, "Vin Tag", pca_tf_tag_vin },
	{ 0x0e, 0, 2, 0, adt_ovp, "Additional OVP", pca_tf_adt_ovp},
	{ 0x0f, 0, 3, 0, sr_tune, "Slew Rate Tuning", pca_tf_sr_tune},
	/* Registers 10 registers in total */
	{ 0x00, 0, 8, 0, reg_0, "DEVICE INFO", pca_tf_byte },
	{ 0x01, 0, 8, 0, reg_1, "ENABLE REG", pca_tf_byte },
	{ 0x02, 0, 8, 0, reg_2, "STATUS REG", pca_tf_byte },
	{ 0x03, 0, 8, 0, reg_3, "FLAG", pca_tf_byte },
	{ 0x04, 0, 8, 0, reg_4, "INT MASK", pca_tf_byte },
	{ 0x05, 0, 8, 0, reg_5, "OVLO LEVEL", pca_tf_byte },
	{ 0x06, 0, 8, 0, reg_6, "ISRC TO VIN", pca_tf_byte },
	{ 0x07, 0, 8, 0, reg_7, "ISRC WORKING TIME", pca_tf_byte },
	{ 0x08, 0, 8, 0, reg_8, "VOLTAGE TO VIN", pca_tf_byte },
	{ 0x09, 0, 8, 0, reg_9, "SET TAG ON VIN", pca_tf_byte },
	{ 0x0A, 0, 8, 0, reg_9, "RESERVED", pca_tf_byte },
	{ 0x0B, 0, 8, 0, reg_9, "RESERVED", pca_tf_byte },
	{ 0x0C, 0, 8, 0, reg_9, "RESERVED", pca_tf_byte },
	{ 0x0D, 0, 8, 0, reg_9, "RESERVED", pca_tf_byte },
	{ 0x0E, 0, 8, 0, reg_9, "ADDITIONAL OVP", pca_tf_byte },
	{ 0x0F, 0, 8, 0, reg_9, "SLEW RATE TUNE", pca_tf_byte }
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
	{ false, MP22_AUTO_INC | 0x09, 8, pca_data_bits_default[9] },
	{ true,  MP22_AUTO_INC | 0x0A, 8, pca_data_bits_default[10] },
	{ true,  MP22_AUTO_INC | 0x0B, 8, pca_data_bits_default[11] },
	{ true,  MP22_AUTO_INC | 0x0C, 8, pca_data_bits_default[12] },
	{ true,  MP22_AUTO_INC | 0x0D, 8, pca_data_bits_default[13] },
	{ false, MP22_AUTO_INC | 0x0E, 8, pca_data_bits_default[14] },
	{ false, MP22_AUTO_INC | 0x0F, 8, pca_data_bits_default[15] }
};

#ifndef _PCA9498_TYPES_H_
#define _PCA9498_TYPES_H_

/*			pca9498_types.h
 *			Created: 2016/07/31
 *          Author: Erik Lam
 *        
 *			This header defines types exposed to the outside world 
 */

/* Result codes */
typedef enum {
	pr_ok,
	pr_badparam,
	pr_ioerror,
	pr_disconnect,
	pr_connect,
	pr_noconnection
} pca_notify_t;

/* Enumeration for all data fields */
typedef enum data_fields_enum {
	dev_id,
	dev_rev,
	vbus_ovp_mask,
	ibus_reg_mask,
	vbat_reg_mask,
	ibat_reg_mask,
	vout_reg_mask,
	vbus_otp_mask,
	tbat_otp_mask,
	ibus_rev_mask,
	wd_mask,
	adc_done_mask,
	vdrop_alm_mask,
	vdrop_ovp_mask,
	vbus_ins_mask,
	bat_ins_mask,
	tshut_mask,
	ioc_mask,
	vbus_ovp_flt,
	ibus_reg_ldo,
	vbat_reg_ldo, 
	ibat_reg_ldo,
	vout_reg_ldo,
	tbus_otp_flt,
	tbat_otp_flt,
	ibus_irev_flt,
	wd_flt,
	adc_done,
	vdrop_alm_flt,
	vdrop_ovp_flt,
	vbus_ins,
	bat_ins,
	tshut_flt,
	ioc_flt,
	vbus_ovp_en,
	ibus_reg_en,
	vbat_reg_en,
	ibat_reg_en,
	vout_reg_en,
	tbus_otp_en, 
	tbat_otp_en,
	vbus_pd_en,
	vdrop_ovp_en, 
	vdrop_alm_en,
	sense_r,
	chg_en,
	watchdog,
	irev_set,
	reg_rst,
	tdie_adc_en,
	adc_en,
	adc_rate,
	adc_avg_en,
	adc_samples,
	vbus_adc_en,
	ibus_adc_en,	
	vout_adc_en,
	vdrop_adc_en,
	vbat_adc_en,
	ibat_adc_en,
	tbus_adc_en,	
	tbat_adc_en,
	ibus_ocp,
	ocp_res,
	vbus_ovp_dly,
	vbus_ovp,	
	vout_reg,
	vdrop_ovp,
	vdrop_alm,
	vbat_reg,
	ibat_reg,
	ibus_reg,
	tbus_reg,
	tbat_otp,
	vbus_adc,
	ibus_adc,
	vout_adc,
	vdrop_adc,
	vbat_adc,
	ibat_adc,
	tbus_adc,
	tbat_adc,
	die_temp,
	/* registers */
	reg_0,
	reg_1,
	reg_2,
	reg_3,
	reg_4,
	reg_5,
	reg_6,
	reg_7,
	reg_8,
	reg_9,
	reg_a,
	reg_b,
	reg_c,
	reg_d,
	reg_e,
	reg_f,
	reg_10,
	reg_11,
	reg_12,
	reg_13,
	reg_14,
	reg_15,
	reg_16,
	reg_17,
	reg_18,
	reg_19,
	reg_1a,
	reg_1b,
	reg_1c,
	reg_1d,
	reg_1e,
	reg_1f,
	reg_20,
	reg_21,
	reg_22,
	reg_23,
	number_of_dataFields
} pca_data_fields_enum_t;

typedef void(*pca_notify_function_t)(pca_data_fields_enum_t updatedField, pca_notify_t result);

#endif //_PCA9498_TYPES_H_
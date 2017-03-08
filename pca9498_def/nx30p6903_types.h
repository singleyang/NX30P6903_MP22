#ifndef _NX30P6903_TYPES_H_
#define _NX30P6903_TYPES_H_

/*			nx30p6903_types.h
*			Created: 2017/02/23
*          Author: Yang Yin
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
	vout_en,
	detc_en,
	pwron_sts,
	overtag_sts,
	tmrout_sts,
	swon_sts,
	ov_flg,
	oc_flg,
	ot_flg,
	pwron_mask,
	overtag_mask,
	tmrout_mask,
	swon_mask,
	ov_mask,
	oc_mask,
	ot_mask,
	ovlo_rng,
	ovlo_sel,
	ovlo_ov,
	isrc_val,
	isrc_det,
	vin_duty,
	adc_vin,
	tag_vin,
	adt_ovp,
	sr_tune,
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
	number_of_dataFields
} pca_data_fields_enum_t;

typedef void(*pca_notify_function_t)(pca_data_fields_enum_t updatedField, pca_notify_t result);

#endif //_NX30P6903_TYPES_H_
#ifndef _NX30P6903_DEF_H_
#define _NX30P6903_DEF_H_

/*			nx30p6903_def.h
*			Created: 2017/02/23
*          Author: Yang Yin
*
*			This header defines internal structures. I.e. structures not exposed to the outside world
*/

#include "nx30p6903_types.h"
#include <stdint.h>

typedef void(*pca_value_text_func_t)(char *textbuffer, size_t sz, int index);

#define PCA9498_REG_COUNT	0x1C			/* 2 * 8 bit registers are combined into 1 * 16 bit regsister */

typedef uint32_t pca_data_bits_t;

/* Definition of a register */
typedef struct pca_datafield {
	uint8_t regnum;							/* Register offset in memory register map */
	uint8_t ls_bit;							/* bit weight of least significant bit */
	uint8_t bit_count;						/* the number of bits this data field is comprised of */
	uint16_t value_count;					/* The maximum number of allowed values. Zero if the full range is used. */
	pca_data_fields_enum_t field_index;		/* enum for binary reference */
	const char *caption;					/* Text for labeling in user application */
	pca_value_text_func_t value_text_func;	/* Function that supplies texts, one for each value */
} pca_data_field_t;

/* Definition of a register. */
typedef struct pca_register {
	bool readonly;
	uint8_t offset;                         /* Register offset in device */
	uint8_t bitSz;                          /* The size of the register in bits */
	pca_data_bits_t data_bits;              /* The register's contents */
} pca_register_t;


#endif  //_NX30P6903_DEF_H_
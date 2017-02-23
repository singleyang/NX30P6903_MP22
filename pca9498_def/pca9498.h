#ifndef _PCA9498_H_
#define _PCA9498_H_

/*			pca9498.h
 *			Created: 2016/07/31
 *          Author: Erik Lam
 *        
 *			This header defines the application interface t0 PCA9498 registers.
 */

#include "pca9498_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum pca_result
{
	pca_ok,
	pca_invalidIF,
	pca_IFnotPresent,
	pca_IFbusy,
	pca_nosuchfunction,
	pca_cantopenIF,
	pca_badParam,
	pca_readFailed,
	pca_writeFailed,
	pca_timedout,
	pca_dataTooLarge,
	pca_unknown,
} pca_result_t;	

/* ==================================================================
 *
 * Routines that retrieve data from the model 
 *
 * ==================================================================*/

/* Returns the caption text of a data field, or NULL if none exists. */ 
pca_result_t pcaGetCaption(pca_data_fields_enum_t dataField, char *textbuffer, size_t sz);

/* Returns the number of values the data field is comprised of. */ 
int pcaGetValueCount(pca_data_fields_enum_t dataField);

/* Returns the text for a specific value for specified data field */
int pcaGetValueText(pca_data_fields_enum_t dataField, int Index, char *textbuffer, size_t sz);

/* Returns the current value for a specific data field */ 
int pcaGetCurrentValue(pca_data_fields_enum_t dataField);

/* Returns the text for the current value of  specific data field */
int pcaGetCurrentText(pca_data_fields_enum_t dataField, char *textbuffer, size_t sz);

///* Find the value for the supplied text */
//int pcaGetValueForText(pca_data_fields_enum_t dataField, const char *txt);

/* Returns the value for a specific register */
int pcaGetRegisterValue(int regnumber);

/* Returns zero if the register is writable */
int pcaIsRegisterReadOnly(int regnumber);

/* Returns zero if the datafield is writable */
int pcaIsDataFieldReadOnly(pca_data_fields_enum_t dataField);

/* ==================================================================
 *
 * Routines that deal with updating the model from hardware
 *
 * ==================================================================*/

/* Register a call-back function to receive notofications of changes in the model */
void pcaRegisterNotification(pca_notify_function_t callback);

/* Unregister a call-back function, to stop receiving notifications */
void pcaUnregisterNotification(pca_notify_function_t callback);

/* Reads the register where <dataField> is defined in. For each change in data fields, all call-back's will be called. */
pca_result_t pcaReadDataField(pca_data_fields_enum_t dataField);

/* Reads a register. For each change in data fields, all call-back's will be called. */
pca_result_t pcaReadRegister(int regnum);

/* Reads <count> registers starting at <regNumber>'s offset */
pca_result_t pcaReadRegisters(int regNumber, int count);

/* Reads all registers. For each change in data fields, all call-back's will be called. */
pca_result_t pcaReadAll();
 
/* ==================================================================
 *
 * Routines that deal with updating the model from the application
 *
 * ==================================================================*/

pca_result_t pcaSetDataField(pca_data_fields_enum_t dataField, int value);
void pcaSetRegister(int regNumber, int value);

/* ==================================================================
 *
 * Routines that deal with updating the hardware from the model
 *
 * ==================================================================*/

pca_result_t pcaWriteDataField(pca_data_fields_enum_t dataField);
pca_result_t pcaWriteRegister(int regNumber);
pca_result_t pcaWriteAll();
pca_result_t pcaSetAndWriteDataField(pca_data_fields_enum_t dataField, int value);
pca_result_t pcaSetAndWriteRegister(int regNumber, int value);

// Set the device's I2C slave address
void pcaSlaveAddress(int sla);

#ifdef __cplusplus
}
#endif

#endif //_PCA9498_H_
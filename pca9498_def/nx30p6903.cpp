#include "nx30p6903.h"
#include "nx30p6903_def.h"
#include <stdlib.h>
#include <vector>
#include "../pca9498_com/pca9498_com.h"

/* ==================================================================
*
* Global variables
*
* ==================================================================*/

std::vector<pca_notify_function_t> gCallbacks;
extern pca_data_field_t pca_DataFields[];
extern pca_register_t pca_registers[];
uint8_t gSla = 0x65;
/* ==================================================================
*
* Local functions and macro's
*
* ==================================================================*/

#define DATAFIELD(d) pca_DataFields[d]
#define VALUECOUNT(d) (2 << (DATAFIELD(d).bit_count-1))
#define MASK(d) ((VALUECOUNT(d)-1)<<DATAFIELD(d).ls_bit)

bool pcaCallbackExists(pca_notify_function_t callback, int *iterator = NULL) {
	unsigned int idx;
	for (idx = 0; idx < gCallbacks.size(); idx++) {
		if (gCallbacks[idx] == callback) {
			if (iterator) *iterator = idx;
			return true;
		}
	}
	return false;
}

void Notify(pca_data_fields_enum_t field, pca_notify_t result) {
	unsigned int idx;
	size_t cnt = gCallbacks.size();
	for (idx = 0; idx < cnt; idx++) {
		gCallbacks[idx](field, result);
	}
}

uint16_t _pcaSetRegister(int regNumber, int value) {
	uint16_t delta = 0;
	if (regNumber >= 0 && regNumber < PCA9498_REG_COUNT) {
		uint16_t oldvalue = pca_registers[regNumber].data_bits;
		pca_registers[regNumber].data_bits = value & 0xFFFF;
		delta = oldvalue ^ pca_registers[regNumber].data_bits;
		if (delta != 0) {
			// some bit(s) changed. Notify the caller which data fields have changed
			unsigned int idx = 0;
			//for (idx = 0; idx < number_of_dataFields; idx++) {
			//	if (pca_DataFields[idx].regnum == regNumber) break;
			//}
			for (; idx < number_of_dataFields; idx++) {
				if (pca_DataFields[idx].regnum != regNumber) continue;
				if ((MASK(idx) & delta) != 0) {
					Notify(static_cast<pca_data_fields_enum_t>(idx), pr_ok);
					//break;
				}
			}
		}
	}
	return delta;
}

uint16_t _pcaSetRegisterSwapped(int regNumber, int value) {
	int swapped;
	int bytecount = pca_registers[regNumber].bitSz / 8;
	if (bytecount == 1) {
		swapped = value;
	}
	if (bytecount == 2) {
		swapped = ((value & 0x00FF) << 8) + ((value & 0xFF00) >> 8);
	}
	if (bytecount == 3) {
		swapped = ((value & 0x0000FF) << 16) + ((value & 0x00FF00) >> 0) + ((value & 0xFF0000) >> 16);
	}
	if (bytecount == 4) {
		swapped = ((value & 0x000000FF) << 24) + ((value & 0x0000FF00) << 8) + ((value & 0x00FF0000) >> 8) + ((value & 0xFF000000) >> 24);
	}
	return _pcaSetRegister(regNumber, swapped);
}

/* ==================================================================
*
* Exported functions
*
* ==================================================================*/

pca_result_t pcaGetCaption(pca_data_fields_enum_t dataField, char *textbuffer, size_t sz)
{
	if (dataField >= 0 && dataField < number_of_dataFields) {
		strcpy_s(textbuffer, sz, DATAFIELD(dataField).caption);
		return pca_ok;
	}
	return pca_badParam;
}

int pcaGetValueCount(pca_data_fields_enum_t dataField) {
	if (dataField < 0 || dataField >= number_of_dataFields) return -1;
	if (DATAFIELD(dataField).value_count != 0) return DATAFIELD(dataField).value_count;
	return VALUECOUNT(dataField);
}

int pcaGetValueText(pca_data_fields_enum_t dataField, int Index, char *textbuffer, size_t sz) {
	if (dataField < 0 || dataField >= number_of_dataFields) return 0;
	if (Index < 0 || Index >= VALUECOUNT(dataField)) return 0;
	if (DATAFIELD(dataField).value_text_func != NULL)
		DATAFIELD(dataField).value_text_func(textbuffer, sz, Index);
	return 1;
}

int pcaGetCurrentValue(pca_data_fields_enum_t dataField) {
	if (dataField < 0 || dataField >= number_of_dataFields) return NULL;
	pca_data_field_t *datafld = &DATAFIELD(dataField);
	pca_data_bits_t data = pca_registers[datafld->regnum].data_bits;
	return (data >> datafld->ls_bit) & ((1 << (datafld->bit_count - 0)) - 1);
}

int pcaGetCurrentText(pca_data_fields_enum_t dataField, char *textbuffer, size_t sz) {
	int currentValue = pcaGetCurrentValue(dataField);
	if (currentValue >= 0)
	if (DATAFIELD(dataField).value_text_func != NULL)
		DATAFIELD(dataField).value_text_func(textbuffer, sz, currentValue);
	return currentValue >= 0;
}

//int pcaGetValueForText(pca_data_fields_enum_t dataField, const char *txt) {
//	// No way to predict the value. Can't use a binary search either. 
//
//
//}

uint8_t _pcaGetRegVal8(int regNumber) {
	// Notice PCA9498 has only 8 bit writable registers
	return (uint8_t)pcaGetRegisterValue(regNumber) & 0xFF;
}

int pcaGetRegisterValue(int regnumber)
{
	if (regnumber >= 0 && regnumber < PCA9498_REG_COUNT)
		return pca_registers[regnumber].data_bits;
	return -1;
}

/* Returns zero if the register is writable */
int pcaIsRegisterReadOnly(int regnumber)
{
	if (regnumber >= 0 && regnumber < PCA9498_REG_COUNT)
		return pca_registers[regnumber].readonly;
	return true;
}

/* Returns zero if the datafield is writable */
int pcaIsDataFieldReadOnly(pca_data_fields_enum_t dataField)
{
	return pcaIsRegisterReadOnly(pca_DataFields[dataField].regnum);
}

void pcaRegisterNotification(pca_notify_function_t callback) {
	if (!pcaCallbackExists(callback)) {
		gCallbacks.push_back(callback);
	}
}

void pcaUnregisterNotification(pca_notify_function_t callback) {
	int iterator;
	if (pcaCallbackExists(callback, &iterator))
		gCallbacks.erase(gCallbacks.begin() + iterator);
}

pca_result_t pcaReadDataField(pca_data_fields_enum_t dataField) {
	if (dataField >= 0 && dataField < number_of_dataFields) {
		return pcaReadRegister(DATAFIELD(dataField).regnum);
	}
	else Notify(dataField, pr_badparam);
	return pca_badParam;
}

pca_result_t pcaReadRegister(int regNumber) {
	uint16_t data;
	pca_result_t result;
	if (regNumber < 0 || regNumber >= PCA9498_REG_COUNT) return pca_badParam;
	if ((result = (pca_result_t)pc_readRegister(gSla,
		pca_registers[regNumber].offset,
		(uint8_t *)&data,
		pca_registers[regNumber].bitSz / 8)
		) == pca_ok)
	{
		_pcaSetRegisterSwapped(regNumber, data);
	}
	return result;
}

pca_result_t pcaReadRegisters(int regNumber, int count) {
	//pca_result_t result = pca_ok;
	//int idx;
	//for (idx = 0; result == pca_ok && idx < PCA9498_REG_COUNT; idx++) {
	//	result = pcaReadRegister(idx);
	//}
	//return result;
	pca_result_t result = pca_ok;
	int idx;
	int bytecount = 0;
	for (idx = regNumber; idx < regNumber + count; idx++) {
		bytecount += pca_registers[idx].bitSz / 8;
	}
	uint8_t data[0xFF];
	if ((result = (pca_result_t)pc_readRegister(gSla, 0x80 | pca_registers[regNumber].offset, (uint8_t *)&data, bytecount)) == pca_ok)
	{
		bytecount = 0;
		for (idx = regNumber; idx < regNumber + count; idx++) {
			_pcaSetRegisterSwapped(idx, *((int *)&data[bytecount]));
			bytecount += pca_registers[idx].bitSz / 8;
		}

	}
	return result;
}


pca_result_t pcaReadAll() {
	return pcaReadRegisters(0, PCA9498_REG_COUNT);
	////pca_result_t result = pca_ok;
	////int idx;
	////for (idx = 0; result == pca_ok && idx < PCA9498_REG_COUNT; idx++) {
	////	result = pcaReadRegister(idx);
	////}
	////return result;
	//pca_result_t result = pca_ok;
	//int idx;
	//int bytecount = 0;
	//for (idx = 0; idx < PCA9498_REG_COUNT; idx++) {
	//	bytecount += pca_registers[idx].bitSz / 8;
	//}
	//uint8_t data[0xFF];
	//if ((result = (pca_result_t)pc_readRegister(gSla, 0x80, (uint8_t *) &data, bytecount)) == pca_ok)
	//{
	//	bytecount = 0;
	//	for (idx = 0; idx < PCA9498_REG_COUNT; idx++) {
	//		_pcaSetRegisterSwapped(idx, *((int *)&data[bytecount]));
	//		bytecount += pca_registers[idx].bitSz / 8;
	//	}
	//	
	//}
	//return result;
}

pca_result_t pcaSetRegisterAndWrite(int regNumber, int value) {
	if (_pcaSetRegister(regNumber, value) != 0)
		return pcaWriteRegister(regNumber);
	return pca_ok;
}

pca_result_t pcaSetDataField(pca_data_fields_enum_t dataField, int value) {
	uint16_t newvalue;
	int regnumber;
	if (dataField >= 0 && dataField < number_of_dataFields) {
		regnumber = DATAFIELD(dataField).regnum;
		newvalue = pcaGetRegisterValue(regnumber) & ~MASK(dataField);
		newvalue |= ((value << DATAFIELD(dataField).ls_bit) & MASK(dataField));
		//return pcaSetRegisterAndWrite(regnumber, newvalue);
		pcaSetRegister(regnumber, newvalue);
		return pca_ok;
	}
	return pca_badParam;
}

void pcaSetRegister(int regNumber, int value) {
	_pcaSetRegister(regNumber, value);
}

pca_result_t pcaWriteDataField(pca_data_fields_enum_t dataField) {
	if (dataField >= 0 && dataField < number_of_dataFields)
		return pcaWriteRegister(DATAFIELD(dataField).regnum);
	return pca_badParam;
}

pca_result_t pcaWriteRegister(int regNumber) {
	pca_result_t result = pca_ok;
	// ...
	if (result == pca_ok)
		result = (pca_result_t)pc_writeRegister(gSla,
		pca_registers[regNumber].offset,
		(uint8_t *)&pca_registers[regNumber].data_bits,
		1);
	return result;
}

pca_result_t pcaWriteAll() {
	//pca_result_t result = pca_ok;
	//unsigned int idx;
	//for (idx = 0; result == pca_ok && idx < PCA9498_REG_COUNT; idx++) {
	//	result = pcaWriteRegister(idx);
	//}
	//return result;
	pca_result_t result = pca_ok;
	unsigned int idx, offset;
	uint8_t data[0xFF];
	offset = 0;
	for (idx = 1; idx < 3; idx++) {
		data[offset++] = (pca_registers[idx].data_bits & 0xFF);
	}
	result = pc_writeRegister(gSla, 0x81, data, 2) == pc_ok ? pca_ok : pca_writeFailed;
	if (result == pca_ok) {
		offset = 0;
		for (idx = 5; idx < 0x13; idx++) {
			data[offset++] = (pca_registers[idx].data_bits & 0xFF);
		}
		result = pc_writeRegister(gSla, 0x85, data, 0x13 - 5) == pc_ok ? pca_ok : pca_writeFailed;
	}
	return result;
}

pca_result_t pcaSetAndWriteDataField(pca_data_fields_enum_t dataField, int value) {
	pcaSetDataField(dataField, value);
	return pcaWriteDataField(dataField);
}

pca_result_t pcaSetAndWriteRegister(int regNumber, int value) {
	pcaSetRegister(regNumber, value);
	return pcaWriteRegister(regNumber);
}

void pcaSlaveAddress(int sla) {
	gSla = (uint8_t)(sla & 0xFF);
}
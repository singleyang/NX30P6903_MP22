#include "pca9498_com.h"
#include "pca9498_com_local.h"

// interfaces
#include "aardvark_i2c.h"
#include "ft232h.h"

#include <string.h>

// Unique id's for interfaces
#define PC_ID_NONE                          (0)
#define PC_ID_AARDVARK                      (2)
#define PC_ID_FT232H                        (5)

// Names of known interfaces
#define pc_NAME_AARDVARK                    "Aardvark"
#define pc_NAME_FT232H                      "FT232H"

static size_t interfacecount = 0;
static pc_interface_t theInterface;

pc_interfaceID_t currentInterface = PC_ID_NONE;

void pca_com_init()
{
}

void pca_com_cleanup()
{
	if (theInterface.release) theInterface.release();
}

pc_result_t pc_selectInterface(pc_interfaceID_t interface_id)
{
	pc_release();
	currentInterface = interface_id;
	switch(interface_id)
	{
	case PC_ID_AARDVARK:
		if (av_open() == 0)
			av_registerInterface(&theInterface);
		break;
	case PC_ID_FT232H:
		if (ft232_open() == 0)
			ft232_registerInterface(&theInterface);
		break;
	default:
		currentInterface = PC_ID_NONE;
		return pc_invalidIF;
	}
	return pc_ok;
}

pc_result_t pc_selectedInterface(pc_interfaceID_t *interface_id)
{
	*interface_id = currentInterface;
	return pc_ok;
}

pc_result_t pc_claim()
{
	if (theInterface.claim) return theInterface.claim();
	return pc_nosuchfunction;
}

pc_result_t pc_release()
{
	if (theInterface.release) 
	{
		pc_result_t result = theInterface.release();
		memset(&theInterface, 0, sizeof(theInterface));
		return result;
	}
	return pc_nosuchfunction;
}

pc_result_t pc_init()
{
	return pc_ok;
}

pc_result_t pc_connected()
{
	if (theInterface.readRegister) return pc_ok;
	return pc_IFnotPresent;
}

pc_result_t pc_info(char *info, size_t sz)
{
	if (theInterface.info) return theInterface.info(info, sz);
	return pc_nosuchfunction;
}

pc_result_t pc_writeRead(uint64_t address, uint8_t dataOut[], uint16_t szOut, uint8_t dataIn[], uint16_t szIn)
{
	if (theInterface.writeRead == nullptr) return pc_IFnotPresent;
	return theInterface.writeRead(address, dataOut, szOut, dataIn, szIn);
}

pc_result_t pc_readRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count)
{
	if (data == nullptr) return pc_badParam;
	if (theInterface.readRegister) return theInterface.readRegister(sla, addr, data, count);
	return pc_nosuchfunction;
}

pc_result_t pc_writeRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count)
{
	if (theInterface.writeRegister) return theInterface.writeRegister(sla, addr, data, count);
	return pc_nosuchfunction;
}


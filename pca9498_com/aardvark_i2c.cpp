#include <SDKDDKVer.h>
#include <WinSDKVer.h>

// Set oldest supported version to Windows 7
//#undef _WIN32_WINNT
//#define _WIN32_WINNT _WIN32_WINNT_WIN7 
//#define NOCOMM
//#define WIN32_LEAN_AND_MEAN
//
//#include <windows.h>

#include "aardvark_i2c.h"
#include "aardvark.h"


#include <string.h>
#include <stdio.h>

// defines and typedefs
#define AV_BUS_FREQ_KHZ                     (400)
#define AV_BUF_SZ                           (0xFF)

// global variables
static Aardvark avHandle = 0;
static uint32_t avSerialNumber = 0;
static AardvarkExt avVersionInfo;

pc_result_t av_I2C_writeRead(uint64_t sla, uint8_t dataOut[], uint16_t szOut, uint8_t dataIn[], uint16_t szIn)
{
	if (dataOut == nullptr && szOut != 0) return pc_badParam;  
	if (dataIn  == nullptr && szIn  != 0) return pc_badParam;  
	pc_result_t result = pc_ok;
	uint16_t bytesRead, bytesWritten;
      
	if (szOut && szIn)
	{
		aa_i2c_write_read(avHandle, (u16)sla, AA_I2C_NO_FLAGS, szOut, (uint8_t *) dataOut, &bytesWritten, szIn, (uint8_t *) dataIn, &bytesRead);
		if (bytesWritten != szOut) result = pc_writeFailed;
		else if (bytesRead != szIn) result = pc_readFailed;
	}
	else if (szOut)
	{
		bytesWritten = aa_i2c_write(avHandle, (u16)sla, AA_I2C_NO_FLAGS, (uint16_t)(szOut & 0xFFFF), (uint8_t *)dataOut);
		if (bytesWritten != szOut) result = pc_writeFailed;
	}
	else if(szIn)
	{
		bytesRead = aa_i2c_read(avHandle, (u16)sla, AA_I2C_NO_FLAGS, (uint16_t)(szIn & 0xFFFF), dataIn);
		if (bytesRead != szIn) result = pc_readFailed;
	}
	return result;  
}

pc_result_t av_claim()
{
	pc_result_t result = pc_ok;
	if (avHandle <= 0) 
	{
		aa_close(0);
		const int size = 3;
		result = pc_IFnotPresent;
		uint16_t ports[size];
		uint32_t serialnumbers[size];
		int devcount = aa_find_devices_ext(size, ports, size, serialnumbers);
		if (devcount > size) devcount = size;
		int idx, portnr = -1;
		for (idx = 0; idx < devcount; idx++)
		{
			if ((ports[idx] & AA_PORT_NOT_FREE) != AA_PORT_NOT_FREE)
			{
				// Found a present and available Aardvark.
				// Use this one.
				portnr = idx;
				result = pc_ok;
				break;
			}
			else result = pc_IFbusy;
		}
		if (portnr >= 0)
		{
			avSerialNumber = serialnumbers[portnr];
			AardvarkExt avExt;
			avHandle = aa_open_ext(portnr, &avExt);
			if (avHandle > 0)
			{
				result = pc_ok;
				aa_configure(avHandle, AA_CONFIG_SPI_I2C);
				aa_i2c_bitrate(avHandle, AV_BUS_FREQ_KHZ / 1000);
				aa_target_power(avHandle, AA_CONFIG_I2C_MASK);
				avVersionInfo = avExt;
			}
			else 
			{
				result = pc_cantopenIF;
			}
		}
	}
	return result;
}

pc_result_t av_release()
{
	if (avHandle > 0)
	{
		aa_target_power(avHandle, AA_TARGET_POWER_NONE);
		aa_i2c_free_bus (avHandle);
		printf("aa_close(avHandle) returned %d\n", aa_close(avHandle));
	}
	avHandle = 0;
	return pc_ok;
}

pc_result_t av_open()
{
	pc_result_t result = pc_ok;
	if (avHandle <= 0) 
	{
		// See if we could get a handle to an Aardvark, but don't do so yet (That's what claim() is for)
		const int size = 3;
		result = pc_IFnotPresent;
		uint16_t ports[size];
		int devcount = aa_find_devices(size, ports);
		if (devcount > size) devcount = size;
		int idx, portnr = -1;
		for (idx = 0; idx < devcount; idx++)
		{
			if ((ports[idx] & AA_PORT_NOT_FREE) != AA_PORT_NOT_FREE)
			{
				// Found a present and available Aardvark.
				result = pc_ok;
				break;
			}
			else result = pc_IFbusy;
		}
	}
	else
	{
		// Test if aardvark is still present
		/*if (aa_i2c_monitor_disable(avHandle) != AA_OK)
		{
			av_close();
			return av_open();
		}*/
		av_close();
		return av_open();
	}
	return result;
}

void av_close()
{
	av_release();
}

pc_result_t av_info(char *info, size_t sz)
{
	if (avHandle <= 0) return pc_IFnotPresent;
	sprintf_s(info, sz, "Aardvark (SN: %u). HW: %d.%d FW: %d.%d SW: %d.%d", 
		avSerialNumber,
		avVersionInfo.version.hardware >> 8, avVersionInfo.version.hardware & 0xFF, 
		avVersionInfo.version.firmware >> 8, avVersionInfo.version.firmware & 0xFF, 
		avVersionInfo.version.software >> 8, avVersionInfo.version.software & 0xFF);
	return pc_ok;
}

pc_result_t av_readRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count)
{
	return av_I2C_writeRead(sla, &addr, 1, data, (uint16_t)count & 0xFFFF); 
}

pc_result_t av_writeRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count)
{
	if (count > AV_BUF_SZ) return pc_badParam;
	uint8_t dataOut[AV_BUF_SZ];
	dataOut[0] = addr;
	memcpy(&dataOut[1], data, count); 
	return av_I2C_writeRead(sla, dataOut, ((uint16_t)count & 0xFFFF) + 1, nullptr, 0);
}

void av_registerInterface(pc_interface_t *theInterface)
{
	if (theInterface != nullptr)
	{
		memset(theInterface, 0, sizeof(pc_interface_t));
		theInterface->claim = av_claim;
		theInterface->release = av_release;
		theInterface->writeRead = av_I2C_writeRead;
		theInterface->readRegister = av_readRegister;
		theInterface->writeRegister = av_writeRegister;
		theInterface->info = av_info;
	}
}

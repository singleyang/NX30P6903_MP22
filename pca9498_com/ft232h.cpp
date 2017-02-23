#include <SDKDDKVer.h>
#include <WinSDKVer.h>

//// Set oldest supported version to Windows 7
//#undef _WIN32_WINNT
//#define _WIN32_WINNT _WIN32_WINNT_WIN7 
//#define NOCOMM
//#define WIN32_LEAN_AND_MEAN
//
//#include <windows.h>

#include "ft232h.h"
#include "ftd2xx.h"
#include "libMPSSE_i2c.h"

#include <string.h>
#include <stdio.h>

// Link with ftd2xx.dll
#pragma comment(lib, "ftd2xx.lib")
#pragma comment(lib, "libMPSSE-I2C.lib")

// defines and typedefs
#define FT232_DEV_TYPE                         (8)     // Device type of FT232X as defined by FTDI
#define FT232_BUS_FREQ_HZ                      (4E5)
	
// global variables
static char ft232SerialNumber[16] = "";
static char ft232Description[64] = "";
static FT_HANDLE ft232Handle = 0;

ChannelConfig ft232_i2cChannel;

inline uint32_t ft232_i2c_write(uint8_t sla, uint16_t szOut, uint8_t *dataOut, bool addStop)
{
	uint32 bytesWritten = 0;
	FT_STATUS i2cStatus = I2C_DeviceWrite(ft232Handle, sla, szOut, dataOut, &bytesWritten, 
		I2C_TRANSFER_OPTIONS_BREAK_ON_NACK  | I2C_TRANSFER_OPTIONS_START_BIT | (addStop ? I2C_TRANSFER_OPTIONS_STOP_BIT : 0));
	return bytesWritten;
}

inline uint32_t ft232_i2c_read(uint8_t sla, uint16_t szIn, uint8_t *dataIn)
{
	uint32 bytesReceived = 0;
	if (szIn > 0)
	{
		I2C_DeviceRead(ft232Handle, sla, szIn, dataIn, &bytesReceived, I2C_TRANSFER_OPTIONS_NACK_LAST_BYTE | I2C_TRANSFER_OPTIONS_START_BIT | I2C_TRANSFER_OPTIONS_STOP_BIT);
	}
	return bytesReceived;
}

uint32_t ft232_i2c_write_read(uint8_t sla, uint16_t szOut, uint8_t *dataOut, uint16_t *bytesWritten, uint16_t szIn, uint8_t *dataIn, uint16_t *bytesRead)
{
	*bytesWritten = ft232_i2c_write(sla, szOut, dataOut, false);
	*bytesRead = ft232_i2c_read(sla, szIn, dataIn);
	return *bytesWritten + *bytesRead;
}

pc_result_t ft232_I2C_writeRead(uint64_t sla, uint8_t dataOut[], uint16_t szOut, uint8_t dataIn[], uint16_t szIn)
{
	if (dataOut == nullptr && szOut != 0) return pc_badParam;  
	if (dataIn  == nullptr && szIn  != 0) return pc_badParam;  
	pc_result_t result = pc_ok;
	uint16_t bytesRead, bytesWritten;
    bytesRead = bytesWritten = 0;
	if (szOut && szIn)
	{
		ft232_i2c_write_read((uint8_t)sla, szOut, (uint8_t *) dataOut, &bytesWritten, szIn, (uint8_t *) dataIn, &bytesRead);
		if (bytesWritten != szOut) result = pc_writeFailed;
		else if (bytesRead != szIn) result = pc_readFailed;
	}
	else if (szOut)
	{
		bytesWritten = ft232_i2c_write((uint8_t)sla, (uint16_t)(szOut & 0xFFFF), (uint8_t *)dataOut, true);
		if (bytesWritten != szOut) result = pc_writeFailed;
	}
	else if(szIn)
	{
		bytesRead = ft232_i2c_read((uint8_t)sla, (uint16_t)(szIn & 0xFFFF), dataIn);
		if (bytesRead != szIn) result = pc_readFailed;
	}
	return result;  
}

pc_result_t ft232_I2C_Init()
{
	pc_result_t result = pc_ok;
	Init_libMPSSE();
	FT_STATUS i2cStatus;
	// Set up the various I2C parameters
	ft232_i2cChannel.ClockRate = I2C_CLOCK_STANDARD_MODE; // 400Kbps
	ft232_i2cChannel.LatencyTimer = 1; // 1mS latency timer
	ft232_i2cChannel.Options = 0; // 3-phase clocking enabled
	i2cStatus = I2C_InitChannel(ft232Handle, &ft232_i2cChannel);
	if (i2cStatus)
	{
		result = pc_invalidIF;
	}
	else
	{
		uint8_t data[] = { 0x9E, 0x03, 0x00 };
		unsigned long sent;
		FT_Write(ft232Handle, data, 3, &sent);
	}
	return result;
}

pc_result_t ft232_claim()
{
	pc_result_t result = pc_ok;
	if (ft232Handle <= 0) 
	{
		FT_Close(ft232Handle);
		ft232Handle = 0;
		result = pc_IFnotPresent;
		FT_STATUS ftStatus; 
		DWORD numDevs; 
		// create a ftDevice information list and open the first available FT201X
		ftStatus = FT_CreateDeviceInfoList(&numDevs); 
		if (ftStatus == FT_OK) 
		{
			// allocate storage for list based on numDevs 
			FT_DEVICE_LIST_INFO_NODE *devInfo;
			devInfo = new FT_DEVICE_LIST_INFO_NODE[numDevs];
			ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs); 
			if (ftStatus == FT_OK) 
			{
				result = pc_cantopenIF;
				uint32_t i;
				for (i = 0; i < numDevs; i++) 
				{ 
					if (devInfo[i].Type == FT232_DEV_TYPE && (devInfo[i].Flags & 0x00000001) == 0)
					{
						// Found an unopened FT232
						ftStatus = FT_Open(i, &ft232Handle); 
						if (ftStatus == FT_OK) 
						{ 
							// Got it! Store info and configure ftDevice
							strncpy_s(ft232SerialNumber, sizeof(ft232SerialNumber), devInfo[i].SerialNumber, strnlen(devInfo[i].SerialNumber, sizeof(devInfo[i].SerialNumber)));
							strncpy_s(ft232Description, sizeof(ft232Description), devInfo[i].Description, strnlen(devInfo[i].Description, sizeof(devInfo[i].Description)));
							//ftStatus = FT_SetUSBParameters(ft232Handle, 64, 0);
							ftStatus = FT_SetBaudRate(ft232Handle, (ULONG)FT232_BUS_FREQ_HZ * 4);	// Synchronous frequency = 16 * baudrate
							ft232_I2C_Init();
							result = pc_ok;
							break;
						} 
						else 
						{ 
							// continue! See, if there are other devices
						}
					}
				} 
			} 
			delete devInfo;
		} 
		else
		{ 
			// FT_CreateDeviceInfoList failed 
			result = pc_cantopenIF;
		}
	}
	return result;
}

pc_result_t ft232_release()
{
	if (ft232Handle > 0)
	{
		FT_Close(ft232Handle);
	}
	ft232Handle = 0;
	Cleanup_libMPSSE();
	return pc_ok;
}

pc_result_t ft232_open()
{
	pc_result_t result = pc_ok;
	Init_libMPSSE();
	if (ft232Handle <= 0)
	{
		// See if we could get a handle to an FT232, but don't do so yet (That's what claim() is for)
		result = pc_IFnotPresent;
		FT_STATUS ftStatus; 
		DWORD numDevs; 
		// create the ftDevice information list 
		ftStatus = FT_CreateDeviceInfoList(&numDevs); 
		if (ftStatus == FT_OK) 
		{
			printf("Number of devices is %d\n",numDevs); 
		} 
		else
		{ 
			// FT_CreateDeviceInfoList failed 
			numDevs = 0;
			result = pc_cantopenIF;
		}

		if (numDevs > 0) 
		{ 
			// allocate storage for list based on numDevs 
			FT_DEVICE_LIST_INFO_NODE *devInfo;
			//devInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs); 
			devInfo = new FT_DEVICE_LIST_INFO_NODE[numDevs];
			// get the ftDevice information list 
			ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs); 
			if (ftStatus == FT_OK) 
			{
				uint32_t i;
				for (i = 0; i < numDevs; i++) 
				{ 
					if (devInfo[i].Type == FT232_DEV_TYPE && (devInfo[i].Flags & 0x00000001) == 0)
					{
						// Found an unopened FT232
						result = pc_ok;
						break;
					}
				} 
			} 
			delete devInfo;
		}
	}
	else
	{
		// Test if the device is still present
		UCHAR mode;
		if (FT_OK != FT_GetBitMode(ft232Handle, &mode)) 
		{
			ft232_close();
			return ft232_open();
		}
	}
	return result;
}

void ft232_close()
{
	ft232_release();
}

pc_result_t ft232_info(char *info, size_t sz)
{
	if (ft232Handle <= 0) return pc_IFnotPresent;
	sprintf_s(info, sz, "FT232H (SN: %s). %s", 
		ft232SerialNumber,
		ft232Description);
	return pc_ok;
}

pc_result_t ft232_readRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count)
{
	return ft232_I2C_writeRead(sla, &addr, 1, data, (uint16_t)count & 0xFFFF);
}

pc_result_t ft232_writeRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count)
{
	if (count > 0xFF) return pc_badParam;
	uint8_t dataOut[0xFF];
	dataOut[0] = addr;
	memcpy(&dataOut[1], data, count); 
	return ft232_I2C_writeRead(sla, dataOut, ((uint16_t)count & 0xFFFF) + 1, nullptr, 0);
}

void ft232_registerInterface(pc_interface_t *theInterface)
{
	if (theInterface != nullptr)
	{
		memset(theInterface, 0, sizeof(pc_interface_t));
		theInterface->claim = ft232_claim;
		theInterface->release = ft232_release;
		theInterface->writeRead = ft232_I2C_writeRead;
		theInterface->readRegister = ft232_readRegister;
		theInterface->writeRegister = ft232_writeRegister;
		theInterface->info = ft232_info;
	}
}

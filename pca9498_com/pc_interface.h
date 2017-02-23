#ifndef _PC_INTERFACE_H_
#define _PC_INTERFACE_H_

#include <stdint.h>

typedef enum pc_result
{
	pc_ok,
	pc_invalidIF,
	pc_IFnotPresent,
	pc_IFbusy,
	pc_nosuchfunction,
	pc_cantopenIF,
	pc_badParam,
	pc_readFailed,
	pc_writeFailed,
	pc_timedout,
	pc_dataTooLarge,
	pc_unknown,
} pc_result_t;

typedef pc_result_t (*pc_claim_t)();
typedef pc_result_t (*pc_release_t)();
typedef pc_result_t (*pc_writeRead_t)(uint64_t address, uint8_t dataOut[], uint16_t szOut, uint8_t dataIn[], uint16_t szIn);
typedef uint64_t (*pc_address_t)();
typedef pc_result_t (*pc_readRegister_t)(uint8_t sla, uint8_t addr, uint8_t *data, size_t count);
typedef pc_result_t (*pc_writeRegister_t)(uint8_t sla, uint8_t addr, uint8_t *data, size_t count);
typedef pc_result_t (*pc_info_t)(char *info, size_t sz);

typedef struct pc_interface
{
	pc_claim_t claim;
	pc_release_t release;
	pc_writeRead_t writeRead;
	pc_address_t address;
	pc_readRegister_t readRegister;
	pc_writeRegister_t writeRegister;
	pc_info_t info;
} pc_interface_t;

typedef void (*pc_registerInterface_t)(pc_interface_t *theInterface);

#endif // _PC_INTERFACE_H_
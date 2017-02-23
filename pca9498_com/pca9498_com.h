#ifndef _TEA190X_COM_H_
#define _TEA190X_COM_H_

#include <stdint.h>
#include "pc_interface.h"

typedef uint32_t pc_interfaceID_t;

/* Selects a specific interface to be used in IO related functions */
pc_result_t pc_selectInterface(pc_interfaceID_t interface_id);

/* Retrieves the current interface identifier */
pc_result_t pc_selectedInterface(pc_interfaceID_t *interface_id);

pc_result_t pc_claim();
pc_result_t pc_release();
pc_result_t pc_init();
pc_result_t pc_connected();
pc_result_t pc_info(char *info, size_t sz);
pc_result_t pc_readRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count);
pc_result_t pc_writeRegister(uint8_t sla, uint8_t addr, uint8_t *data, size_t count);

#endif // _TEA190X_COM_H_
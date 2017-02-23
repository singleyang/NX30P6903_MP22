#ifndef _TEA190X_COM_LOCAL_H_
#define _TEA190X_COM_LOCAL_H_

#include "pca9498_com.h"

#ifdef __cplusplus
extern "C" {
#endif

void pca_com_init();
void pca_com_cleanup();

pc_result_t pc_writeRead(uint64_t address, uint8_t dataOut[], uint16_t szOut, uint8_t dataIn[], uint16_t szIn);

#ifdef __cplusplus
}
#endif

#endif // _TEA190X_COM_LOCAL_H_
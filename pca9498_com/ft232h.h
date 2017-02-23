#ifndef _FT232H_H_
#define _FT232H_H_

#include "pc_interface.h"

pc_result_t ft232_open();

void ft232_close();

void ft232_registerInterface(pc_interface_t *theInterface);

#endif // _FT232H_H_
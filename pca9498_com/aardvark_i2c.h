#ifndef _AARDVARK_H_
#define _AARDVARK_H_

#include "pc_interface.h"

pc_result_t av_open();

void av_close();

void av_registerInterface(pc_interface_t *theInterface);
			
#endif // _AARDVARK_H_
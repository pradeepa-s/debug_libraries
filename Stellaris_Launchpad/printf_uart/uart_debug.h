/*
 * uart_debug.h
 *
 *  Created on: Oct 25, 2014
 *      Author: PradeepaS
 */

#ifndef UART_DEBUG_H_
#define UART_DEBUG_H_

#include <stdio.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/rom.h"
#include "driverlib/uart.h"


#define TO_HEX_CHAR(y,x)		{ 	if(x > 9)\
										y = 'A' + x - 9;\
									else\
										y = '0' + x;\
								}


void InitUARTDebug(void);
void PrintRegValue(const char *string_val, unsigned long reg_value);


#endif /* UART_DEBUG_H_ */

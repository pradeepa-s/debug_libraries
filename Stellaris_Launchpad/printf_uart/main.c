/*
 * main.c
 */

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
#include "uart_debug.h"


int main(void) {
	
	/* PS: Set the clock frequency of the processor */
	ROM_SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_5);

	InitUARTDebug();

	while(1)
	{
		PrintString("Hello UART library!!!\n\r");
		PrintRegValue("This is int value 1024: ",1024);
	}

	return 0;
}

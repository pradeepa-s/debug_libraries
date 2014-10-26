/*
 * main.c
 */

#include "uart_debug.h"

void InitUARTDebug(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	GPIOPinConfigure(GPIO_PA0_U0RX);
	GPIOPinConfigure(GPIO_PA1_U0TX);

	GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

	UARTEnable(UART0_BASE);

//	// Enable clock to the peripheral (UART0)
//	HWREG(SYSCTL_RCGCUART) = 0x00000001;
//
//	// Enable port A of GPIO (PA0 and PA1 for UART0)
//	HWREG(SYSCTL_RCGCGPIO) = 0x00000001;
//
//	// Enable alternate function on pin PA0 and PA1
//	HWREG(GPIO_PORTA_BASE + GPIO_O_AFSEL)	= 0x00000001;
//	HWREG(GPIO_PORTA_BASE + GPIO_O_PCTL) 	= 0x00000001;

}

void PrintRegValue(const char *string_val, unsigned long reg_value)
{
	char c[8];
	int  i = 0;
	//char v = 0;
	while(*string_val != '\0')
	{
		UARTCharPut(UART0_BASE, string_val[0]);
		string_val++;
	}

	UARTCharPut(UART0_BASE, '0');
	UARTCharPut(UART0_BASE, 'x');

	while(i < 8)
	{
		TO_HEX_CHAR(c[i],(char)((reg_value >> (28 - i*4)) & 0x0000000F));
		UARTCharPut(UART0_BASE, c[i++]);
	}

	UARTCharPut(UART0_BASE, '\n');
	UARTCharPut(UART0_BASE, '\r');
}

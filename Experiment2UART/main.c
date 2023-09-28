/*
 * Experiment2UART.c
 *
 * Created: 9/25/2023 1:15:55 PM
 * Author : timke
 */ 

#include "UART.h"
#include <util/delay.h>


int main(void)
{
	uint32_t BAUD_RATE = 9600; 
	
    UART_init(UART0, BAUD_RATE); 
    UART_init(UART0, BAUD_RATE); 
    UART_init(UART1, BAUD_RATE); 
    UART_init(UART2, BAUD_RATE); 

    while (1) 
    {
       UART_transmit(UART0, 0x55);
       UART_transmit(UART1, 0x55);
       UART_transmit(UART2, 0x55);
        _delay_ms(50);

    }
}


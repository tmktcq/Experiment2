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
    UART_init(UART1, (uint32_t)9600U); 

    while (1) 
    {
        UART_transmit(UART0, 0xAA);
        _delay_ms(500);
        UART_transmit(UART1, 0xAA);
        _delay_ms(500);
    }
}


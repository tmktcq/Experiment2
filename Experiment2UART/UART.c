#include "UART.h"


uint32_t Calc_Baudrate(uint32_t baud_rate, uint8_t UtwoX)
{
    //return (uint32_t)(((F_CPU/OSC_DIV)/(8*(2-U2X)*baud_rate))-1);

    return (uint32_t)((((F_CPU/OSC_DIV)+(4UL*(2-UtwoX)*baud_rate))/(8UL*(2-UtwoX)*baud_rate))-1);
}

void UART_init(volatile UART_t *UART_addr, uint32_t baud_rate)
{
// Calculate the baud rate reload value using the constants F_CPU,
// OSC_DIV and U2X_bit. Write the values to UBRRH, UBRRL and set or
// clear the U2X bit in UCSRA.
    uint16_t UBRR_value = Calc_Baudrate(baud_rate, U2X_Val); //Where do we get U2X

    UART_addr->UART_UBRR = UBRR_value;
    UART_addr->UART_UCSRA = 0; //set u2x here. currently off (0)

// Determine the value for UCSRC using the settings for number of bits,
// parity and number of stop bits and write this value. In my solution, I
// defined constants for these settings to make the code more readable. You
// could also make sure your comments explain the value written to the
// register.
    UART_addr->UART_UCSRC = (async_mode | no_parity | one_stop_bit | eight_bit_data);

// Enable the transmitter and receiver with interrupts disabled by writing the
// appropriate value to UCSRB
    UART_addr->UART_UCSRB = (RXCIE_dis | TXCIE_dis | UDRIE_dis | RXEN_en | TXEN_en);
    return; 
}

void UART_transmit(volatile UART_t *UART_addr, uint8_t data)
{
    //1: wait for UDRE to be set
    while(( UART_addr->UART_UCSRA & (1<<UDRE)) != (1<<UDRE));

    //2: write val to UDR
    UART_addr->UART_UDR = data;
    return;
}


uint8_t UART_receive(volatile UART_t *UART_addr)
{
    //1: wait for rxc bit to be set
    while (!(UART_addr->UART_UCSRA & ( 1 << RXCn)));
    //2: read value from UDR (rxc cleared by read from UDR)
    //??? This seems to be the same "UART_UDR" in the return statement below
    //3: return received value
    return UART_addr->UART_UDR;
}
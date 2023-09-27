/*
 * board.h
 *
 * Created: 9/4/2020 11:57:19 AM
 *  Author: tony tim ben
 */

#ifndef BOARD_H_
#define BOARD_H_


#define F_CPU (16000000UL)
#define OSC_DIV (1)

#include <avr/io.h>

//struct to simplify the offsets of port registers. Pointer to the struct is needed for proper use.
typedef struct port_regs
{
    volatile uint8_t PIN_REG;
    volatile uint8_t DDR_REG;
    volatile uint8_t PORT_REG;
} GPIO_port_t;


// structs defined for each port:
#define PA ( ( volatile GPIO_port_t * ) 0x20 )
#define PB ( ( volatile GPIO_port_t * ) 0x23 )
#define PC ( ( volatile GPIO_port_t * ) 0x26 )
#define PD ( ( volatile GPIO_port_t * ) 0x29 )
#define PE ( ( volatile GPIO_port_t * ) 0x2C )

#ifndef	UCSR0A
#define UCSR0A 0xC0U
#endif

#ifndef UCSR1A
#define UCSR1A 0xC8U
#endif 

#ifndef UCSR2A
#define UCSR2A 0xD0U
#endif 

#define DELAY 10000 



#endif
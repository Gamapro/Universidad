/*
* main.c
*
* Created: 3/1/2022 9:01:01 AM
*  Author: David Gamaliel Arcos
*/


#define F_CPU 4000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#define isClear(r, i) (!(r & (1 << i)))
#define isSet(r, i) (r & (1 << i))

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
// #include <stdlib.h>
#include <stdio.h>
// #include <cstdlib>
#include <time.h>

#define PINX PINA
#define PORTX PORTA
#define DDRX DDRA


void USART_INIT(uint16_t ubrr){
	
	DDRD = 0x02;
	PORTD = 0x00;
	
	// set baud rate
	UBRRH = (uint8_t)(ubrr>>8);
	UBRRL = (uint8_t)ubrr;
	
	UCSRB = (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);  // receive, transmit, interruption
	UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);
	
}

void USART_TRANSMIT(uint8_t data){
	while( !( UCSRA & (1<<UDRE) ) ){} // wait empty transmit buffer
	UDR = data;
}

uint8_t keyboard[4][4] ={
	{0xD, 0xC, 0xB, 0xA},
	{0xF, 0x3, 0x6, 0x9},
	{0x0, 0x2, 0x5, 0x8},
	{0xE, 0x1, 0x4, 0x7}
};uint8_t keyboard_char[4][4] ={
	{'7', '8', '9', 'A'},
	{'4', '5', '6', 'B'},
	{'1', '2', '3', 'C'},
	{'E', '0', 'F', 'D'}
};
uint8_t px = 0, py = 0;
volatile uint8_t a = 0, b = 0;
volatile uint8_t tecla = 0;
volatile uint8_t s[16], s2[16];

uint8_t hastaTecla(){
	for(uint8_t i = 0;; i++, i %= 4){
		PORTX = ~(1 << i);
		asm("nop");
		asm("nop");
		for(uint8_t j = 4; j < 8; j++){
			if(isClear(PINX, j)){
				_delay_ms(50);
				while(isClear(PINX, j));
				_delay_ms(50);
				px = j; py = i;
				return keyboard_char[7 - j][3 - i];
			}
		}
	}
}

void start(){

	USART_INIT(MYUBRR);

	DDRX = 0x0F;
	PORTX = 0xFF;
	
}

int main(){
	
	start();
	
	while(1){
		tecla = hastaTecla();
		USART_TRANSMIT(tecla);
	}
	
}

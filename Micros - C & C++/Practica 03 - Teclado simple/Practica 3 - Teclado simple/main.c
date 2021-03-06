/*
 * main.c
 *
 * Created: 2/3/2022 3:10:09 PM
 *  Author: David Gamaliel Arcos
 */ 

#define F_CPU 1000000
#define offBit(x,i) !(x & (1<<i))
#define onBit(x,i)  (x & (1<<i))
#define moveFour(x) x=(x<<4)

#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

#define PORTT PORTA
#define PINT PINA 

int main(void){
	
	DDRA = 0x00;	// Entrada
	PORTA = 0xFF;	// Pull ups
	
	DDRC = 0xFF;	// Salida
	PORTC = 0x00;	// Ceros
	
	uint8_t aum = 0;
	
	while(1){
		
		if( offBit(&PINA, 0) && aum < 99 ){ // incremento
			_delay_ms(50);
			while(offBit(&PINA, 0)){}
			aum++;
			_delay_ms(50);
		}
		
		if( offBit(&PINA, 7) && aum > 0 ){ // decremento
			_delay_ms(50);
			while(offBit(&PINA, 7)){}
			aum--;
			_delay_ms(50);
		}
		
		uint8_t d = (aum/10) + ((aum%10) << 4);
		PORTC = d;
		
	}
}

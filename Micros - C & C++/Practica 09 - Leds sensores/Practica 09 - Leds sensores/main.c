/*
 * main.c
 *
 * Created: 3/12/2022 6:49:01 PM
 *  Author: david
 */ 

#define F_CPU 4000000

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// #include <cstdlib>
#include <time.h>

#define setBit(x,i) x|=(1<<i)
#define clearBit(x,i) x&=(~(1<<i))
#define offBit(x,i) !(x & (1<<i))
#define onBit(x,i)  ((int)(x) & (int)(1<<i))
#define moveFour(x) x=(x<<4)

#define ADMUX_PIN0 0b01000000
#define ADMUX_PIN1 0b01000001
#define ADMUX_PIN2 0b01000010
#define ADMUX_PIN7 0b01000111

uint8_t a,b,c;

#define adc_to_5(x) x=((x/200.0)*(500.0/511.0))
#define adc_to_5_real(x) x=x/200.0


void readPin(uint8_t pin, int idx){
			
	ADMUX = pin;
			
	ADCSRA |= (1<<ADSC);
	while( onBit(ADCSRA, ADSC) ){}
	
	int res = ADC;
	// _delay_ms(500);
		
	adc_to_5(res);
	
	if(idx == 0) a = res;			
	if(idx == 1) b = res;			
	else c = res;
	
}

int main(void){
	
	ADMUX = 0b01000111;
	ADCSRA = 0b10010101; // 4MHZ
	
	a=b=c=0;
	
	DDRA = 0x00;	// Entrada
	PORTA = 0x00;	// No Pull ups
	
	DDRB = 0xFF;	// Salida
	DDRC = 0xFF;	// Salida
	PORTB = 0x00;
	PORTC = 0x00;
	
	while(1){
		
		readPin(ADMUX_PIN0, 0);
		readPin(ADMUX_PIN1, 1);
		readPin(ADMUX_PIN2, 2);
		
		uint8_t out = 0;
		
		while(c-- > 0){ out<<=1; setBit(out,0); }
		PORTC = out;
		
		out = 0; c = 0;
		while(a-- > 0){ out<<=1; setBit(out,0); }
		while(b-- > 0){ c<<=1; setBit(c,0); }
		out = (out&0xF)|(c<<4);
		PORTB = out;
			
	}
	
	
	
}
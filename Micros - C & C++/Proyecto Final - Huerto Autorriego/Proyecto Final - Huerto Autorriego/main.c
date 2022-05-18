/*
 * main.c
 *
 * Created: 5/15/2022 1:52:52 PM
 *  Author: David Gamaliel Arcos Bravo
 */ 

#define F_CPU 4000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
#define isClear(r, i) (!(r & (1 << i)))
#define isSet(r, i) (r & (1 << i))
#define setBit(x,i) ((x) |=  (1 << (i)))
#define clrBit(x,i) ((x) &= ~(1 << (i)))

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "libraries/Serial.c"	
#include "libraries/DHT.c"

uint16_t temperature_int = 0;
uint16_t humidity_int = 0; 

void start(){
	
	DHT_DDR = 0x00; DHT_PORT = 0xFF; // Sensores entrada con pull up
	// LCD_init();
	DDRA = 0xFF; PORTA = 0x00;
	USART_INIT(MYUBRR);
		
}

void waterPumpActive(){
	
}

void checkSensors(){
	if(dht_GetTempUtil(&temperature_int, &humidity_int) != -1) {
		
	}
}

uint8_t cero_en_bit(volatile uint8_t *LUGAR, uint8_t BIT)
{
	return (!(*LUGAR&(1<<BIT)));
}

int main(void){
	
	start();
	
    while(1){
	
		_delay_ms(200);
		
		checkSensors();
		USART_TRANSMIT('D');
		/*if( cero_en_bit(&PINB,1) ){
			_delay_ms(50);
			USART_TRANSMIT('7');
			while( cero_en_bit(&PINB,1) ){}
			_delay_ms(50);
		}
		// USART_TRANSMIT('1');
		// 11010000 ADDRESSDEL 0x6 8
		
		uint8_t data = USART_RECEIVE(); 
		USART_TRANSMIT(data);
		if(data == '0' || data == 0x00){
			setBit(PORTA, 1);	
			USART_TRANSMIT(data);			
		}
		if(data == '1' || data == 0x01){
			clrBit(PORTA, 1);
			USART_TRANSMIT(data);
		}*/
    
	}

}

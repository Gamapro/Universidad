/*
 * main.c
 *
 * Created: 1/27/2022 3:42:16 PM
 *  Author: David Gamaliel Arcos
 */ 

#define F_CPU 1000000

#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>

int main(void){
	
	DDRA = 0x00;	// Entrada	
	PORTA = 0xFF;	// Pull ups
	
	DDRC = 0xFF;	// Salida
	PORTC = 0x00;	// Ceros
	
	uint8_t cosa;
	
    while(1){

		cosa = ~PINA; // leo puerto A :vv
		cosa >>= 4;
		
		if(cosa == 1){
			PORTC = 0b00000110; // 1
		}else if(cosa == 2){
			PORTC = 0b01011011; // 2
		}else if(cosa == 3){
			PORTC = 0b01001111; // 3
		}else if(cosa == 4){
			PORTC = 0b01100110; // 4
		}else if(cosa == 5){
			PORTC = 0b01101101; // 5
		}else if(cosa == 6){
			PORTC = 0b01111101; // 6
		}else if(cosa == 7){
			PORTC = 0b00000111; // 7
		}else if(cosa == 8){
			PORTC = 0b01111111; // 8
		}else if(cosa == 9){
			PORTC = 0b01101111; // 9
		}else{
			PORTC = 0b00111111; // 0
		}
		
    }
	
}
/*
 * main.c
 *
 * Created: 4/12/2022 10:27:34 AM
 *  Author: david
 */ 

#define F_CPU 4000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void motores(uint8_t mot1 , uint8_t mot2){
	uint8_t mask = 0;
	mask |= mot1;
	mask |= (mot2 << 2);
	PORTD = mask;
}

void apagarMotores(){
	motores(0,0);
}
void derechaNormal(){
	motores(1, 0);
}

void derechaEnchinga(){
	motores(1, 2);
}

void izquierda(){
	motores(0, 1);
}

void izquierdaenchinga(){
	motores(2, 1);
}

void reversa(){
	motores(2,2);
}

void adelante(){
	motores(1,1);
}

void start(){

	DDRB = 0x00;
	DDRD = 0xFF;

	PORTB = 0x00;
	PORTD = 0x00;

	// _delay_ms(1500);
	_delay_ms(5200);
}

int main(){
	start();
	while(1){
		adelante();
		_delay_ms(2000);
		derechaEnchinga();
		_delay_ms(500);
		apagarMotores();
		_delay_ms(500);
		derechaEnchinga();
		_delay_ms(2000);
		_delay_ms(2000);
		_delay_ms(2000);
		adelante();
		_delay_ms(600);
		reversa();
		_delay_ms(900);
		
		/*if(PINB == 0b10000000){ // Derecha
			derechaNormal();
			_delay_ms(200);
		}else if(PINB == 0b01000000){ // Izquierda
			izquierda();
			_delay_ms(200);
		}else if(PINB == 0b11000000){ // Atras
			reversa();
			_delay_ms(200);
			derechaEnchinga();
			_delay_ms(200);
		}else{
			adelante();
			_delay_ms(50);
		}*/
	}
}
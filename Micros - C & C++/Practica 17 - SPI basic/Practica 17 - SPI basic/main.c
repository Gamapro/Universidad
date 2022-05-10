/*
 * main.c
 *
 * Created: 5/5/2022 11:29:12 AM
 *  Author: david
 */ 

#define F_CPU 8000000
#define isClear(r, i) (!(r & (1 << i)))
#define isSet(r, i) (r & (1 << i))

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// #include <cstdlib>
#include <time.h>

void SPI_INIT_MASTER(){
	// MOSI, SCK como salidas, MISO como entrada
	DDRB = (1<<5) | (1<<7); // MOSI 5  SCK 7  MISO 6 
	// Configurar SPCR, si hiciera falta también SPSR (para interrupciones o velocidad).
	SPCR = (1 << SPE) | (1 << MSTR) | (1<< SPR1) | (1<< SPR0); // Enable, Master, 128 Fosc
	// EXTRA - bits que irán a SS como salidas
	// Poner un 1 en todos los bits SS de los esclavos
	DDRA = 0XFF;
	PORTA = 0XFF;
}

uint8_t SPI_TRANSMIT(uint8_t slave_idx, uint8_t data){
	// Seleccionar el esclavo con el que se quiere comunicar (poner un 0)
	PORTA = ~(1<<slave_idx);
	// Escribir el dato en SPDR
	SPDR = data;
	// Esperar hasta que el bit SPIF se tenga un 1 (para garantizar que terminó la transmisión)
	while( !( SPSR &  (1<<SPIF)) ){}
	// Regresar el bit del esclavo a 1.
	PORTA |= (1<<slave_idx);
	return SPDR;
}

void start(){
	
	SPI_INIT_MASTER();
	
	DDRC = 0x00;
	PORTC = 0xFF;
	
}

int main(void)
{
	start();
	uint8_t x;
    while(1)
    {
        if( isClear(PINC, 0) ){
			_delay_ms(50);
			while(isClear(PINC, 0)){}
			x = SPI_TRANSMIT(6, 0b11111110);
			x = SPI_TRANSMIT(7, 0b11110000);
			_delay_ms(50);
		}
    }
}
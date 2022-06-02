/*
/*
 * main.c
 *
 * Created: 5/15/2022 1:52:52 PM
 *  Author: David Gamaliel Arcos Bravo
 */ 

#include "utilities.h"

void set_eeprom_position(uint16_t pos){
	// EEARH:EEARL – EEPROM ADDRESS REGISTER
	EEARL = (uint8_t)pos;
	EEARH = (uint8_t)((pos>>8)&1);
}

uint8_t read_eeprom(uint16_t pos){
	// EEDR – EEPROM DATA REGISTER	// EECR – EEPROM CONTROL REGISTER
	while( EECR & (1<<EEWE) ){} // Mientras dato escribiendose
	set_eeprom_position(pos);
	EECR = (1<<EERE);
	return EEDR;
}

void write_eeprom(uint16_t pos, uint8_t data){
	// EEDR – EEPROM DATA REGISTER	// EECR – EEPROM CONTROL REGISTER
	cli();
	while( EECR & (1<<EEWE) ){} // Mientras dato escribiendose
	set_eeprom_position(pos);
	EEDR = data;
	EECR = (1<<EEMWE);
	EECR|= (1<<EEWE); // | (1<<EERE);
	sei();
	return;
}

void ADC_INIT(){
	ADMUX = 0b01000111;
	ADCSRA = 0b10010100; // 2MHZ
	DDRA = 0x00;	// Entrada
	PORTA = 0x00;	// No Pull ups
}

#define adc_to_10(x) x=((x/100.0)*(500.0/511.0))

int readADC(uint8_t pin){
	
	cli();
	
	ADMUX = pin;
	
	ADCSRA |= (1<<ADSC);
	while( isSet(ADCSRA, ADSC) ){}
	
	int res = ADC;
	sei();
	return adc_to_10(res);
	
}

void USART_INIT(uint16_t ubrr){
	
	DDRD = 2;
	PORTD = 0;
	
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

uint8_t USART_RECEIVE(){
	while( !( UCSRA & (1<<RXC) ) ){} // wait data to be received
	return UDR;
}

void USART_TRANSMIT_STRING(volatile const char *s){
	char c;
	while((c=*s++)){
		USART_TRANSMIT(c);
	}
	USART_TRANSMIT(' ');
}

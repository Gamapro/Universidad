/*
 * main.c
 *
 * Created: 4/5/2022 2:07:12 PM
 *  Author: david
 */ 

#define F_CPU 2000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1
#define isClear(r, i) (!(r & (1 << i)))
#define isSet(r, i) (r & (1 << i))
#define setBit(x,i) x|=(1<<i)
#define clearBit(x,i) x&=(~(1<<i))
#define offBit(x,i) !(x & (1<<i))
#define onBit(x,i)  ((int)(x) & (int)(1<<i))
#define moveFour(x) x=(x<<4)

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// #include <cstdlib>
#include <time.h>

#define PINX PINB
#define PORTX PORTB
#define DDRX DDRB

#define DDRLCD DDRC
#define PORTLCD PORTC
#define PINLCD PINC
#define RS 4
#define RW 6
#define E 5
#define BF 3

#define LCD_Cmd_Clear      0b00000001	// replace all characters with ASCII 'space'
#define LCD_Cmd_Home       0b00000010  // return cursor to first position on first line
//#define LCD_Cmd_Mode     0b000001 ID  S
#define LCD_Cmd_ModeDnS	   0b00000110 //sin shift cursor a la derecha
#define LCD_Cmd_ModeInS	   0b00000100 //sin shift cursor a la izquierda
#define LCD_Cmd_ModeIcS	   0b00000111 //con shift desplazamiento a la izquierda
#define LCD_Cmd_ModeDcS	   0b00000101 //con shift desplazamiento a la derecha
//#define LCD_Cmd_OnOff    0b00001 D C B
#define LCD_Cmd_Off		   0b00001000
#define LCD_Cmd_OnsCsB	   0b00001100
#define LCD_Cmd_OncCsB     0b00001110
#define LCD_Cmd_OncCcB     0b00001111
//#define LCD_Cmd_Shift    0b0001 SC  RL 00
//#define LCD_Cmd_Function 0b001 DL  N  F  00
#define LCD_Cmd_Func2Lin   0b00101000
#define LCD_Cmd_Func1LinCh 0b00100000
#define LCD_Cmd_Func1LinG  0b00100100
//#define LCD_Cmd_DDRAM    0b1xxxxxxx

void saca_uno(volatile uint8_t *LUGAR, uint8_t BIT);
void saca_cero(volatile uint8_t *LUGAR, uint8_t BIT);
void LCD_wr_inst_ini(uint8_t instruccion);
void LCD_wr_char(uint8_t data);
void LCD_wr_instruction(uint8_t instruccion);
void LCD_wait_flag(void);
void LCD_init(void);
void LCD_wr_string(volatile const char *s);
void LCD_wr_lines(volatile const char *a, volatile const char *b);uint8_t keyboard_char[4][4] ={
	{'7', '8', '9', 'D'},
	{'4', '5', '6', 'C'},
	{'1', '2', '3', 'B'},
	{'*', '0', '#', 'A'}
};uint8_t keyboard[4][4] ={
	{7,  8,  9, 10},
	{4,  5,  6, 10},
	{1,  2,  3, 10},
	{10, 0, 10, 10}
};
volatile uint8_t s[16], tecla, idx, idxFake;

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
				return keyboard_char[7 - j][3 - i];
			}
		}
	}
}

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
	while( EECR & (1<<EEWE) ){} // Mientras dato escribiendose
	set_eeprom_position(pos);
	EEDR = data;
	EECR = (1<<EEMWE);
	EECR|= (1<<EEWE); // | (1<<EERE);
	return;
}

void USART_INIT(uint16_t ubrr){
	
	DDRD = 2;
	PORTD = 0;
	
	// set baud rate
	UBRRH = (uint8_t)(ubrr>>8);
	UBRRL = (uint8_t)ubrr;
	
	UCSRB = (1<<RXEN) | (1<<TXEN) | (1<<RXCIE);  // receive, transmit, interruption
	// UCSRC = (1<<URSEL) | (1<<USBS) | (3<<UCSZ0);
	UCSRC = (1<<URSEL) | (3<<UCSZ0); // 1BIT
	
}

void USART_TRANSMIT(uint8_t data){
	while( !( UCSRA & (1<<UDRE) ) ){} // wait empty transmit buffer
	UDR = data;
}

// INTERRUPCION
volatile uint8_t int_serial_data;
ISR(USART_RXC_vect){
	int_serial_data = UDR;
}

uint8_t USART_RECEIVE(){
	while( !( UCSRA & (1<<RXC) ) ){} // wait data to be received
	return UDR;
}

void ADC_INIT(){
	ADMUX = 0b01000111;
	ADCSRA = 0b10010100; // 2MHZ
	
	DDRA = 0x00;	// Entrada
	PORTA = 0x00;	// No Pull ups
}

#define ADMUX_PIN0 0b01000000
#define ADMUX_PIN1 0b01000001
#define ADMUX_PIN2 0b01000010
#define ADMUX_PIN7 0b01000111

#define adc_to_5(x) x=((x/200.0)*(500.0/511.0))

int readPin(uint8_t pin){
	
	ADMUX = pin;
	
	ADCSRA |= (1<<ADSC);
	while( onBit(ADCSRA, ADSC) ){}
	
	int res = ADC;
	adc_to_5(res);
	return res;
}

void start(){

	sei();
	LCD_init();
	DDRX = 0x0F;
	PORTX = 0xFF;	USART_INIT(MYUBRR);
	ADC_INIT();
	idx = 0;
		
}

int main(){
	
	start();
	
	while(1){
		
		LCD_wr_instruction(LCD_Cmd_Clear);
		LCD_wr_instruction(0b10000000); //posición cero!
		sprintf(s, "Esperando C...");
		LCD_wr_string(s);
		
		int_serial_data = '@';
		while(int_serial_data != 'C'){}
		_delay_ms(200);
		
		uint8_t valor_adc = readPin(ADMUX_PIN7) + 1;
		if(valor_adc > 5) valor_adc = 5;
		LCD_wr_instruction(LCD_Cmd_Clear);
		LCD_wr_instruction(0b10000000); //posición cero!
		sprintf(s, "Esperando %d val", valor_adc);
		LCD_wr_string(s);
		
		idx = 0;
		LCD_wr_instruction(0b11000000);//posición cero abajo
		int_serial_data = '@';
		while(idx < valor_adc){
			if(int_serial_data < '0' || int_serial_data > '9' ) continue;
			write_eeprom(idx, int_serial_data);
			sprintf(s, "%c ", int_serial_data);
			LCD_wr_string(s);
			int_serial_data = '@';
			idx+=1;
		}
		
		idxFake = idx;
		while(idxFake <= 4){
			write_eeprom(idxFake, '@');
			idxFake += 1;
		}
		
		_delay_ms(1000);
		
		USART_TRANSMIT('X');
		LCD_wr_instruction(LCD_Cmd_Clear);
		LCD_wr_instruction(0b10000000); //posición cero!
		sprintf(s, "Escribe...", valor_adc);
		LCD_wr_string(s);
		LCD_wr_instruction(0b11000000);//posición cero abajo
		
		idx = 0;
		while(idx < valor_adc){
			tecla = hastaTecla();
			if(tecla != read_eeprom(idx) ) continue;
			sprintf(s, "%c ", tecla);
			LCD_wr_string(s);
			idx+=1;
		}
		
		_delay_ms(1000);
		
		LCD_wr_instruction(LCD_Cmd_Clear);
		LCD_wr_instruction(0b10000000); //posición cero!
		sprintf(s, "Terminado :)", valor_adc);
		LCD_wr_string(s);
		
		_delay_ms(1000);
		

		
	}
	
}

void LCD_wr_string(volatile const char *s){
	char c;
	while((c=*s++)){
		LCD_wr_char(c);
	}
}

void LCD_wr_lines(volatile const char *a, volatile const char *b){
	LCD_wr_instruction(LCD_Cmd_Clear);
	LCD_wr_instruction(LCD_Cmd_Home);
	LCD_wr_instruction(0b10000000);
	LCD_wr_string(a);
	LCD_wr_instruction(0b11000000);
	LCD_wr_string(b);
}

void LCD_init(void){
	DDRLCD=(15<<0)|(1<<RS)|(1<<RW)|(1<<E); //DDRLCD=DDRLCD|(0B01111111)
	_delay_ms(15);
	LCD_wr_inst_ini(0b00000011);
	_delay_ms(5);
	LCD_wr_inst_ini(0b00000011);
	_delay_us(100);
	LCD_wr_inst_ini(0b00000011);
	_delay_us(100);
	LCD_wr_inst_ini(0b00000010);
	_delay_us(100);
	LCD_wr_instruction(LCD_Cmd_Func2Lin); //4 Bits, n?mero de l?neas y tipo de letra
	LCD_wr_instruction(LCD_Cmd_Off); //apaga el display
	LCD_wr_instruction(LCD_Cmd_Clear); //limpia el display
	LCD_wr_instruction(LCD_Cmd_ModeDnS); //Entry mode set ID S
	LCD_wr_instruction(LCD_Cmd_OnsCsB); //Enciende el display
}

void LCD_wr_char(volatile uint8_t data){
	//saco la parte m?s significativa del dato
	PORTLCD=data>>4; //Saco el dato y le digo que escribir? un dato
	saca_uno(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	saca_uno(&PORTLCD,E);
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
	//saco la parte menos significativa del dato
	PORTLCD=data&0b00001111; //Saco el dato y le digo que escribir? un dato
	saca_uno(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	saca_uno(&PORTLCD,E);
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
	saca_cero(&PORTLCD,RS);
	LCD_wait_flag();
}

void LCD_wr_inst_ini(uint8_t instruccion){
	PORTLCD=instruccion; //Saco el dato y le digo que escribir? un dato
	saca_cero(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	saca_uno(&PORTLCD,E);
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
}

void LCD_wr_instruction(uint8_t instruccion){
	//saco la parte m?s significativa de la instrucci?n
	PORTLCD=instruccion>>4; //Saco el dato y le digo que escribir? un dato
	saca_cero(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	saca_uno(&PORTLCD,E);
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
	//saco la parte menos significativa de la instrucci?n
	PORTLCD=instruccion&0b00001111; //Saco el dato y le digo que escribir? un dato
	saca_cero(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	saca_uno(&PORTLCD,E);
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
	LCD_wait_flag();
}


void LCD_wait_flag(void){
	//	_delay_ms(100);
	DDRLCD&=0b11110000; //Para poner el pin BF como entrada para leer la bandera lo dem?s salida
	saca_cero(&PORTLCD,RS);// Instrucci?n
	saca_uno(&PORTLCD,RW); // Leer
	while(1){
		saca_uno(&PORTLCD,E); //pregunto por el primer nibble
		_delay_ms(10);
		saca_cero(&PORTLCD,E);
		if(isSet(PINLCD,BF)) {break;} //uno_en_bit para protues, 0 para la vida real
		_delay_us(10);
		saca_uno(&PORTLCD,E); //pregunto por el segundo nibble
		_delay_ms(10);
		saca_cero(&PORTLCD,E);
	}
	saca_uno(&PORTLCD,E); //pregunto por el segundo nibble
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
	//entonces cuando tenga cero puede continuar con esto...
	saca_cero(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	DDRLCD|=(15<<0)|(1<<RS)|(1<<RW)|(1<<E);
}


void saca_uno(volatile uint8_t *LUGAR, uint8_t BIT){ // al usarla, no olvidar el &
	*LUGAR=*LUGAR|(1<<BIT);
}

void saca_cero(volatile uint8_t *LUGAR, uint8_t BIT){// al usarla, no olvidar el &
	*LUGAR=*LUGAR&~(1<<BIT);
}





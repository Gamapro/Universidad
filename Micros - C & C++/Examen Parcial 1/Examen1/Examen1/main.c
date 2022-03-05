/*
 * main.c
 *
 * Created: 3/1/2022 9:01:01 AM
 *  Author: David Gamaliel Arcos
 */ 
#define F_CPU 1000000
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

#define PINX PINC
#define PORTX PORTC
#define DDRX DDRC

#define DDRLCD DDRA
#define PORTLCD PORTA
#define PINLCD PINA
#define RS 5
#define RW 6
#define E 4
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
void LCD_wr_lines(volatile const char *a, volatile const char *b);

uint8_t keyboard[4][4] ={
	{0xD, 0xC, 0xB, 0xA},
	{0xF, 0x3, 0x6, 0x9},
	{0x0, 0x2, 0x5, 0x8},
	{0xE, 0x1, 0x4, 0x7}
};uint8_t keyboard_char[4][4] ={
	{'D', 'C', 'B', 'A'},
	{'F', '3', '6', '9'},
	{'0', '2', '5', '8'},
	{'E', '1', '4', '7'}
};
uint8_t px = 0, py = 0;
volatile uint8_t a = 0, b = 0;
volatile uint8_t cont = 0, precio = 0, pago = 0, puerto = 0;
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
				return keyboard[7 - j][3 - i];
			}
		}
	}
}

void start(){

	pago = 0;

	sei();
	GIFR = 0xE0;
	MCUCR = 0x02;
	GICR = 0x20;

	DDRX = 0x0F;
	PORTX = 0xFF;		DDRB = 0b00000010;	PORTB= 0b11111101;

	LCD_init();
	
}

void print_precio(){
	sprintf(s, "Inserta $%d.00", precio);
	if(cont < 10) sprintf(s2, "Tienes $0%d.00", cont);
	else sprintf(s2, "Tienes $%d.00", cont);
	LCD_wr_instruction(0b10000000); //posición cero!
	LCD_wr_string(s);
	LCD_wr_instruction(0b11000000);
	LCD_wr_string(s2);
}

ISR(INT2_vect){
	if(pago == 1){
		// cont = (cont+1)%10;
		puerto = PINB >> 4;
		if(puerto == 1) cont+=1;
		if(puerto == 2) cont+=2;
		if(puerto == 3) cont+=5;
		if(puerto == 4) cont+=10;
		while(isClear(PINB,2));
		if(puerto <= 4 && puerto > 0) print_precio();
	}
}

int main(){
	
	start();
	
	while(1){
	
		pago = 0;
		LCD_wr_instruction(LCD_Cmd_Clear);
		LCD_wr_instruction(0b10000000); //posición cero!
		sprintf(s, "Elige producto:");
		LCD_wr_string(s);
		
		uint8_t tecla, tecla_char;
		
		LCD_wr_instruction(LCD_Cmd_OncCcB);
		
		LCD_wr_instruction(0b11000000);//posición cero abajo		
		while(1){
			tecla = hastaTecla();
			tecla_char = keyboard_char[7-px][3-py];
			if(tecla == 0xA || tecla == 0xB) break;
		}
		LCD_wr_char(tecla_char);
		a = tecla;

		LCD_wr_instruction(0b11000001);//posición cero abajo		
		while(1){
			tecla = hastaTecla();
			tecla_char = keyboard_char[7-px][3-py];
			if(tecla == 0x1 || tecla == 0x2) break;
		}
		LCD_wr_char(tecla_char);
		b = tecla;
		
		if(a == 0xA){
			if(b == 0x1) precio = 11;
			else precio = 15;
		}else{
			if(b == 0x1) precio = 17;
			else precio = 32;
		}
		
		_delay_ms(500);
		LCD_wr_instruction(LCD_Cmd_Clear);
		LCD_wr_instruction(LCD_Cmd_OnsCsB);
		print_precio();
		
		pago = 1;
		// Esperar a interrupciones
		while(cont < precio);
		
		_delay_ms(500);
		
		LCD_wr_instruction(LCD_Cmd_Clear);
		sprintf(s, "Entregando...");
		sprintf(s2, "Cambio $%d.00", cont - precio);
		LCD_wr_instruction(0b10000000); //posición cero!
		LCD_wr_string(s);
		LCD_wr_instruction(0b11000000);
		LCD_wr_string(s2);
		
		_delay_ms(1500);
		
		cont = precio = 0;
		pago = 0;
		
		LCD_wr_instruction(LCD_Cmd_Clear);

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

void LCD_wr_char(uint8_t data){
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





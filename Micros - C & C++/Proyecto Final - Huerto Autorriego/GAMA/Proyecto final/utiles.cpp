#include "utiles.h"
#include <avr/io.h>
#include <util/delay.h>

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)	/* Define prescale value */
			/* Include math function */
#define SCL_CLK 100000L							/* Define SCL clock frequency */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

/* Interrupt vectors */
/* External Interrupt 0 */
#define INT0_vect _VECTOR(1)
/* External Interrupt 1 */
#define INT1_vect _VECTOR(2)
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect _VECTOR(3)
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect _VECTOR(4)
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect _VECTOR(5)
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect _VECTOR(6)
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect _VECTOR(7)
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect _VECTOR(8)
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect _VECTOR(9)
/* SPI Serial Transfer Complete */
#define SPI_STC_vect _VECTOR(10)
/* USART, RX Complete */
#define USART_RX_vect _VECTOR(11)
/* USART Data Register Empty */
#define USART_UDRE_vect _VECTOR(12)
/* USART, TX Complete */
#define USART_TX_vect _VECTOR(13)
/* ADC Conversion Complete */
#define ADC_vect _VECTOR(14)
/* EEPROM Ready */
#define EE_RDY_vect _VECTOR(15)
/* Analog Comparator */
#define ANA_COMP_vect _VECTOR(16)
/* Two-wire Serial Interface */
#define TWI_vect _VECTOR(17)
/* External Interrupt Request 2 */
#define INT2_vect _VECTOR(18)
/* TimerCounter0 Compare Match */
#define TIMER0_COMP_vect _VECTOR(19)
/* Store Program Memory Read */
#define SPM_RDY_vect _VECTOR(20)


void cambiar_a_0(volatile   uint8_t *puerto, uint8_t pos){
	*puerto &= ~(1<<pos);
}
void cambiar_a_1(volatile   uint8_t *puerto, uint8_t pos){
	*puerto |= (1<<pos);
}

bool hay0(uint8_t num, uint8_t pos)
{
	if (num & (1 << pos)){
		return 0;
	}
	return 1;
}
bool hay1(uint8_t num, uint8_t pos)
{
	if (num & (1 << pos)){
		return 1;
	}
	return 0;
}

uint8_t cero_en_bit(volatile uint8_t *LUGAR, uint8_t BIT)
{
	return (!(*LUGAR&(1<<BIT)));
}
uint8_t uno_en_bit(volatile uint8_t *LUGAR, uint8_t BIT)
{
	return (*LUGAR&(1<<BIT));
}


uint8_t swap(uint8_t num){
	return ((num & 0x0F) << 4 | (num & 0xF0) >> 4);
	/*uint8_t binario = 0;
	for (uint8_t i=0;i<4;i++ )
	{
		if(hay1(num,i)){
			binario |= (1<<(i+4));
		}
	}
	for (uint8_t i=0;i<4;i++ )
	{
		if(hay1(num,i+4)){
			binario |= (1<<(i));
		}
	}
	return binario;*/
}
uint8_t voltear(uint8_t num)
{
	uint8_t binario = 0;
	for (uint8_t i=0;i<8;i++ )
	{
		if(hay1(num,i)){
			binario |= (1<<(8-i-1));
		}
	}
	return binario;
}
uint8_t pow2(uint8_t num, uint8_t potencia){
	uint8_t n=1;
	if(potencia==0){
		return 1;
	}
	else{
		for (uint8_t i = 0; i < potencia; i++)
		{
			n*=num;
		}
	}
	return n;
}
uint8_t comp_a_1(uint8_t num)
{
	uint8_t binario = 0;
	for (uint8_t i=0;i<8;i++ )
	{
		if(hay0(num,i)){
			binario |= (1<<i);
		}
	}
	return binario;
}

void saca_uno(volatile uint8_t *LUGAR, uint8_t BIT){
	*LUGAR=*LUGAR|(1<<BIT);
}
void saca_cero(volatile uint8_t *LUGAR, uint8_t BIT){
	*LUGAR=*LUGAR&~(1<<BIT);
}
void delay_en_segundos(int n)
{
	for (int i = 0; i < n; i++)
	{
		_delay_ms(262);
		_delay_ms(262);
		_delay_ms(262);
		_delay_ms(262);
	}

}


// teclado

void hacer_antes(uint8_t num){}
void hacer_despues(uint8_t num){}
void hacer_mientras(uint8_t num){}
void teclado4x4(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][4],int coneccion_teclado[][4]){
	*puerto = 0xFF;
	for (int i =0;i<4;i++)
	{
		cambiar_a_0(puerto,coneccion_teclado[1][i]);
		for (int j =0;j<4;j++){
			if (cero_en_bit(pin, coneccion_teclado[0][j]))
			{
				hacer_antes(teclado_dispocicion[j][i]);
				_delay_ms(50);
				while (cero_en_bit(pin, coneccion_teclado[0][j]))
				{
					hacer_mientras(teclado_dispocicion[j][i]);
				}
				_delay_ms(50);
				hacer_despues(teclado_dispocicion[j][i]);
			}

		}
		cambiar_a_1(puerto,coneccion_teclado[1][i]);
	}
}
int teclado4x4_simple(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][4],int coneccion_teclado[][4]){
	*puerto = 0xFF;
	for (int i =0;i<4;i++)
	{
		cambiar_a_0(puerto,coneccion_teclado[1][i]);
		for (int j =0;j<4;j++){
			if (cero_en_bit(pin, coneccion_teclado[0][j]))
			{
				_delay_ms(50);
				while (cero_en_bit(pin, coneccion_teclado[0][j]))
				{
				}
				_delay_ms(50);
				return teclado_dispocicion[j][i];
			}

		}
		cambiar_a_1(puerto,coneccion_teclado[1][i]);
	}
	return 17;
}
void teclado4x3(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][3],int coneccion_teclado[][4]){
	*puerto = 0xFF;
	for (int i =0;i<3;i++)
	{
		cambiar_a_0(puerto,coneccion_teclado[1][i]);
		for (int j =0;j<4;j++){
			if (cero_en_bit(pin, coneccion_teclado[0][j]))
			{
				hacer_antes(teclado_dispocicion[j][i]);
				_delay_ms(50);
				while (cero_en_bit(pin, coneccion_teclado[0][j]))
				{
					hacer_mientras(teclado_dispocicion[j][i]);
				}
				_delay_ms(50);
				hacer_despues(teclado_dispocicion[j][i]);
			}

		}
		cambiar_a_1(puerto,coneccion_teclado[1][i]);
	}
}



// motor a pasos
void motor_pos(volatile uint8_t *puerto){
	*puerto = 0b10001100;
	_delay_ms(50);
	*puerto = 0b10000110;
	_delay_ms(50);
	*puerto = 0b10000011;
	_delay_ms(50);
	*puerto = 0b10001001;
	_delay_ms(50);
}
void motor_neq(volatile uint8_t *puerto){
	*puerto = 0b00000011;
	_delay_ms(50);
	*puerto = 0b00000110;
	_delay_ms(50);
	*puerto = 0b00001100;
	_delay_ms(50);
	*puerto = 0b10001001;
	_delay_ms(50);
}


// serbo

// display
#define DDRLCD DDRC  //puedo cambiar el puerto al que se va a conectar
#define PORTLCD PORTC
#define PINLCD PINC
#define RS 4  // son los pines en los que esta conectada esa parte del LCD
#define RW 5
#define E 6
#define BF 3  //pin de la bandera conectada
#define LCD_Cmd_Clear      0b00000001   //es la instruccion del clear
#define LCD_Cmd_Home       0b00000010   //es la instruccion que me lleva a la posicion hoem
//#define LCD_Cmd_Mode     0b000001 ID  S
#define LCD_Cmd_ModeDnS	   0b00000110 //sin shift cursor a la derecha
#define LCD_Cmd_ModeInS	   0b00000100 //sin shift cursor a la izquierda
#define LCD_Cmd_ModeIcS	   0b00000111 //con shift desplazamiento a la izquierda
#define LCD_Cmd_ModeDcS	   0b00000101 //con shift desplazamiento a la derecha
//#define LCD_Cmd_OnOff    0b00001 D C B
#define LCD_Cmd_Off		   0b00001000    //apaga display
#define LCD_Cmd_OnsCsB	   0b00001100	//enciende disply sin cursor sin blinking
#define LCD_Cmd_OncCsB     0b00001110	//enciende display con cursor sin blinking
#define LCD_Cmd_OncCcB     0b00001111	//enciende display con cursor con blinking
//#define LCD_Cmd_Shift    0b0001 SC  RL 00
//#define LCD_Cmd_Function 0b001 DL  N  F  00
#define LCD_Cmd_Func2Lin   0b00101000	//dos lineas
#define LCD_Cmd_Func1LinCh 0b00100000	//1 linea letra chica
#define LCD_Cmd_Func1LinG  0b00100100	//1 linea con letra grande
//#define LCD_Cmd_DDRAM    0b1xxxxxxx



void LCD_wr_string(char *s){
	char c;
	while((c=*s++)){
		LCD_wr_char(c);
	}
}
void LCD_init(void){	// inicializa LCD  es lo del datasheet
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
	LCD_wr_instruction(LCD_Cmd_OncCcB); //Enciende el display
}
void LCD_wr_char(uint8_t data){  //mandar datos
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
void LCD_wr_inst_ini(uint8_t instruccion){ // manda instrucciones de 4 bits las del inicio del datasheet del lcd
	PORTLCD=instruccion; //Saco el dato y le digo que escribir? un dato
	saca_cero(&PORTLCD,RS);
	saca_cero(&PORTLCD,RW);
	saca_uno(&PORTLCD,E);
	_delay_ms(10);
	saca_cero(&PORTLCD,E);
}
void LCD_wr_instruction(uint8_t instruccion){  // escribe instrucciones de 8 bits
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
void LCD_wait_flag(void){  // espera que la bandera de ocupado se libere
	//	_delay_ms(100);
	DDRLCD&=0b11110000; //Para poner el pin BF como entrada para leer la bandera lo dem?s salida
	saca_cero(&PORTLCD,RS);// Instrucci?n
	saca_uno(&PORTLCD,RW); // Leer
	while(1){
		saca_uno(&PORTLCD,E); //pregunto por el primer nibble
		_delay_ms(10);
		saca_cero(&PORTLCD,E);
		if(uno_en_bit(&PINLCD,BF)) {break;} //uno_en_bit para protues, 0 para la vida real
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
void  LCD_posicion_inicio(int pos, int linea)
{
	int x =0;
	if (linea == 2)
	{
		x = (0x40 + pos) | 0x80;
	}
	else
	{
		x =  (0x00 + pos) | 0x80;
	}
	LCD_wr_instruction(x);
}
void LCD_clear()
{
	LCD_wr_instruction(LCD_Cmd_Clear);
}

void LCD_wr_num_int(int x){
	if(x!=0){
		LCD_wr_num_int_r(x);
	}else{
		LCD_wr_char('0');
	}
	
}
void LCD_wr_num_int_r(int x){
	if(x<=0) return;
	LCD_wr_num_int_r(x/10);
	LCD_wr_char(x%10+'0');
}
void LCD_wr_num_float(float x){
	int x_Entero = x;		
	LCD_wr_num_int(x_Entero);	
	int x_Decimal= (x-(float)x_Entero)*100;	
	LCD_wr_char('.');		
	if(x_Decimal!=0){
		if(x_Decimal<10){
			LCD_wr_char('0');
		}
		LCD_wr_num_int(x_Decimal);
	}else{
		LCD_wr_string("00");
	}
	
}



// eeproom
void  eprom_write_unit(uint8_t dato,uint16_t direccion){
	while(EECR & (1 << EEWE));
	EEAR = direccion;
	EEDR = dato;
	cli();
	EECR |= (1 << EEMWE);
	EECR |= (1 << EEWE);
	sei();
}
int eprom_read_unit(uint16_t direccion){
	while(EECR & (1 << EEWE));
	EEAR = direccion;
	EECR |= (1 << EERE);
	return EEDR;
}


// serial 
void SerialInit(long USART_BAUDRATE,int stopbits,int char_size)
{
		
	saca_uno(&DDRD,1);
	saca_cero(&DDRD,0);
	UCSRB |= (1 << RXEN) | (1 << TXEN)|(1 << RXCIE);	// resepcion transmicion interrupcion
	/* Set frame format: 8data, 2stop bit */
	switch(char_size){
		case 9:
			char_size = 7;
		break;
		default:
			char_size-=5;	
	}
	//UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	UCSRC = (1<<URSEL) | ((stopbits-1)<<USBS) | (char_size<<UCSZ0);
	UBRRL = BAUD_PRESCALE;			/* Load lower 8-bits of the baud rate */
	UBRRH = (BAUD_PRESCALE >> 8);		/* Load upper 8-bits*/
}



void SerialPutChar(char c) {
	while (!(UCSRA & (1 << UDRE)));
	UDR = c;
}

void SerialPutString(char* s) {
	while (*s)
	SerialPutChar(*s++);
}

char SerialGetChar() {
	while (!(UCSRA & (1 << RXC)));
	return UDR;
}

char SerialHayDatoRecivido() {
	return (UCSRA & (1 << RXC));
}


// adc
void ADC_iniciar_convercion(){
	ADCSRA=ADCSRA|(1<<ADSC);
}


// I2C
void I2C_Init()												
{
	TWBR = BITRATE(TWSR = 0x00);							
}


uint8_t I2C_Start(char slave_write_address)						
{
	uint8_t status;										
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);					
	while (!(TWCR & (1<<TWINT)));							
	status = TWSR & 0xF8;									
	if (status != 0x08){	
		return 0;
	}										
	TWDR = slave_write_address;								
	TWCR = (1<<TWEN)|(1<<TWINT);							
	while (!(TWCR & (1<<TWINT)));							
	status = TWSR & 0xF8;									
	if (status == 0x18){
		return 1;		
	}
											
	if (status == 0x20){
		return 2;			
	}										
	else{
		
		return 3;
	}								
}

uint8_t I2C_Repeated_Start(char slave_read_address)			
{
	uint8_t status;											
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);				
	while (!(TWCR & (1<<TWINT)));						
	status = TWSR & 0xF8;							
	if (status != 0x10)							
	return 0;									
	TWDR = slave_read_address;					
	TWCR = (1<<TWEN)|(1<<TWINT);							
	while (!(TWCR & (1<<TWINT)));							
	status = TWSR & 0xF8;									
	if (status == 0x18){
		return 1;
	}
	
	if (status == 0x20){
		return 2;
	}
	else{
		
		return 3;
	}											
}

void I2C_Stop()									
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);		
	while(TWCR & (1<<TWSTO));				
}

void I2C_Start_Wait(char slave_write_address)				
{
	uint8_t status;											
	while (1)
	{
		TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);				
		while (!(TWCR & (1<<TWINT)));						
		status = TWSR & 0xF8;								
		if (status != 0x08)									
		continue;											
		TWDR = slave_write_address;							
		TWCR = (1<<TWEN)|(1<<TWINT);						
		while (!(TWCR & (1<<TWINT)));						
		status = TWSR & 0xF8;								
		if (status != 0x18 )								
		{
			I2C_Stop();										
			continue;										
		}
		break;												
	}
}

uint8_t I2C_Write(char data)								
{
	uint8_t status;											
	TWDR = data;											
	TWCR = (1<<TWEN)|(1<<TWINT);							
	while (!(TWCR & (1<<TWINT)));							
	status = TWSR & 0xF8;									
	if (status == 0x28)									{
	return 0;												
	}
	
	if (status == 0x30)									{
		return 1;											
	}
	
	else
	{
		return 2;											
	}
	
	
}

char I2C_Read_Ack()										
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);				
	while (!(TWCR & (1<<TWINT)));						
	return TWDR;										
}

char I2C_Read_Nack()	{
	TWCR=(1<<TWEN)|(1<<TWINT);							
	while (!(TWCR & (1<<TWINT)));						
	return TWDR;										
}
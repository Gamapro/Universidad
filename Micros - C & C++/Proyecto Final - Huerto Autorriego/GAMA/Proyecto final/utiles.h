#ifndef _utiles
#define _utiles
	void cambiar_a_0( volatile uint8_t *puerto, uint8_t pos);
	void cambiar_a_1( volatile uint8_t *puerto, uint8_t pos);
	bool hay1(uint8_t num, uint8_t pos);
	bool hay0(uint8_t num, uint8_t pos);
	uint8_t cero_en_bit(volatile uint8_t *LUGAR, uint8_t BIT);
	uint8_t uno_en_bit(volatile uint8_t *LUGAR, uint8_t BIT);
	uint8_t swap(uint8_t num);
	uint8_t voltear(uint8_t num);
	uint8_t pow2(uint8_t num, uint8_t potencia);
	uint8_t comp_a_1(uint8_t num);
	void saca_uno(volatile uint8_t *LUGAR, uint8_t BIT);
	void saca_cero(volatile uint8_t *LUGAR, uint8_t BIT);
	void delay_en_segundos(int n);
	uint8_t voltear(uint8_t num);

	// teclado
	void hacer_antes(uint8_t num);
	void hacer_despues(uint8_t num);
	void hacer_mientras(uint8_t num);
	void teclado4x4(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][4],int coneccion_teclado[][4]);
	void teclado4x3(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][3],int coneccion_teclado[][4]);
	int teclado4x4_simple(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][4],int coneccion_teclado[][4]);
	void saca_uno(volatile uint8_t *LUGAR, uint8_t BIT);
	void saca_cero(volatile uint8_t *LUGAR, uint8_t BIT);
	int teclado4x4_simple(volatile uint8_t *puerto,volatile uint8_t *pin,int teclado_dispocicion[][4],int coneccion_teclado[][4]);
	// motor a paso
	void motor_pos(volatile uint8_t *puerto);
	void motor_neq(volatile uint8_t *puerto);
	// lcd
	void LCD_wr_string(char *s);
	void LCD_init(void);
	void LCD_wr_char(uint8_t data);
	void LCD_wr_inst_ini(uint8_t instruccion);
	void LCD_wr_instruction(uint8_t instruccion);
	void LCD_wait_flag(void);
	void LCD_posicion_inicio(int pos, int linea);
	void LCD_clear();
	void LCD_wr_num_int(int x);
	void LCD_wr_num_int_r(int x);
	void LCD_wr_num_float (float x) ;
	// tecldos
	/*
	int teclado_dispocicion[4][4] = {{1,2,3,10},//fila1
	{4,5,6,11},//f2
	{7,8,9,12},//f3
	{16,0,14,13}};//f4
	//c1 c2 c3 c4
	int coneccion_teclado[2][4]={{3,2,1,0},//filas
	{7,6,5,4}};//columnas

	int teclado_dispocicion2[4][3] = {{3,2,1},//fila1
								{6,5,4},//f2
								{9,8,7},//f3
								{14,0,16}};//f4
								//c1 c2 c3 c4
	int coneccion_teclado2[2][4]={{6,5,4,3},//filas
							{0,1,2,7}};//columnas
	int x = teclado4x4_simple(&PORTA,&PINA,teclado_dispocicion,coneccion_teclado);

	DDRA=0xF0;
	PORTA=0xFF;
		*/

	// eeproom
	int eprom_read_unit(uint16_t direccion);
	void  eprom_write_unit(uint8_t dato,uint16_t direccion);


	// serial 
	void SerialInit(long USART_BAUDRATE,int stopbits,int char_size);
	void SerialPutChar(char c);
	void SerialPutString(char* s);
	char SerialGetChar();
	char SerialHayDatoRecivido();

	// adc
	void ADC_iniciar_convercion();

	//I2C
	void I2C_Init()	;
	uint8_t I2C_Start(char slave_write_address);
	uint8_t I2C_Repeated_Start(char slave_read_address);
	void I2C_Stop()	;
	void I2C_Start_Wait(char slave_write_address)	;
	uint8_t I2C_Write(char data)	;
	char I2C_Read_Ack()	;
	char I2C_Read_Nack();
#include  "utiles.cpp"
#endif
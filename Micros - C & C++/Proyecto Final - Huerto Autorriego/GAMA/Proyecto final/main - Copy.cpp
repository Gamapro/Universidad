#define F_CPU 8000000UL									/* Define CPU clock Frequency e.g. here its 8MHz */
#include <avr/io.h>										/* Include AVR std. library file */
#include <util/delay.h>									/* Include delay header file */
#include <inttypes.h>									/* Include integer type header file */
#include <stdlib.h>										/* Include standard library file */
#include <stdio.h>				
						/* Include standard library file */
						
#include "MPU6050_res_define.h"							/* Include USART header file */
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)	/* Define prescale value */
			/* Include math function */
#define SCL_CLK 100000L							/* Define SCL clock frequency */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))) /* Define bit rate */
float Acc_x,Acc_y,Acc_z,Temperature,Gyro_x,Gyro_y,Gyro_z;


void I2C_Init()												/* I2C initialize function */
{
	TWBR = BITRATE(TWSR = 0x00);							/* Get bit rate register value by formula */
}


uint8_t I2C_Start(char slave_write_address)						/* I2C start function */
{
	uint8_t status;											/* Declare variable */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);					/* Enable TWI, generate start condition and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (start condition) */
	status = TWSR & 0xF8;									/* Read TWI status register with masking lower three bits */
	if (status != 0x08)										/* Check weather start condition transmitted successfully or not? */
	return 0;												/* If not then return 0 to indicate start condition fail */
	TWDR = slave_write_address;								/* If yes then write SLA+W in TWI data register */
	TWCR = (1<<TWEN)|(1<<TWINT);							/* Enable TWI and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (Write operation) */
	status = TWSR & 0xF8;									/* Read TWI status register with masking lower three bits */
	if (status == 0x18)										/* Check weather SLA+W transmitted & ack received or not? */
	return 1;												/* If yes then return 1 to indicate ack received i.e. ready to accept data byte */
	if (status == 0x20)										/* Check weather SLA+W transmitted & nack received or not? */
	return 2;												/* If yes then return 2 to indicate nack received i.e. device is busy */
	else
	return 3;												/* Else return 3 to indicate SLA+W failed */
}

uint8_t I2C_Repeated_Start(char slave_read_address)			/* I2C repeated start function */
{
	uint8_t status;											/* Declare variable */
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);					/* Enable TWI, generate start condition and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (start condition) */
	status = TWSR & 0xF8;									/* Read TWI status register with masking lower three bits */
	if (status != 0x10)										/* Check weather repeated start condition transmitted successfully or not? */
	return 0;												/* If no then return 0 to indicate repeated start condition fail */
	TWDR = slave_read_address;								/* If yes then write SLA+R in TWI data register */
	TWCR = (1<<TWEN)|(1<<TWINT);							/* Enable TWI and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (Write operation) */
	status = TWSR & 0xF8;									/* Read TWI status register with masking lower three bits */
	if (status == 0x40)										/* Check weather SLA+R transmitted & ack received or not? */
	return 1;												/* If yes then return 1 to indicate ack received */
	if (status == 0x20)										/* Check weather SLA+R transmitted & nack received or not? */
	return 2;												/* If yes then return 2 to indicate nack received i.e. device is busy */
	else
	return 3;												/* Else return 3 to indicate SLA+W failed */
}

void I2C_Stop()												/* I2C stop function */
{
	TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);					/* Enable TWI, generate stop condition and clear interrupt flag */
	while(TWCR & (1<<TWSTO));								/* Wait until stop condition execution */
}

void I2C_Start_Wait(char slave_write_address)				/* I2C start wait function */
{
	uint8_t status;											/* Declare variable */
	while (1)
	{
		TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);				/* Enable TWI, generate start condition and clear interrupt flag */
		while (!(TWCR & (1<<TWINT)));						/* Wait until TWI finish its current job (start condition) */
		status = TWSR & 0xF8;								/* Read TWI status register with masking lower three bits */
		if (status != 0x08)									/* Check weather start condition transmitted successfully or not? */
		continue;											/* If no then continue with start loop again */
		TWDR = slave_write_address;							/* If yes then write SLA+W in TWI data register */
		TWCR = (1<<TWEN)|(1<<TWINT);						/* Enable TWI and clear interrupt flag */
		while (!(TWCR & (1<<TWINT)));						/* Wait until TWI finish its current job (Write operation) */
		status = TWSR & 0xF8;								/* Read TWI status register with masking lower three bits */
		if (status != 0x18 )								/* Check weather SLA+W transmitted & ack received or not? */
		{
			I2C_Stop();										/* If not then generate stop condition */
			continue;										/* continue with start loop again */
		}
		break;												/* If yes then break loop */
	}
}

uint8_t I2C_Write(char data)								/* I2C write function */
{
	uint8_t status;											/* Declare variable */
	TWDR = data;											/* Copy data in TWI data register */
	TWCR = (1<<TWEN)|(1<<TWINT);							/* Enable TWI and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (Write operation) */
	status = TWSR & 0xF8;									/* Read TWI status register with masking lower three bits */
	if (status == 0x28)										/* Check weather data transmitted & ack received or not? */
	return 0;												/* If yes then return 0 to indicate ack received */
	if (status == 0x30)										/* Check weather data transmitted & nack received or not? */
	return 1;												/* If yes then return 1 to indicate nack received */
	else
	return 2;												/* Else return 2 to indicate data transmission failed */
}

char I2C_Read_Ack()										/* I2C read ack function */
{
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);					/* Enable TWI, generation of ack and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (read operation) */
	return TWDR;											/* Return received data */
}

char I2C_Read_Nack()										/* I2C read nack function */
{
	TWCR=(1<<TWEN)|(1<<TWINT);								/* Enable TWI and clear interrupt flag */
	while (!(TWCR & (1<<TWINT)));							/* Wait until TWI finish its current job (read operation) */
	return TWDR;											/* Return received data */
}


void USART_Init(unsigned long BAUDRATE)				/* USART initialize function */
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);				/* Enable USART transmitter and receiver */
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	/* Write USCRC for 8 bit data and 1 stop bit */
	UBRRL = BAUD_PRESCALE;							/* Load UBRRL with lower 8 bit of prescale value */
	UBRRH = (BAUD_PRESCALE >> 8);					/* Load UBRRH with upper 8 bit of prescale value */
}

char USART_RxChar()									/* Data receiving function */
{
	while (!(UCSRA & (1 << RXC)));					/* Wait until new data receive */
	return(UDR);									/* Get and return received data */
}

void USART_TxChar(char data)						/* Data transmitting function */
{
	UDR = data;										/* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE)));					/* Wait until data transmit and buffer get empty */
}

void USART_SendString(char *str)					/* Send string of USART data function */
{
	int i=0;
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}








void MPU6050_Init()										/* Gyro initialization function */
{
	_delay_ms(150);										/* Power up time >100ms */
	I2C_Start_Wait(0xD0);								/* Start with device write address */
	I2C_Write(SMPLRT_DIV);								/* Write to sample rate register */
	I2C_Write(0x07);									/* 1KHz sample rate */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(PWR_MGMT_1);								/* Write to power management register */
	I2C_Write(0x01);									/* X axis gyroscope reference frequency */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(CONFIG);									/* Write to Configuration register */
	I2C_Write(0x00);									/* Fs = 8KHz */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(GYRO_CONFIG);								/* Write to Gyro configuration register */
	I2C_Write(0x18);									/* Full scale range +/- 2000 degree/C */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(INT_ENABLE);								/* Write to interrupt enable register */
	I2C_Write(0x01);
	I2C_Stop();
}

void MPU_Start_Loc()
{
	I2C_Start_Wait(0xD0);								/* I2C start with device write address */
	I2C_Write(ACCEL_XOUT_H);							/* Write start location address from where to read */ 
	I2C_Repeated_Start(0xD1);							/* I2C start with device read address */
}

void Read_RawValue()
{
	MPU_Start_Loc();									/* Read Gyro values */
	Acc_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Acc_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Acc_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Temperature = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_x = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_y = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Ack());
	Gyro_z = (((int)I2C_Read_Ack()<<8) | (int)I2C_Read_Nack());
	I2C_Stop();
}

int main()
{
	char buffer[20], float_[10];
	float Xa,Ya,Za,t;
	float Xg=0,Yg=0,Zg=0;
	I2C_Init();											/* Initialize I2C */
	MPU6050_Init();										/* Initialize MPU6050 */
	USART_Init(9600);									/* Initialize USART with 9600 baud rate */
	
	while(1)
	{
		Read_RawValue();

		Xa = Acc_x/16384.0;								/* Divide raw value by sensitivity scale factor to get real values */
		Ya = Acc_y/16384.0;
		Za = Acc_z/16384.0;
		
		Xg = Gyro_x/16.4;
		Yg = Gyro_y/16.4;
		Zg = Gyro_z/16.4;

		t = (Temperature/340.00)+36.53;					/* Convert temperature in ?/c using formula */


		dtostrf( Xa, 3, 2, float_ );					/* Take values in buffer to send all parameters over USART */
		sprintf(buffer," Ax = %s g\t",float_);
		USART_SendString(buffer);

		dtostrf( Ya, 3, 2, float_ );
		sprintf(buffer," Ay = %s g\t",float_);
		USART_SendString(buffer);
		
		dtostrf( Za, 3, 2, float_ );
		sprintf(buffer," Az = %s g\t",float_);
		USART_SendString(buffer);

		dtostrf( t, 3, 2, float_ );
		sprintf(buffer," T = %s%cC\t",float_,0xF8);           /* 0xF8 Ascii value of degree '?' on serial */
		USART_SendString(buffer);

		dtostrf( Xg, 3, 2, float_ );
		sprintf(buffer," Gx = %s%c/s\t",float_,0xF8);
		USART_SendString(buffer);

		dtostrf( Yg, 3, 2, float_ );
		sprintf(buffer," Gy = %s%c/s\t",float_,0xF8);
		USART_SendString(buffer);
		
		dtostrf( Zg, 3, 2, float_ );
		sprintf(buffer," Gz = %s%c/s\r\n",float_,0xF8);
		USART_SendString(buffer);
	}
}

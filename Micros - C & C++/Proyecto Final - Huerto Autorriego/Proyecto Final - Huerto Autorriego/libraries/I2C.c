#include "utilities.h"
#include "Serial.c"

void I2C_INIT(){
	TWBR = BITRATE(TWSR = 0x00);
}

void I2C_START(){
	TWCR = (1 << TWINT)|(1 << TWSTA)|(1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	while((TWSR & 0xF8) != 0x08 && (TWSR & 0xF8) != 0x10){
		USART_TRANSMIT_STRING("Error I2C START");
		_delay_ms(1000);
	}
}

void I2C_SET_ADDRESS(uint8_t addr){
	TWDR = addr;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	/*while((TWSR & 0xF8) != 0x08 && (TWSR & 0xF8) != 0x10){
		USART_TRANSMIT_STRING("Error I2C SET ADRESS");
		_delay_ms(1000);
	}*/
}

void I2C_TRANSMIT(uint8_t data){
	TWDR = data;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while(!(TWCR & (1 << TWINT)));
	/*while((TWSR & 0xF8) != 0x08 && (TWSR & 0xF8) != 0x10){
		USART_TRANSMIT_STRING("Error I2C transmit");
		_delay_ms(1000);
	}*/
}

void I2C_STOP(){
	TWCR = (1 << TWINT)|(1 << TWEN)|(1 << TWSTO);
}

uint8_t i2c_read_nack(){
	TWCR = (1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}

uint8_t i2c_read_ack(){
	TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	return TWDR;
}

/********************** FUNCTIONS **********************/


void WRITE_CLOCK(uint8_t pos_add, uint8_t data){
	I2C_START();
	I2C_SET_ADDRESS( (CLOCK_ADDRESS<<1) );
	I2C_TRANSMIT(pos_add);
	I2C_TRANSMIT(data);
	I2C_STOP();
}

uint8_t READ_CLOCK(uint8_t pos_add){
	I2C_START();
	I2C_SET_ADDRESS( (CLOCK_ADDRESS<<1) );
	I2C_TRANSMIT(pos_add);
	I2C_START();
	I2C_SET_ADDRESS( (CLOCK_ADDRESS<<1)|1 );
	uint8_t val = i2c_read_nack();
	I2C_STOP();
	return val;
}

/********************** WRITE **********************/

void WRITE_DATE(uint8_t day,uint8_t month, uint8_t year){
	WRITE_CLOCK(0x04, day);
	WRITE_CLOCK(0x05, month);
	WRITE_CLOCK(0x06, year);
}
void WRITE_TIME(uint8_t seconds,uint8_t minutes, uint8_t hour){
	WRITE_CLOCK(0x00,seconds);
	WRITE_CLOCK(0x01,minutes);
	WRITE_CLOCK(0x02,hour);
}

/********************** WRITE **********************/

/********************** READ  *********************/

uint8_t READ_SECOND(){
	return READ_CLOCK(0x00);
}
uint8_t READ_MINUTE(){
	return ( READ_CLOCK(0x01) );
}
uint8_t READ_HOUR(){
	return READ_CLOCK(0x02);
}
uint8_t READ_DAY(){
	return READ_CLOCK(0x04);
}
uint8_t READ_MONTH(){
	uint8_t ans = READ_CLOCK(0x05);
	return ans;
}
uint8_t READ_YEAR(){
	uint8_t ans = READ_CLOCK(0x06);
	return ans;
}
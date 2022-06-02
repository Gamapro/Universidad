/*
 * main.c
 *
 * Created: 5/15/2022 1:52:52 PM
 *  Author: David Gamaliel Arcos Bravo
 */ 

#include "libraries/utilities.h"
// #include "libraries/Serial.c"	
#include "libraries/DHT.c"
#include "libraries/I2C.c"

volatile uint8_t temperature = 0, temp = 0;
volatile uint8_t humidity = 0, hum = 0;
volatile uint8_t ground_humidity = 0;
volatile uint8_t sound = 0;
volatile uint8_t hour = 0,minu = 0,sec = 0,year = 0, day = 0,month = 0;
volatile uint8_t s[30];

void start(){

	sei();
	GIFR = 0xE0;
	MCUCR = 0x02;
	GICR = 0x20;
	
	ADC_INIT();
	
	I2C_INIT();	
	
	DIGITAL_DDR = 0x00; DIGITAL_PORT = 0xFF; // Sensores entrada con pull up
	OUT_DDR = 0xFF; OUT_PORT = 0x00;
	USART_INIT(MYUBRR);

	sound = read_eeprom(SOUND_PIN)%2;
	setLed();
		
}

/********** INTERRUPTIONS **********/

ISR(INT2_vect){
	while(isSet(DIGITAL_PIN, SOUND_PIN)){}
	setLed();
}

// INTERRUPCION
volatile uint8_t int_serial_data;
ISR(USART_RXC_vect){
	int_serial_data = UDR;
	USART_TRANSMIT(int_serial_data);
	
	if(int_serial_data == 'W'){
		waterPumpActive();
	}
	
	if(int_serial_data == 'S'){
		checkSensors();
	}
	
	if(int_serial_data == 'D'){
		clock_module();
		sprintf(s,"TIME %.2d:%.2d:%.2d  DATE %d/%d/20%d"
		,hour, minu, sec,   day,month,year);
		USART_TRANSMIT_STRING(s);
	}
	
	if(int_serial_data == 'X'){
		// Cada cuanto
		uint8_t cuando = read_eeprom(CUANDO);
		cuando = (cuando+1)%4;
		if(cuando == 0) sprintf(s,"NO RIEGO");
		if(cuando == 1) sprintf(s,"RIEGO NOCTURNO");
		if(cuando == 2) sprintf(s,"RIEGO MATUTINO");
		if(cuando == 3) sprintf(s,"RIEGO MATUTINO Y NOCTURNO");
		write_eeprom(CUANDO, cuando);
		USART_TRANSMIT_STRING(s);
	}
	
	if(int_serial_data == 'K'){
		// Cuanto
		uint8_t cuando = read_eeprom(CADA_CUANTO);
		cuando = (cuando+1)%3;
		if(cuando == 0) sprintf(s,"DIARIO");
		if(cuando == 1) sprintf(s,"CADA 2 DIAS");
		if(cuando == 2) sprintf(s,"CADA 3 DIAS");
		write_eeprom(CADA_CUANTO, cuando);
		USART_TRANSMIT_STRING(s);
	}
	
	int_serial_data = '0';
}

/********** INTERRUPTIONS **********/

void setLed(){
	sound = (sound+1)%2;
	write_eeprom(SOUND_PIN, sound);
	if(sound > 0) setBit(OUT_PORT,RGB_LED_PIN);
	else clrBit(OUT_PORT,RGB_LED_PIN);
}

void waterPumpActive(){
	humidity_sensor();
	if(ground_humidity < 2){
		USART_TRANSMIT_STRING("MUY HUMEDO!!");
		return;
	}
	setBit(OUT_PORT, WATER_PUMP_PIN);
	_delay_ms(7500);
	clrBit(OUT_PORT, WATER_PUMP_PIN);
	return;
}

void dht_sensor(){
	Request();
	Response();
	humidity=Receive_data();
	hum=Receive_data();
	temperature=Receive_data();
	temp=Receive_data();
	uint8_t check=Receive_data();
	if ((humidity + hum + temperature + temp) != check){
		sprintf(s,"DHT ERROR");
		USART_TRANSMIT_STRING(s);
	}
	return;
}

void humidity_sensor(){
	ground_humidity = readADC( ADMUX_PIN | HUMIDITY_PIN );
	return;
}

void clock_module(){
	sec = READ_SECOND();
	minu = READ_MINUTE();
	hour = READ_HOUR();
	day = READ_DAY();
	month = READ_MONTH();
	year = READ_YEAR();
	return;
}

void checkSensors(){	
	("Sensors Humidity");
	humidity_sensor();
	sprintf(s,"Ground Humidity: %d",ground_humidity);
	USART_TRANSMIT_STRING(s);
	if(ground_humidity < 2) USART_TRANSMIT_STRING("MUY HUMEDO!!");
	if(ground_humidity >= 2 && ground_humidity <= 6) USART_TRANSMIT_STRING("HUMEDAD NORMAL");
	if(ground_humidity > 6) USART_TRANSMIT_STRING("MUY SECO!!");
	USART_TRANSMIT_STRING("Sensors DHT");
	dht_sensor();
	sprintf(s,"Temperature: %d.%d Humidity: %d.%d"
	,temperature,temp, humidity, hum);	
	USART_TRANSMIT_STRING(s);
	USART_TRANSMIT_STRING("Sensors Clock");
	clock_module();
	sprintf(s,"TIME %.2d:%.2d:%.2d  DATE %d/%d/20%d"
	,hour, minu, sec,   day,month,year);
	USART_TRANSMIT_STRING(s);	
}

void checkRiegoHorario(){
	uint8_t cuando = read_eeprom(CUANDO);
	if( cuando & 1 && hour == 20 && minu == 0 && sec < 30){ // nocturno
		waterPumpActive();
	}
	if( cuando & 2 && hour == 8 && minu == 0 && sec < 30){ // matutino
		waterPumpActive();
	}
}

int main(void){
	
	start();
	
    while(1){
	
		_delay_ms(100);
		
		clock_module();
		uint8_t cada_cuanto = read_eeprom(CADA_CUANTO);
		uint8_t cuando = read_eeprom(CUANDO);
		if( cada_cuanto == 0 ){
			checkRiegoHorario();
		}else{
			uint8_t pday = read_eeprom(EEPROM_DIA);
			if(day != pday){
				write_eeprom(EEPROM_DIA,day);
				uint8_t cont = read_eeprom(EEPROM_CONT);
				cont+=1;
				if(cont == cada_cuanto){
					checkRiegoHorario();
					if(cuando < 3) write_eeprom(EEPROM_CONT,0);
					if(cuando == 3 && hour == 8) write_eeprom(EEPROM_CONT,0);
				}else{
					write_eeprom(EEPROM_CONT,cont);
				}
			}
		}
		
		
		if( isClear(DIGITAL_PIN,BUTTON_PIN) ){
			_delay_ms(50);
			while( isClear(DIGITAL_PIN,BUTTON_PIN) ){}
		
			USART_TRANSMIT_STRING("Setting date and time");
			
			WRITE_DATE(21,5,22);
			WRITE_TIME(0,45,0);
			clock_module();
			write_eeprom(EEPROM_DIA, day);
			write_eeprom(EEPROM_CONT,0);
			
			_delay_ms(50);
		}
    
	}

}





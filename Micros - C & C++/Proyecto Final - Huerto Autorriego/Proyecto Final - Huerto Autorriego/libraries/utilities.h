/*
/*
 * main.c
 *
 * Created: 5/15/2022 1:52:52 PM
 *  Author: David Gamaliel Arcos Bravo
 */ 

#define F_CPU 4000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

#define CLOCK_ADDRESS 0x68

#define isClear(r, i) (!(r & (1 << i)))
#define isSet(r, i) (r & (1 << i))
#define setBit(x,i) ((x) |=  (1 << (i)))
#define clrBit(x,i) ((x) &= ~(1 << (i)))

#define SCL_CLK 100000
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define ADMUX_PIN 0b01000000
#define ADMUX_PIN7 0b01000111

// Define ports

#define DIGITAL_DDR DDRB
#define DIGITAL_PORT PORTB
#define DIGITAL_PIN PINB

#define ANALOG_DDR DDRA
#define ANALOG_PORT PORTA
#define ANALOG_PIN PINA	

#define OUT_DDR DDRC
#define OUT_PORT PORTC
#define OUT_PIN PINC

// Define sensor pins

#define DHT_PIN 0
#define SOUND_PIN 2
#define BUTTON_PIN 3
#define HUMIDITY_PIN 0

#define CLOCK_PIN 0

#define WATER_PUMP_PIN 3
#define RGB_LED_PIN 2

#define CADA_CUANTO 10
#define CUANDO 11
#define EEPROM_DIA 12
#define EEPROM_CONT 13

//timeout retries

#define DHT_TIMEOUT 300

extern int8_t readDHT(int8_t *temperature, int8_t *humidity);

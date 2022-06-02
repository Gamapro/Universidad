/*
 * main.c
 *
 * Created: 5/15/2022 1:52:52 PM
 *  Author: David Gamaliel Arcos Bravo
 */ 

#include "utilities.h"

void Request(){				/* Microcontroller send start pulse/request */
	DIGITAL_DDR |= (1<<DHT_PIN);
	DIGITAL_PORT &= ~(1<<DHT_PIN);	/* set to low pin */
	_delay_ms(20);			/* wait for 20ms */
	DIGITAL_PORT |= (1<<DHT_PIN);	/* set to high pin */
}

void Response()				/* receive response from DHT11 */
{
	DIGITAL_DDR &= ~(1<<DHT_PIN);
	while(DIGITAL_PIN & (1<<DHT_PIN));
	while((DIGITAL_PIN & (1<<DHT_PIN))==0);
	while(DIGITAL_PIN & (1<<DHT_PIN));
}

uint8_t Receive_data()			/* receive data */
{
	uint8_t c = 0;
	for (int q=0; q<8; q++)
	{
		while((DIGITAL_PIN & (1<<DHT_PIN)) == 0);  /* check received bit 0 or 1 */
		_delay_us(30);
		if(DIGITAL_PIN & (1<<DHT_PIN))/* if high pulse is greater than 30ms */
		c = (c<<1)|(0x01);	/* then its logic HIGH */
		else			/* otherwise its logic LOW */
		c = (c<<1);
		while(DIGITAL_PIN & (1<<DHT_PIN));
	}
	return c;
}
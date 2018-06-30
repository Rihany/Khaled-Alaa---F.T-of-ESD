/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */

#include  "../file.h/types.h"
#include  "../file.h/service.h"
#include <avr/io.h>
#include "ADC.h"
#include <util/delay.h>


void ADC_init(void )
{

	ADMUX |= (1<<ADLAR)|(1<<REFS0);					/* ADC Multiplexer Selection Register Register Description:-
													1-REFS1:0 : Reference Selection Bits ( REFS0=1 , REFS1=0  ==> Internal Vref)
																						 ( REFS0=0 , REFS1=0  ==> External Vref)
													2-ADLAR=1  (ADC Left Adjust Result) */
	ADCSRA|= (1<<ADEN)|(1<<ADPS2);					/* ADC Control and Status Register A Description :-
													1-ADEN: enable ADC
													2-ADPS2:0: ADC Rescale Select Bits:-	100	(division factor 16) ADC frequency = CPU freq / (division factor)
														ADC Frequency from 50kHz and 200kHz
													3-ADFR = 0  Disable ADC Free Running Select */
}

u8 ADC_read(u8 channal_Number)
{
	if (channal_Number <=NUMBER_OF_CHANNEL)        /* NON_DIFRENTIAL_MODE */
	{

		ADMUX &= 0xE0;							  /* saving ADMUX register values (BIT 7 , BIT 6 ,BIT 5  ) */
		ADMUX = ADMUX | channal_Number  ;		  /* choose the correct channel by setting the channel number in MUX4:0 bits */
		SET_BIT(ADCSRA , ADSC);					  /* ADC start conversion */
		while(IS_BIT_CLEAR(ADCSRA,ADIF));         /* polling on ADIF FLAG */
		SET_BIT(ADCSRA, ADIF);                    /* clear ADIF by write '1' to it :) */
		return ADCH;
	}
	else return 0;
}

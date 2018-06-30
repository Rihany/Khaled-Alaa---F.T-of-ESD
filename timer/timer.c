/*
 * timer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */
#include "../file.h/types.h"
#include "../file.h/registers.h"
#include "../file.h/service.h"
#include "../UART/UART.h"
#include "timer_cfg.h"
#include "timer.h"


u16 counter = 0 ; //counter of timer interrupt

u8 temperature = 0;
u8 temp_Digital = 0; //Save digital read
u8 TempStr[] = {" Temperature : "};

void Timer0_CM_vidInit (void) // Timer0 COMPARE MATCH Mode
{
	SET_BIT(SREG,GI_Enable); //GI enable
	SET_BIT(TIMSK,COMPAR_MATCH);//Counter CTC interrupt enable
	TCCR0 = 0b00001010; //configure .. prescaling & CTC mode
	OCR0 = 100; //value to compare with
}

void __vector_10 (void)__attribute__((signal,__INTR_ATTRS));
void __vector_10 (void)
{
	counter ++;
	if( counter == 30000) //Execute function with 3 second rate
	{
		temp_Digital = ADC_read(0); //Save digital read of ADC channel zero
		temperature = (temp_Digital*500) / 256; //Calibration of temperature sensor
		UART_vidTransmitDataString(TempStr); //Send "Temperature"
		UART_vidTransmitData(temperature); //Send temperature to serial monitor
		counter = 0; //return counter to initial value
	}
}

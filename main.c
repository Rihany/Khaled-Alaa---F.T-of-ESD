/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */

#include "file.h/types.h"
#include "file.h/registers.h"
#include "file.h/service.h"
#include  "file.h/uConfig.h"
#include "UART/UART.h"
#include "timer/timer.h"
#include "ADC/ADC.h"
#include "interrupt/interrupt.h"



void XIOT_SwitchIntererruptLED (u8 interrupt_Number);


int main (void)
{
	UART_vidInit(); //UART initialization

	ADC_init(); // ADC initialization
	CLEAR_BIT(PORTA,0); //Set temperature sensor as analog input pin (PORTA , pin 0)

	Timer0_CM_vidInit();//send temperature with 3 second rate, depend on interrupt of timer 0

	XIOT_SwitchIntererruptLED(0);
	XIOT_SwitchIntererruptLED(1);
	XIOT_SwitchIntererruptLED(2);


	while(1)
	{


	}
		return 0;
}

void XIOT_SwitchIntererruptLED (u8 interrupt_Number)
{
	//Function to control 3 switches and 3 LED's as max it's depend on type of microcontroller
	//Determine Switch number on function argument

	u8 erorrMsg[] = {"Error : Choose just from 0 to 2 on XIOT function"};

	if (interrupt_Number == 0)
	{
		CLEAR_BIT(DDRD,2); //Set switch pin as input (PORTD , pin 3)

		SET_BIT(PORTD,2); //Active bullup resistance

		SET_BIT(DDRD,4); //Set led pin as output (PORTB , pin 4)

		External_INTZero_vidPrefIntEnable(); //Enable external interrupt zero

	}

	else if (interrupt_Number == 1)
	{
		CLEAR_BIT(DDRD,3); //Set switch pin as input (PORTD , pin 3)

		SET_BIT(PORTD,3); //Active bullup resistance

		SET_BIT(DDRD,5); //Set led pin as output (PORTB , pin 4)

		External_INTOne_vidPrefIntEnable(); //Enable external interrupt one
	}
	else if (interrupt_Number == 2)
	{
		CLEAR_BIT(DDRB,2); //Set switch pin as input (PORTD , pin 3)

		SET_BIT(PORTB,2); //Active bullup resistance

		SET_BIT(DDRD,6); //Set led pin as output (PORTB , pin 4)

		External_INTTow_vidPrefIntEnable(); //Enable external interrupt tow
	}
	else
	{
		UART_vidTransmitDataString(erorrMsg);
	}
}


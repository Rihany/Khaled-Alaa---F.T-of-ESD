/*
 * interrupt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */
#include "../file.h/types.h"
#include "../file.h/registers.h"
#include "../file.h/service.h"
#include "interrupt_cfg.h"
#include "interrupt.h"
#include "../UART/UART.h"

u8 SwZeroPressed[] = {" Switch ZERO Pressed "};
u8 OnZeroStr[] = {" LED ZERO Status : ON "};
u8 OffZeroStr[] = {" LED ZERO Status : OFF "};


u8 SwOnePressed[] = {" Switch ONE Pressed "};
u8 OnOneStr[] = {" LED ONE Status : ON "};
u8 OffOneStr[] = {" LED ONE Status : OFF "};


u8 SwTowPressed[] = {" Switch TOW Pressed "};
u8 OnTowStr[] = {" LED TOW Status : ON "};
u8 OffTowStr[] = {" LED TOW Status : OFF "};


//_____________________________________________________________

void External_INTZero_vidPrefIntEnable(void)
{
	SET_BIT(SREG,GI_Enable); //Global Interrupt Enable
	SET_BIT(GICR,INT0_Enable); //Perapheral Interrupt Enable
	SET_BIT(MCUCR,INT0_Mode); //Interrupt Mode
}


void __vector_1 (void)__attribute__((signal,__INTR_ATTRS)); // Not nessary to write at file.h
void __vector_1 (void)
{


	TOGGOL_BIT(PORTD,4);
	if(IS_BIT_SET(PORTD,4))
	{
		UART_vidTransmitDataString(SwZeroPressed);
		UART_vidTransmitDataString(OnZeroStr);
	}
	else
	{
		UART_vidTransmitDataString(SwZeroPressed);
		UART_vidTransmitDataString(OffZeroStr);
	}

}


//_____________________________________________________________

void External_INTOne_vidPrefIntEnable(void)
{
	SET_BIT(SREG,GI_Enable); //Global Interrupt Enable
	SET_BIT(GICR,INT1_Enable); //Perapheral Interrupt Enable
	SET_BIT(MCUCR,INT1_Mode); //Interrupt Mode
}


void __vector_2 (void)__attribute__((signal,__INTR_ATTRS)); // Not nessary to write at file.h
void __vector_2 (void)
{


	TOGGOL_BIT(PORTD,5);
	if(IS_BIT_SET(PORTD,5))
	{
		UART_vidTransmitDataString(SwOnePressed);
		UART_vidTransmitDataString(OnOneStr);
	}
	else
	{
		UART_vidTransmitDataString(SwOnePressed);
		UART_vidTransmitDataString(OffOneStr);
	}

}

//_____________________________________________________________

void External_INTTow_vidPrefIntEnable(void)
{
	SET_BIT(SREG,GI_Enable); //Global Interrupt Enable
	SET_BIT(GICR,INT2_Enable); //Perapheral Interrupt Enable
	CLEAR_BIT(MCUCSR,INT2_Mode); //Interrupt Mode
}


void __vector_3 (void)__attribute__((signal,__INTR_ATTRS)); // Not nessary to write at file.h
void __vector_3 (void)
{


	TOGGOL_BIT(PORTD,6);
	if(IS_BIT_SET(PORTD,6))
	{
		UART_vidTransmitDataString(SwTowPressed);
		UART_vidTransmitDataString(OnTowStr);
	}
	else
	{
		UART_vidTransmitDataString(SwTowPressed);
		UART_vidTransmitDataString(OffTowStr);
	}

}

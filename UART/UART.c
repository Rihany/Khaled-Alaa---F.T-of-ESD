/*
 * UART.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */
#include "../file.h/types.h"
#include "../file.h/registers.h"
#include "../file.h/service.h"

#include "UART.h"


void UART_vidInit(void)
{
	SET_BIT(DDRD,TX); //Tx pin output
	CLEAR_BIT(DDRD,RX);// Rx pin input

	SET_BIT(UCSRB,3); //Tx Enable
	SET_BIT(UCSRB,4); //Rx Enable



	//char size
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);


	UBRRL = myBAUD_RATE;
	UBRRH = 0; //MOST SEGNIFICANT VALUE OF BOUD RATE REGISTER

}

void UART_vidTransmitData(u8 Data)
{
	while(READ_BIT(UCSRA,5)==0);
	UDR=Data;
}

u8 UART_u8ReceiveData(void)
{
	while(READ_BIT(UCSRA,7)==0);
	return UDR;
}

void UART_vidTransmitDataString(u8 arr[])
{
	u8 i =0;
	while(arr[i] != 0)
	{
		UART_vidTransmitData(arr[i]);
		i++;
	}

}

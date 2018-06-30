/*
 * UART.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */

#include "UART_cfg.h"

#ifndef UART_UART_H_
#define UART_UART_H_

#define myBAUD_RATE (freq/16/BAUD_RATE)-1

void UART_vidInit(void);
void UART_vidTransmitData(u8 Data);
u8 UART_u8ReceiveData(void);
void UART_vidTransmitDataString(u8 arr[]);

#endif /* UART_UART_H_ */

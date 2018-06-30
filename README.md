# Khaled-Alaa---F.T-of-ESD
XIOT Filtration Task of Embedded Systems Development Track.

This program and functions built and working on AVR 32 only.
Usualy I prefer to unuse stander libraries, so most of program I use my drivers.

Program prepherals:
1- UART to send serial data
2- ADC to read digital measure temptature form temperature sensor
3- Timer interrupt to send temperature data every 3 second (not nessery to ues timer interrupt to send data in certin time, may uesd while with _delaay function_)

Instraction :
1- XIOT_SwitchIntererruptLED()_function_ can use for just 3 times because AVR 32 have just 3 prepheral interrupts.
2- XIOT_SwitchIntererruptLED(0); _Switch set on PORTD (pin 2) and LED set on PORTD (pin 4)_
3- XIOT_SwitchIntererruptLED(1); _Switch set on PORTD (pin 3) and LED set on PORTD (pin 5)_
4- XIOT_SwitchIntererruptLED(2); _Switch set on PORTB (pin 2) and LED set on PORTD (pin 6)_
5- Tx _set on PORTD (pin 1)_
6- Rx _set on PORTD (pin 0)_
Used Tx & Rx with TTL to USB to send data to any application monitor like (Docklight).

Assumptions:
-> Assume that switches have no bouncing .. normally there is ways to decrease bouncing effect by software but it's not accurate at all, The accurate one is the debouncing switches by hardware.

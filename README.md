# Khaled-Alaa---F.T-of-ESD
XIOT Filtration Task of Embedded Systems Development Internship.

This project and its included functions implement with C language and working on AVR 32 only.

To setup this project you can open it with any IDE work with C and burn hex file to AVR 32 controller. I usually use Eclipse with AVR plug.

Anyway if you have any problem when open project you can make new project on IDE and import this folders and files from home folder:
  1- ADC
  2- file.h
  3- interrupt
  4- timer
  5- UART
  6- main.c


Instraction to setup hardware :
- I use the target function (XIOT_SwitchIntererruptLED() ) 3 times with 3 switches for 3 LEDs - each switch for one LED.
- All switches programed with bullup resister on software, so you must connected it with ground, it is active low.
- All LED's active high.
- XIOT_SwitchIntererruptLED()_function_ can use for just 3 switches because AVR 32 have just 3 external interrupts, And I descriped another way to create more than 3 interrupt switches on ABOUT.md file at point (5).

1- XIOT_SwitchIntererruptLED(0); _Switch set on PORTD (pin 2) and its LED set on PORTD (pin 4)_

2- XIOT_SwitchIntererruptLED(1); _Switch set on PORTD (pin 3) and its LED set on PORTD (pin 5)_

3- XIOT_SwitchIntererruptLED(2); _Switch set on PORTB (pin 2) and its LED set on PORTD (pin 6)_

4- Tx _set on PORTD (pin 1)_

5- Rx _set on PORTD (pin 0)_

Use Tx & Rx with TTL to USB (or another way you comfort with) to send data to any application monitor like (Docklight).


Assumptions :

-> Assume that switches have no bouncing .. normally there is ways to decrease bouncing effect by software but it's not accurate at all, The accurate one is the debouncing switches by hardware.


Issues :

-> May face an inaccurate behavior if you use bouncing switches, but if ues test this project with any simulation application (like :  Proteus) you will not face any problem.

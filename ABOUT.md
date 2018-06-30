XIOT Filtration Task of Embedded Systems Development Internship.

This program and functions built and working on AVR 32 only.

Language of implementation in C language.

Usually I prefer to not use standard libraries, Because of I don't know what is literally include, and it's usually include unused functionalities, and this waste a lot of execution time in run time, so most of program I used my drivers.


Program content:

1- File.h Folder include :

    A- registers.h (this header have all registers of AVR 32 , I Built this by accessing registers addresses) also can use (AVR/io.h) instead of that.
    
    B- service.h (this header have some macros to help in implementaion like SET_Bit & CLEAR_Bit).
    
    C- types.h (this header have some #typedef of data types).
    
    D- uConfig.h (this header to adupt the clock of microcontroler you have).
    
2- UART Driver to send serial data.

3- ADC Driver to read digital measure temperature from temperature sensor.

4- Timer Driver : use timer interrupt to send temperature data every 3 second (not necessary to use timer interrupt to send data in certain time, may use (while function) include (delay function), but timer interrupt more accuret for me, specialy with big program instractions and also because of (delay function) literally paralyzes the program for (delay time) plus excution time of other instructions ).

5- Interrupt Folder to accessing external interrupts.(AVR 32 have only 3 external interrupt so we can access only 3 switches)

-> If we need to do alot of interrupt switches, we can make it through RTOS, like create tasks to turn LEDs ON or OFF, and make events of this tasks are the switches we need.

6- main.c , this is the main code , calling thier the functions needed for implementation and implement the funciton of task(XIOT_SwitchIntererruptLED() ), and use it in main function for 3 times to access 3 switches and 3 LEDs.


Expriance :

-> Language and framwork expriance : I implement with C on AVR for many projects ,also woke on many internal or external prepherals, such as:
    Timers , ADC , UART , SPI , I2C , EEPROM , WIFI Module , LCD , Keybad and many sensors.

-> One of my projects is Master Slave Robotic Arms :
        A combination between master and slave robotic arms (4DOF) as master arm makes some movements with encoders by the help of a technician and sends them through WIFI to teach slave arms which have 4 servo motor. The slave arm, which is learning, follows these movements and saves them in external EEPROM in order to make them again, this scenario can be handled by mobile GUI through wifi.

-> And there are another projects mention in my CV.


- I'm very happy with this task, It's make my get brainstorming and good training of work around to get job done.

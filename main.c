// main.c
// Runs on LM4F120/TM4C123
// MODIFIED LAB 11
// Testing Jetson TK1 & TM4C Serial Port Connection
// May 4, 2016
// Modified Baud 115200 to 57600, more info at:
// http://stackoverflow.com/questions/25230535/libserial-error-cannot-set-baud-rate-as-115200

// this connection occurs in the USB debugging cable
// U0Rx (PA0) connected to serial port on PC
// U0Tx (PA1) connected to serial port on PC
// Ground connected ground in the USB cable

// Jetson TK1 sends the char 'j' all the time. If TM4C gets the input correctly
// it will light up its PF3 (built in green light)

#include "UART.h"
#include "TExaS.h"
#include "tm4c123gh6pm.h"

void EnableInterrupts(void);  // Enable interrupts

void PORTF_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTF_AMSEL_R &= ~0x08;      // 3) disable analog on PF3
  GPIO_PORTF_PCTL_R &= ~0x0000F000; // 4) PCTL GPIO on PF3
  GPIO_PORTF_DIR_R |= 0x08;         // 5) PF3 out
  GPIO_PORTF_AFSEL_R &= ~0x08;      // 6) disable alt funct on PF3
  GPIO_PORTF_DEN_R |= 0x08;         // 7) enable digital I/O on PF3
}

int main(void)
{ 
  TExaS_Init();             // initialize grader, set system clock to 80 MHz
  UART_Init();              // initialize UART
  EnableInterrupts();       // needed for TExaS
	PORTF_Init();
	
	GPIO_PORTF_DATA_R = 0x00; // turn off lights
	
  while(1)
	{
		unsigned char input;
		input = UART_InChar();
		if (input=='j')
		{
			GPIO_PORTF_DATA_R |= 0x08;
		}
  }
}


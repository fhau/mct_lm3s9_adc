/* *********************************************
   File:        main.c
	 Title:       communicate through UART
	 Purpose:     LM3S9D96-DK
	              communicate through RS232
	 Business:    HSA Elektrotechnik
	 Compiler:    MDK-ARM
	 Author/Date: Franz Haunstetter / 09.09.13
	 Comment:     new
	 Author/Date: Franz Haunstetter / 14.09.13
	 Comment:     User button polling
	 Author/Date: Franz Haunstetter / 16.09.13
	 Comment:     RS232 serial in- and output
	 Author/Date: Franz Haunstetter / 21.09.13
	 Comment:     analog input
   *********************************************
*/

/* includes */
#include <lm3s9d96.h>		// hardware register names
#include <labex.h>

/* private macros */

/* private function prototypes */
void init(void);						// initialize.c
void init_sys(void);				// system.c
void SysTickRun(void);
void SysTickISR(void);
void init_rs232(void);			// rs232.c
void init_IO(void);					// GPIO.c
int init_ADC(void);					// ADC.c

/* global buffers */
char c[TXTBUFL];						// single line
int r_c = 0;								// read index
int w_c = 0;								// write index

int main()
{
	volatile unsigned long ulIOBits = 0;
	
	//
	// Initialize all device ressources.
	//
	init_sys();
	init_rs232();
	init_IO();
	init_ADC();
	
	//
	// Run the timer at once with interrupts.
	//
	SysTickRun();

	//
	// Run the action in a superloop.
	//
	for(;;)
	{
		//
		// Reflect the button's state on second LED with every change.
		//
		if ((GPIO_PORTJ_DATA_R & BIT(7)) != (ulIOBits & BIT(7)))
		{
			if ((GPIO_PORTJ_DATA_R & BIT(7)) == 0)
				GPIO_PORTF_DATA_R &= ~BIT(2);
			else
				GPIO_PORTF_DATA_R |= BIT(2);
			
			ulIOBits = GPIO_PORTJ_DATA_R;
		}
	}
}

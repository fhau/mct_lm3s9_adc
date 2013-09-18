/* *********************************************
   File:        ADC.c
	 Title:       ADC0 driver
	 Purpose:     LM3S9D96-DK
	              resd the ADC0 supplied with the board
	 Business:    HSA Elektrotechnik
	 Compiler:    MDK-ARM
	 Author/Date: Franz Haunstetter / 18.09.13
	 Comment:     new
   *********************************************
*/

/* includes */
#include <lm3s9d96.h>		// hardware register and bit names

/* private macros */
#define BIT(n)		(1 << n)

/* private function prototypes */

/* global variables and buffers */


int init_ADC()
{
	//
	// Return 0 on errors, or something else if successful.
	// Returning as void is also possible.
	//
	return 1;
}

//
// Place driver capability and shutdown routines here.
//

//
// Place interrupt service routines here.
// Import their names into the Interrupt Vector Table, in Startup.s
//
void ADC_ISR()
{
}

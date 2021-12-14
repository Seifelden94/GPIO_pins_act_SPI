	#include"GPIO.h"


/// the following 4 function do nothing.  just to make sure not to give me an error when I try to retest it
void SetGPIOdirection(unsigned char port, unsigned char mask )
{}
unsigned char GetGPIOportValues(unsigned char port )
{

   return 1;
}
void SetGPIOportValues(unsigned char port, unsigned char mask )
{
	}
unsigned long GetPeripheralTime( void )
{

  return 1;
}


///

	void GPIO_init(void)
	 {
	  // Initialize the pins as input or output
	  SetGPIOdirection(PORTA_ADDRESS,PORTA_MODE);

	  SetGPIOdirection(PORTB_ADDRESS,PORTB_MODE);

	  ///could assign initial values for the output pins too
	 }






	void digital_output_assign(uint16_t *data_recived)
	 {

	  //digital 1,2,3 portA
	  ASSIGN_PIN(PORTA_ADDRESS,D_OUT1_PIN,((*data_recived)&(1<<BUTTON_1_OFFSET)));// get BUtton 1 status then output it to digital_1_output pin
      ASSIGN_PIN(PORTA_ADDRESS,D_OUT2_PIN,((*data_recived)&(1<<BUTTON_2_OFFSET)));// get BUtton 2 status then output it to digital_2_output pin
	  ASSIGN_PIN(PORTA_ADDRESS,D_OUT3_PIN,((*data_recived)&(1<<BUTTON_3_OFFSET)));// get BUtton 2 status then output it to digital_3_output pin


	  //digital 4,5,6 portB
	  ASSIGN_PIN(PORTB_ADDRESS,D_OUT4_PIN,((*data_recived)&(1<<BUTTON_4_OFFSET)));// get BUtton 4 status then output it to digital_4_output pin
	  ASSIGN_PIN(PORTB_ADDRESS,D_OUT5_PIN,((*data_recived)&(1<<BUTTON_5_OFFSET)));// get BUtton 5 status then output it to digital_5_output pin
	  ASSIGN_PIN(PORTB_ADDRESS,D_OUT6_PIN,((*data_recived)&(1<<BUTTON_6_OFFSET)));//get BUtton 6 status then output it to digital_6_output pin

	 }


	#ifndef GPIO_H_
	#define GPIO_H_
	#include"stdint.h"






    #define   INPUT_MODE                 0
	#define   OUTPUT_MODE                1

	/// PORTA,  0 to use pin as input and one to use as output

	#define PORTA_ADDRESS               0x8f

	//Digital Output1
	#define PORTA0_MODE               OUTPUT_MODE
	//Controller SPI Clock
	#define PORTA1_MODE               OUTPUT_MODE
	//Digital Output2
    #define PORTA2_MODE               OUTPUT_MODE
	//Controller SPI Data Output
	#define PORTA3_MODE               OUTPUT_MODE
	//Controller SPI Data Input
	#define PORTA4_MODE               INPUT_MODE
	//INT1 input from external ADC
	#define PORTA5_MODE               INPUT_MODE
	//External NVRAM device SPI chip select
	#define PORTA6_MODE               OUTPUT_MODE
	//Digital Output3
    #define PORTA7_MODE               OUTPUT_MODE


    // I will write the PORTA_MODE to GPIOdirection portA to declare the pins in port A as input or output
	#define PORTA_MODE        ((PORTA0_MODE<<0)|(PORTA1_MODE<<1)|(PORTA2_MODE<<2)|(PORTA3_MODE<<3)|(PORTA4_MODE<<4)|(PORTA5_MODE<<5)|(PORTA6_MODE<<6)|(PORTA7_MODE<<7))



	// PORTB p 0 to use pin as input and one to use as output

	#define PORTB_ADDRESS               0x9f

	// Digital Intput1
	#define PORTB0_MODE                INPUT_MODE
	//External LCD device SPI chip select
	#define PORTB1_MODE                OUTPUT_MODE

	//Digital Output4
	#define PORTB2_MODE                OUTPUT_MODE
	//I2C clock
    #define PORTB3_MODE                OUTPUT_MODE
	//I2C data
    #define PORTB4_MODE                OUTPUT_MODE
	//Digital Output5
	#define PORTB5_MODE                OUTPUT_MODE
	//External target device SPI chip select
	#define PORTB6_MODE                OUTPUT_MODE
	//Digital Output6
	#define PORTB7_MODE                OUTPUT_MODE

    // I will write the PORTB_MODE to GPIOdirection portB to declare the pins in port B as input or output
	#define PORTB_MODE             ((PORTB0_MODE<<0)|(PORTB1_MODE<<1)|(PORTB2_MODE<<2)|(PORTB3_MODE<<3)|(PORTB4_MODE<<4)|(PORTB5_MODE<<5)|(PORTB6_MODE<<6)|(PORTB7_MODE<<7))

	// digital output port A pin number

	#define D_OUT1_PIN                  0

	#define D_OUT2_PIN                  2

	#define D_OUT3_PIN                  7

	#define D_1_2_3_mask                10000101
    // digital pin number output port B

   #define D_OUT4_PIN                   2
   #define D_OUT5_PIN                   5
   #define D_OUT6_PIN                   7

   // bit number of the Button in the target device register

   #define BUTTON_1_OFFSET              0
   #define BUTTON_2_OFFSET              2
   #define BUTTON_3_OFFSET              3
   #define BUTTON_4_OFFSET              4
   #define BUTTON_5_OFFSET              5
   #define BUTTON_6_OFFSET              6


	//// giving functions
	void SetGPIOdirection(unsigned char port, unsigned char mask );
	unsigned char GetGPIOportValues(unsigned char port );
	void SetGPIOportValues(unsigned char port, unsigned char mask );
	unsigned long GetPeripheralTime( void );
	//
	void GPIO_init(void);
	void digital_output_assign(uint16_t *data_recived);

	// macro functions, usually I directly access the registers with the macro,
	//ex #define ASSIGN_BIT(port_name,bit_number,value)    port_name= (port_name&(~(1<<bit_number))) |(value<<bit_number)

	// assume that reading the input pin give 0
	// assign value of 0 or 1, to a pin in a port
	#define ASSIGN_PIN(PORT_ADDRESS,PIN_NUMBER,VALUE) (SetGPIOportValues(PORT_ADDRESS,((GetGPIOportValues(PORT_ADDRESS)&(~(1<<PIN_NUMBER)))|(VALUE<<PIN_NUMBER)   ) ))

    // set a specific pin in a sport
	#define SET_PIN(PORT_ADDRESS,PIN_NUMBER) 	(SetGPIOportValues(PORT_ADDRESS,(GetGPIOportValues(PORT_ADDRESS)|(1<<PIN_NUMBER))) )
	//clear specific pin in a port
	#define CLEAR_PIN(PORT_ADDRESS,PIN_NUMBER) 	(SetGPIOportValues( PORT_ADDRESS,( GetGPIOportValues(PORT_ADDRESS)&(~(1<<PIN_NUMBER)) ) ))
	// get the value of a pin in a port
	#define GET_PIN(PORT_ADDRESS,PIN_NUMBER)  (GetGPIOportValues(PORT_ADDRESS)|(1<<PIN_NUMBER))

	//

   #endif

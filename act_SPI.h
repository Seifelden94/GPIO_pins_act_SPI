	#ifndef act_SPI_H_
	#define act_SPI_H_
	#include "GPIO.h"
	#include "stdint.h"

	/// SPI PINS

  	#define   SPI_ClOCK_PORT       PORTA_ADDRESS
	#define   SPI_CLOCK_PIN         1
	#define   SPI_CLOCK_PERIOD_MICRO      4   //1/F


	#define   SPI_Data_OUTPUT_PORT       PORTA_ADDRESS
	#define   SPI_Data_OUTPUT_PIN         3

	#define   SPI_Data_INPUT_PORT       PORTA_ADDRESS
	#define   SPI_Data_INPUT_PIN         4

	#define   SPI_NVRAM_SELECT_PORT       PORTA_ADDRESS
	#define   SPI_NVRAM_SELECT_PIN         5

	#define   SPI_LCD_SELECT_PORT       PORTB_ADDRESS
	#define   SPI_LCD_SELECT_PIN         1

	#define   SPI_TARGET_SELECT_PORT       PORTB_ADDRESS
	#define   SPI_TARGET_SELECT_PIN        6









	/// functions Prototype
	unsigned long GetPeripheralTime( void );

	void SPI_init(void);
	void delay_micro_second(int micro_second);
	void delay_micro_second_from(int micro_second,unsigned long time_from);
	void delay_milli_second(int milli_second);
	void spi_send_recive(unsigned char*data_to_send,uint16_t* data_to_recive);












#endif

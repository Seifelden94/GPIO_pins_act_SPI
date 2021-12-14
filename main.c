

	#include <stdint.h>
	#include"act_SPI.h"
	#include"GPIO.h"



    int main(void)
	{
	 GPIO_init();
     SPI_init();

    unsigned char data_send=7;
    uint16_t  data_recived;

    while(1)
    {

      // send the register number of  the target device, and receive its 16 bits value
      spi_send_recive(&data_send,&data_recived);
      // output the Button status to the digital output pins
      digital_output_assign(&data_recived);

    }

    return 0;
    }

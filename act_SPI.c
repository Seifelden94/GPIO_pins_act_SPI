#include"act_SPI.h"



    /*
     * Data is sampled on the rising edge of the clock without delay.
     *
     *The SPI clock idles in the High state
     *
     *all SPI bus peripheral chip selections are active in the Low state.
     *
     *SPI data communication is most significant bit first.
     *
     *  The maximum SPI clock for the target device is 400 kHz.
     *  my smallest time unit is micro second. have two choice
      *High time =low time=2 MS      T=2+2=4 MS fclock =250KHz
     *
     */
     /*
      * The target device then requires a one millisecond delay before the register data contents can be transferred.
      * the  recived register contains a number of milliseconds to wait before communicating with the target device again.
      */

	void SPI_init(void)
	 {

	   // clock is normally High
	   SET_PIN(SPI_ClOCK_PORT,SPI_CLOCK_PIN);

	   //slaves active low so I make it initially non active
	   SET_PIN(SPI_NVRAM_SELECT_PORT,SPI_NVRAM_SELECT_PIN );

	   //slaves active low so I make it initially non active
	   SET_PIN(SPI_LCD_SELECT_PORT,SPI_LCD_SELECT_PIN  );

	   //slaves active low so I make it initially non active
	   SET_PIN(SPI_TARGET_SELECT_PORT,SPI_TARGET_SELECT_PIN );

	 }



	void delay_micro_second(int micro_second)
	{
	  unsigned long count_to_reach=GetPeripheralTime()+micro_second;

	  // wait until the desired delay pass;
	  while(GetPeripheralTime()<count_to_reach);

	}



	void delay_milli_second(int milli_second)
	{

	  // milli_second*1000 to transfer the desired number of milliseconds to micro
	  unsigned long count_to_reach=GetPeripheralTime()+milli_second*1000;

	  // wait until the desired delay pass
	  while(GetPeripheralTime()<count_to_reach);

	}





   //////////
   void spi_send_recive(unsigned char*data_to_send,uint16_t* data_to_recive)
    {
	  // first time do not wait to communcate with the target device
	  static unsigned long count_to_reach_before_rsend=0;
      int msecond_before_resend;

      // the time to wait before start re communicate with the target device. first time do not wait;
      while(GetPeripheralTime()<count_to_reach_before_rsend);

      /// send 8 bits to the target

      //  chose the target device slave, by making it low
     CLEAR_PIN(SPI_TARGET_SELECT_PORT ,SPI_TARGET_SELECT_PIN);

     // send 8 bits
     for(int i=7;i>=0;i--)
      {

       // clock low
      CLEAR_PIN(SPI_ClOCK_PORT,SPI_CLOCK_PIN);

  	  //put the value of bit number i to be send start with the most significant bit
      ASSIGN_PIN(SPI_Data_OUTPUT_PORT,SPI_Data_OUTPUT_PIN,(*data_to_send)&(1<<i));

      // wait two micro seconds
      delay_micro_second(SPI_CLOCK_PERIOD_MICRO/2);

      //rise the clock, clock high
      SET_PIN(SPI_ClOCK_PORT,SPI_CLOCK_PIN);

      delay_micro_second(SPI_CLOCK_PERIOD_MICRO/2);

     }

     // delay 1 millisec until the target device ready to send the content of the register
     delay_milli_second(1);

    // Receive 16 bits from target



     for(int i=15;i>=0;i--)
      {
       //clock fall,clock become low
   	   CLEAR_PIN(SPI_ClOCK_PORT,SPI_CLOCK_PIN);

       //wait two micro seconds in low mode
  	   delay_micro_second(SPI_CLOCK_PERIOD_MICRO/2);

       //clock rise, clock become  high
       SET_PIN(SPI_ClOCK_PORT,SPI_CLOCK_PIN);

       // data will be ready at the rising edge without delay
   	   // erase the corresponding bit then add the newly receved value. i CAN INTIALISE *data_to_recive with 0 instead of clearing the desired bit every time
  	   *data_to_recive=(*data_to_recive&(~(1<<i)))|(GET_PIN(SPI_Data_INPUT_PORT,SPI_Data_INPUT_PIN)<<i);

  	   delay_micro_second(SPI_CLOCK_PERIOD_MICRO/2);
  	   }

  	  // read the time in millisecond to waits before trying to communicate again via SPI with the target device it is avalabile in the last 9 bits
      msecond_before_resend=(*data_to_recive)|(0x1ff<<6);

      // store the value that the timer counter had to pass before recommunicat with the target device
      //  it was going to be more efficient to use timer interrupt if available
      count_to_reach_before_rsend= GetPeripheralTime()+msecond_before_resend*1000;

      //slaves active low so I make it non active by  making it high
  	  SET_PIN(SPI_TARGET_SELECT_PORT,SPI_TARGET_SELECT_PIN );

   }



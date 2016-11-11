//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																											//
//     										Project     : FreeRTOS-lwIP-IoT 								//
//											  Version     : Driver 01.01 									//
//    										   Date/Time   : 2016-10-15 									//
//																											//
//													  Created by:											//
//								LEONARDO WINTER PEREIRA (leonardowinterpereira@gmail.com)					//
//											  LUCAS ZIMMERMANN CORDEIRO										//
//																											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*************************************************************************************************************
 * 												DEPENDENCIAS												 *
 ************************************************************************************************************/

#include "includes.h"

/*************************************************************************************************************
* 											CONSTANTES E MACROS												 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 										DEFINICOES DE TIPOS E ESTRUTURAS									 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 										  PROTOTIPOS DE FUNCOES LOCAIS										 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 												VARIAVEIS EXTERNAVEIS										 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 												  VARIAVEIS GLOBAIS											 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 										DEFINICOES DE FUNCOES EXTERNAVEIS									 *
 ************************************************************************************************************/

int main(void)
{
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  // Disable the MPU
  MPU_BWR_CESR_VLD(MPU, 0);

  // Initialize the hardware
  hardware_init();

  printf("APS!\r\nDesenvolvida por:\r\nLeonardo Winter Pereira\r\nLucas Zimmermann Cordeiro\r\n");

  // Creates the LwIP task
  if (xTaskCreate (
    		LwipInitTask,  // task function
			"LwipInitTask", // task name for kernel awareness
			configMINIMAL_STACK_SIZE * 4, // task stack size
			(void*)NULL, // optional task startup argument
			tskIDLE_PRIORITY,  // initial priority
			(xTaskHandle*)NULL // task handle
    ) != pdPASS)
    {
  	  for( ; ; ) { } // error! probably out of memory
    }

  // Creates the LwIP task
  if (xTaskCreate (
		SDCardInitTask,  // task function
		"SDCardInitTask", // task name for kernel awareness
		configMINIMAL_STACK_SIZE * 4, // task stack size
		(void*)NULL, // optional task startup argument
		tskIDLE_PRIORITY,  // initial priority
		(xTaskHandle*)NULL // task handle
	  ) != pdPASS)
  {
	  for( ; ; ) { } // error! probably out of memory
  }

  // Start FreeRTOS scheduler, does usually not return!
  vTaskStartScheduler();

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  // Startup of the selected RTOS. Macro is defined by the RTOS component.
  #endif

/*** End of RTOS startup code.  ***/
  for(;;){}
  /*** End of main routine. DON'T WRITE CODE BELOW!!! ***/
}


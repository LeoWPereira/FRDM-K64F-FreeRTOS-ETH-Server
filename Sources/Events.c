/* ###################################################################
**     Filename    : Events.c
**     Project     : FreeRTOS-lwIP-IoT
**     Processor   : MK64FN1M0VLL12
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-15, 00:52, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

static volatile bool cardInserted = false; /* Flag to indicate a card has been inserted */

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationStackOverflowHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         if enabled, this hook will be called in case of a stack
**         overflow.
**     Parameters  :
**         NAME            - DESCRIPTION
**         pxTask          - Task handle
**       * pcTaskName      - Pointer to task name
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
  /* This will get called if a stack overflow is detected during the context
     switch.  Set configCHECK_FOR_STACK_OVERFLOWS to 2 to also check for stack
     problems within nested interrupts, but only do this for debug purposes as
     it will increase the context switch time. */
  (void)pxTask;
  (void)pcTaskName;
  taskDISABLE_INTERRUPTS();
  /* Write your code here ... */
  for(;;) {}
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationTickHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called by the RTOS for every
**         tick increment.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationTickHook(void)
{
  /* Called for every RTOS tick. */
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationIdleHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, this hook will be called when the RTOS is idle.
**         This might be a good place to go into low power mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationIdleHook(void)
{
  /* Called whenever the RTOS is idle (from the IDLE task).
     Here would be a good place to put the CPU into low power mode. */
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  FRTOS1_vApplicationMallocFailedHook (module Events)
**
**     Component   :  FRTOS1 [FreeRTOS]
**     Description :
**         If enabled, the RTOS will call this hook in case memory
**         allocation failed.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FRTOS1_vApplicationMallocFailedHook(void)
{
  /* Called if a call to pvPortMalloc() fails because there is insufficient
     free memory available in the FreeRTOS heap.  pvPortMalloc() is called
     internally by FreeRTOS API functions that create tasks, queues, software
     timers, and semaphores.  The size of the FreeRTOS heap is set by the
     configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
  taskDISABLE_INTERRUPTS();
  /* Write your code here ... */
  for(;;) {}
}

/*
** ===================================================================
**     Callback    : fsl_sdhc1_OnCardDetect0
**     Description : This callback function is called when card is
**     inserted or removed.
**     Parameters  :
**       inserted - Specifies if card was inserted or removed.
**     Returns : Nothing
** ===================================================================
*/
void fsl_sdhc1_OnCardDetect0(bool inserted)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Callback    : fsl_sdhc1_OnCardInterrupt0
**     Description : This callback function is called when card
**     interrupt occurs.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void fsl_sdhc1_OnCardInterrupt0(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Callback    : fsl_sdhc1_OnCardBlockGap0
**     Description : This callback function is called when card block
**     gap occurs.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void fsl_sdhc1_OnCardBlockGap0(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Interrupt handler : PORTE_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTE_IRQHandler(void)
{
	if(PORT_HAL_GetPortIntFlag(PORTE_BASE_PTR) == (1<<SD_CARD_DETECT))
	{
		check_card_inserted();
	}

	PORT_HAL_ClearPortIntFlag(PORTE_BASE_PTR);
}

/*
** ===================================================================
**     check_card_inserted
**
**     Description :
**
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void check_card_inserted(void)
{
    uint32_t state = GPIO_DRV_ReadPinInput(SD_CARD_DETECT);
    uint32_t matchState = -1;

    // Debounce input
    do
    {
        for (int i = 0; i < 0x1FFFFF; i++)
        {
            __asm("nop");
        }
        matchState = state;
        state = GPIO_DRV_ReadPinInput(SD_CARD_DETECT);
    }
    while (state != matchState);

    // Set card state
    cardInserted = (state == 1);

    fsl_sdhc1_OnCardDetect0(cardInserted);
}

/*
** ===================================================================
**     wait_for_card
**
**     Description :
**
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void wait_for_card(void)
{
	while ((!cardInserted))
	{
		GPIO_DRV_TogglePinOutput(LEDRGB_BLUE); // toggle red LED

		vTaskDelay(150/portTICK_RATE_MS); // wait for 150 ms
	}
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

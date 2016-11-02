/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "gpio1.h"
#include "FRTOS1.h"
#include "KSDK1.h"
#include "UTIL1.h"
#include "eNet1.h"
#include "WAIT1.h"
#include "TMOUT1.h"
#include "CS1.h"
#include "memoryCard1.h"
#include "fsl_sdhc1.h"

#ifdef __cplusplus
extern "C" {
#endif 


void FRTOS1_vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName);
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

void FRTOS1_vApplicationTickHook(void);
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

void FRTOS1_vApplicationIdleHook(void);
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

void FRTOS1_vApplicationMallocFailedHook(void);
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
void fsl_sdhc1_OnCardDetect0(bool inserted);

/*
** ===================================================================
**     Callback    : fsl_sdhc1_OnCardInterrupt0
**     Description : This callback function is called when card
**     interrupt occurs.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void fsl_sdhc1_OnCardInterrupt0(void);

/*
** ===================================================================
**     Callback    : fsl_sdhc1_OnCardBlockGap0
**     Description : This callback function is called when card block
**     gap occurs.
**     Parameters  : None
**     Returns : Nothing
** ===================================================================
*/
void fsl_sdhc1_OnCardBlockGap0(void);

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
void PORTE_IRQHandler(void);

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
void check_card_inserted(void);

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
void wait_for_card(void);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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

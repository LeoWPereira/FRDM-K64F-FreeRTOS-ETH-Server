/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : fsl_sdhc1.h
**     Project     : FreeRTOS-lwIP-IoT
**     Processor   : MK64FN1M0VLL12
**     Component   : fsl_sdhc
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-02, 18:48, # CodeGen: 19
**     Contents    :
**         SDHC_DRV_Init                 - sdhc_status_t SDHC_DRV_Init(uint32_t instance,sdhc_host_t * host,const...
**         SDHC_DRV_Shutdown             - sdhc_status_t SDHC_DRV_Shutdown(uint32_t instance);
**         SDHC_DRV_DetectCard           - sdhc_status_t SDHC_DRV_DetectCard(uint32_t instance);
**         SDHC_DRV_ConfigClock          - sdhc_status_t SDHC_DRV_ConfigClock(uint32_t instance,uint32_t clock);
**         SDHC_DRV_SetBusWidth          - sdhc_status_t SDHC_DRV_SetBusWidth(uint32_t instance,sdhc_buswidth_t busWidth);
**         SDHC_DRV_IssueRequestBlocking - sdhc_status_t SDHC_DRV_IssueRequestBlocking(uint32_t instance,sdhc_request_t...
**         SDHC_DRV_DoIrq                - void SDHC_DRV_DoIrq(uint32_t instance);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file fsl_sdhc1.h
** @version 01.00
*/         
/*!
**  @addtogroup fsl_sdhc1_module fsl_sdhc1 module documentation
**  @{
*/         
#ifndef __fsl_sdhc1_H
#define __fsl_sdhc1_H
/* MODULE fsl_sdhc1. */

/* Include inherited beans */
#include "clockMan1.h"
#include "osa1.h"
#include "Cpu.h"

/*! @brief Device instance number */
#define fsl_sdhc1_IDX SDHC_IDX
/*! @brief Device instance number for backward compatibility */
#define FSL_FSL_SDHC1 fsl_sdhc1_IDX

/*! @brief Driver state structure which holds driver runtime data */
extern sdhc_host_t fsl_sdhc1_host;
  
/*! @brief Interrupt service routine used by the component driver */
void fsl_sdhc1_IRQHandler(void);
  
/*! @brief Basic Configuration declaration */
extern const sdhc_user_config_t fsl_sdhc1_InitConfig0;
    

/*! @brief fsl_sdhc1 callbacks declaration */
extern void fsl_sdhc1_OnCardDetect0(bool inserted);

extern void fsl_sdhc1_OnCardInterrupt0(void);

extern void fsl_sdhc1_OnCardBlockGap0(void);
#endif
/* ifndef __fsl_sdhc1_H */
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

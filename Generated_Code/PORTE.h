/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PORTE.h
**     Project     : FreeRTOS-lwIP-IoT
**     Processor   : MK64FN1M0VLL12
**     Component   : Init_PORT
**     Version     : Component 01.006, Driver 01.06, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-02, 18:48, # CodeGen: 19
**     Abstract    :
**          This file implements the PORT (PORTE) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PORTE
**          Device                                         : PORTE
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Pin 0                                        : Initialize
**              Mux control                                : <Automatic>
**              Open drain                                 : <Automatic>
**              Pull resistor                              : Enabled
**              Pull selection                             : Pull Up
**              Slew rate                                  : Fast
**              Drive strength                             : High
**              Interrupt/DMA request                      : <Automatic>
**              Passive filter                             : <Automatic>
**              Lock                                       : <Automatic>
**            Pin 1                                        : Do not initialize
**            Pin 2                                        : Do not initialize
**            Pin 3                                        : Do not initialize
**            Pin 4                                        : Do not initialize
**            Pin 5                                        : Do not initialize
**            Pin 6                                        : Do not initialize
**            Pin 24                                       : Do not initialize
**            Pin 25                                       : Do not initialize
**            Pin 26                                       : Do not initialize
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTE
**              Interrupt request                          : <Automatic>
**              Interrupt priority                         : <Automatic>
**              ISR Name                                   : 
**          Initialization                                 : 
**            Call Init method                             : yes
**            Utilize after reset values                   : default
**     Contents    :
**         Init - void PORTE_Init(void);
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
** @file PORTE.h
** @version 01.06
** @brief
**          This file implements the PORT (PORTE) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup PORTE_module PORTE module documentation
**  @{
*/         

#ifndef PORTE_H_
#define PORTE_H_

/* MODULE PORTE. */

#include "PORTE_Init.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Initialization method user name */
#define PORTE_Init PORTE_Init
/* PDD macros peripheral base address parameter */
#define PORTE_DEVICE PORTE_BASE_PTR

#ifdef __cplusplus
}
#endif

/* END PORTE. */
#endif /* #ifndef __PORTE_H_ */
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



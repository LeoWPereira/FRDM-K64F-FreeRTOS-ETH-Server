/** ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : FreeRTOS-lwIP-IoT
**     Processor   : MK64FN1M0VLL12
**     Component   : MK64FN1M0LL12_4SDK
**     Version     : Component 1.2.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Datasheet   : K64P144M120SF5RM, Rev.2, January 2014
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-02, 19:50, # CodeGen: 22
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         SystemInit            - void SystemInit(void);
**         SystemCoreClockUpdate - void SystemCoreClockUpdate(void);
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
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
** @file Cpu.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

/* {Default RTOS Adapter} No RTOS includes */
#include "Cpu.h"
#include "Events.h"


#ifdef __cplusplus
extern "C" {
#endif

/*
** ===================================================================
**     Method      :  Common_Init (component MK64FN1M0LL12_4SDK)
**     Description :
**         Initialization of registers for that there is no 
**         initialization component.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#if CPU_COMMON_INIT
void Common_Init(void)
{
  /* This function contains initialization code which is not part of initialization 
     methods of peripheral initialization (Init) components used in the project.  
     This function is generated depending on Init components present 
     in the project. To remove initialization of a register from the Common_Init() 
     add Init component that includes initialization of this register.
     This function is also affected by after reset value optimization property 
     available in Component view\Generator_Configurations\Active configuration\
     Optimizations\Utilize after reset values. */
  /* SIM_SCGC5: PORTE=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
  /* SIM_SCGC7: MPU=1 */
  SIM_SCGC7 |= SIM_SCGC7_MPU_MASK;
  /* NVICIP63: PRI63=0 */
  NVICIP63 = NVIC_IP_PRI63(0x00);
}

#endif /* CPU_COMMON_INIT */
/*
** ===================================================================
**     Method      :  Components_Init (component MK64FN1M0LL12_4SDK)
**     Description :
**         Initialization of components (with exception for Peripheral
**         Initialization Components which are initialized in 
**         Peripherals_Init() method).
**         For example, if automatic initialization feature 
**         is enabled in LDD component then its Init method call 
**         is executed in Components_Init() method.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#if CPU_COMPONENTS_INIT
void Components_Init(void)
{

  /*! gpio1 Auto initialization start */
  GPIO_DRV_Init(gpio1_InpConfig0,gpio1_OutConfig0);
  /*! gpio1 Auto initialization end */
  
  /* ### KinetisSDK "KSDK1" init code ... */
  /* Write code here ... */
  /* ### FreeRTOS "FRTOS1" init code ... */
#if configSYSTICK_USE_LOW_POWER_TIMER
  /* enable clocking for low power timer, otherwise vPortStopTickTimer() will crash */
  SIM_PDD_SetClockGate(SIM_BASE_PTR, SIM_PDD_CLOCK_GATE_LPTMR0, PDD_ENABLE);
#endif
  vPortStopTickTimer(); /* tick timer shall not run until the RTOS scheduler is started */
  /* ### CriticalSection "CS1" init code ... */
  /* ### Timeout "TMOUT1" init code ... */
  TMOUT1_Init();
  /*! fsl_sdhc1 Auto initialization start */
  OSA_InstallIntHandler(SDHC_IRQn, fsl_sdhc1_IRQHandler);
  SDHC_DRV_Init(fsl_sdhc1_IDX, &fsl_sdhc1_host, &fsl_sdhc1_InitConfig0);
  /*! fsl_sdhc1 Auto initialization end */
  

}
#endif /* CPU_COMPONENTS_INIT */


#ifdef __cplusplus
}
#endif

/* END Cpu. */


IMPORTANT GUIDES

https://mcuoneclipse.com/2014/11/08/tutorial-freertos-with-the-kinetis-sdk-and-processor-expert/

https://mcuoneclipse.com/2015/10/28/tutorial-lwip-with-the-freertos-and-the-freescale-frdm-k64f-board/

https://mcuoneclipse.com/2014/05/26/tutorial-data-logger-with-the-frdm-k64f-board/

https://community.nxp.com/docs/DOC-275614                        <---- THIS IS A GOOD ONE


HELPFUL LINKS AND PROBLEM SOLVING

I'm trying to work out if there is a problem with my understanding or with the IAR Cortex M3 port.c file.

I've just upgraded to FreeRTOS 7.5.0 and enabled the configASSERT() macro. It  showed that I had a few problems.

I fixed the first one in vPortValidateInterruptPriority( ) by making sure that I called     NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); before calling NVIC_Init(&NVIC_InitStructure);. If you dig deep into the STM32 Standard Peripheral library docs it does say to do this but I didn't notice. If you don't do this then NVIC_Init sets the interrupt priority to zero - causing configASSERT( ucCurrentPriority >= ucMaxSysCallPriority ); to fail.

Also, for this problem, i've disabled, in portmacro.h, this piece of code:

#ifdef configASSERT
#if configCPU_FAMILY_IS_ARM_M4_M7(configCPU_FAMILY) /* ARM M4/M7(F) core */
  void vPortValidateInterruptPriority( void );
  #define portASSERT_IF_INTERRUPT_PRIORITY_INVALID() 	vPortValidateInterruptPriority()
#else
  #define portASSERT_IF_INTERRUPT_PRIORITY_INVALID()
#endif
#endif
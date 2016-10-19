/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : eNet1.h
**     Project     : FreeRTOS-lwIP-IoT
**     Processor   : MK64FN1M0VLL12
**     Component   : fsl_enet
**     Version     : Component 1.3.0, Driver 01.00, CPU db: 3.00.000
**     Repository  : KSDK 1.3.0
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-10-17, 21:50, # CodeGen: 6
**     Contents    :
**         ENET_DRV_1588Init               - enet_status_t ENET_DRV_1588Init(enet_dev_if_t *...
**         ENET_DRV_1588Deinit             - enet_status_t ENET_DRV_1588Deinit(enet_dev_if_t * enetIfPtr);
**         ENET_DRV_Start1588Timer         - enet_status_t ENET_DRV_Start1588Timer(uint32_t instance,bool isSlaveEnabled);
**         ENET_DRV_Stop1588Timer          - void ENET_DRV_Stop1588Timer(uint32_t instance);
**         ENET_DRV_Parse1588Packet        - enet_status_t ENET_DRV_Parse1588Packet(uint8_t *...
**         ENET_DRV_Get1588timer           - enet_status_t ENET_DRV_Get1588timer(enet_mac_ptp_time_t * ptpTimerPtr);
**         ENET_DRV_Set1588timer           - enet_status_t ENET_DRV_Set1588timer(enet_mac_ptp_time_t * ptpTimerPtr);
**         ENET_DRV_Adjust1588timer        - enet_status_t ENET_DRV_Adjust1588timer(uint32_t instance,int32_t drift);
**         ENET_DRV_GetTxTs                - enet_status_t ENET_DRV_GetTxTs(enet_private_ptp_buffer_t * ptpBuffer,volatile...
**         ENET_DRV_GetRxTs                - enet_status_t ENET_DRV_GetRxTs(enet_private_ptp_buffer_t * ptpBuffer,uint8_t...
**         ENET_DRV_1588l2queueInit        - enet_status_t ENET_DRV_1588l2queueInit(enet_dev_if_t *...
**         ENET_DRV_Service_l2packet       - enet_status_t ENET_DRV_Service_l2packet(enet_dev_if_t *...
**         ENET_DRV_Send_l2packet          - enet_status_t ENET_DRV_Send_l2packet(enet_dev_if_t *...
**         ENET_DRV_Receive_l2packet       - enet_status_t ENET_DRV_Receive_l2packet(enet_dev_if_t *...
**         ENET_DRV_1588Ioctl              - enet_status_t ENET_DRV_1588Ioctl(enet_dev_if_t * enetIfPtr,uint32_t...
**         ENET_DRV_Is1588TsBuffFull       - bool ENET_DRV_Is1588TsBuffFull(enet_mac_ptp_ts_ring_t * ptpTsRingPtr);
**         ENET_DRV_Update1588TsBuff       - enet_status_t ENET_DRV_Update1588TsBuff(enet_mac_ptp_ts_ring_t *...
**         ENET_DRV_Search1588TsBuff       - enet_status_t ENET_DRV_Search1588TsBuff(enet_mac_ptp_ts_ring_t *...
**         ENET_DRV_Incr1588TsBuffRing     - static inline uint32_t ENET_DRV_Incr1588TsBuffRing(uint32_t size,uint32_t...
**         ENET_DRV_TsIRQHandler           - void ENET_DRV_TsIRQHandler(uint32_t instance);
**         ENET_DRV_Init                   - enet_status_t ENET_DRV_Init(enet_dev_if_t * enetIfPtr,const...
**         ENET_DRV_Deinit                 - enet_status_t ENET_DRV_Deinit(enet_dev_if_t * enetIfPtr);
**         ENET_DRV_UpdateRxBuffDescrip    - enet_status_t ENET_DRV_UpdateRxBuffDescrip(enet_dev_if_t * enetIfPtr,bool...
**         ENET_DRV_CleanupTxBuffDescrip   - enet_status_t ENET_DRV_CleanupTxBuffDescrip(enet_dev_if_t * enetIfPtr);
**         ENET_DRV_IncrRxBuffDescripIndex - enet_bd_struct_t* ENET_DRV_IncrRxBuffDescripIndex(enet_dev_if_t *...
**         ENET_DRV_IncrTxBuffDescripIndex - enet_bd_struct_t* ENET_DRV_IncrTxBuffDescripIndex(enet_dev_if_t *...
**         ENET_DRV_RxErrorStats           - bool ENET_DRV_RxErrorStats(enet_dev_if_t * enetIfPtr,volatile...
**         ENET_DRV_TxErrorStats           - void ENET_DRV_TxErrorStats(enet_dev_if_t * enetIfPtr,volatile...
**         ENET_DRV_ReceiveData            - enet_status_t ENET_DRV_ReceiveData(enet_dev_if_t *...
**         ENET_DRV_ReceiveData            - enet_status_t ENET_DRV_ReceiveData(enet_dev_if_t * enetIfPtr);
**         ENET_DRV_InstallNetIfCall       - enet_status_t ENET_DRV_InstallNetIfCall(enet_dev_if_t *...
**         ENET_DRV_SendData               - enet_status_t ENET_DRV_SendData(enet_dev_if_t * enetIfPtr,uint32_t...
**         ENET_DRV_RxIRQHandler           - void ENET_DRV_RxIRQHandler(uint32_t instance);
**         ENET_DRV_TxIRQHandler           - void ENET_DRV_TxIRQHandler(uint32_t instance);
**         ENET_DRV_CalculateCrc32         - void ENET_DRV_CalculateCrc32(uint8_t * address,uint32_t * crcValue);
**         ENET_DRV_AddMulticastGroup      - enet_status_t ENET_DRV_AddMulticastGroup(uint32_t instance,uint8_t *...
**         ENET_DRV_LeaveMulticastGroup    - enet_status_t ENET_DRV_LeaveMulticastGroup(uint32_t instance,uint8_t * address);
**         enet_mac_enqueue_buffer         - void enet_mac_enqueue_buffer(void ** queue,void * buffer);
**         enet_mac_dequeue_buffer         - void* enet_mac_dequeue_buffer(void ** queue);
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
** @file eNet1.h
** @version 01.00
*/         
/*!
**  @addtogroup eNet1_module eNet1 module documentation
**  @{
*/         
#ifndef __eNet1_H
#define __eNet1_H
/* MODULE eNet1. */
/* Include inherited beans */
#include "clockMan1.h"
#include "Cpu.h"
#include "fsl_enet_driver.h"

/*! @brief Device instance number */
#define eNet1_IDX ENET_IDX
/*! @brief Device instance number for backward compatibility */
#define FSL_ENET1 eNet1_IDX

#endif
/* ifndef __eNet1_H */
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



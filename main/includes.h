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

#ifndef __INCLUDES_H__
#define __INCLUDES_H__

/*************************************************************************************************************
*                                         	STANDARD LIBRARIES												 *
*************************************************************************************************************/

#include <string.h>
#include <stdio.h>

/*************************************************************************************************************
*                                                 	OS														 *
*************************************************************************************************************/

#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "gpio1.h"
#include "FRTOS1.h"
#include "KSDK1.h"
#include "UTIL1.h"
#include "eNet1.h"
#include "ff.h"
#include "WAIT1.h"
#include "TMOUT1.h"
#include "CS1.h"
#include "memoryCard1.h"
#include "fsl_sdhc1.h"

#if CPU_INIT_CONFIG
	#include "Init_Config.h"
#endif

/*************************************************************************************************************
*                                              	LIBRARIES													 *
*************************************************************************************************************/

// User includes (#include below this line is not maintained by Processor Expert)
#include "board.h" // board header file
#include "gpio1.h" // General purpose I/O pins
#include "FreeRTOS.h" // FreeRTOS interface
#include "debugFunctions.h" // Debug related functions
#include "generalExtraFunctions.h" // Other general functions needed
#include "lwIP_functions.h" // LwIP related functions
#include "sdCard.h" // SD Card related functions

/*************************************************************************************************************
*                                              		LwIP													 *
*************************************************************************************************************/

#include "lwip/api.h"
#include "lwip/tcpip.h"
#include "lwip/udp.h"
#include "lwip/dhcp.h"
#include "netif/etharp.h"
#include "ethernetif.h"

#endif

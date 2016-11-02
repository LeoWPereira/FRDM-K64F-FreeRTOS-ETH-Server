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

#ifndef __LWIP_FUNCTIONS_H__
#define __LWIP_FUNCTIONS_H__

/*************************************************************************************************************
 * 												DEPENDENCIAS												 *
 ************************************************************************************************************/

#include "includes.h"

/*************************************************************************************************************
* 											CONSTANTES E MACROS												 *
 ************************************************************************************************************/

#define DHCP_TIMEOUT 10 // How many times we're gonna try to get an IP

/*************************************************************************************************************
 * 										DEFINICOES DE TIPOS E ESTRUTURAS									 *
 ************************************************************************************************************/

TaskHandle_t blinky_task_handler = NULL;

/*************************************************************************************************************
 * 										  PROTOTIPOS DE FUNCOES LOCAIS										 *
 ************************************************************************************************************/

/*
 * Description:
 * Inputs:
 * Outputs:
 */
void LwipInitTask(void* pvArguments);

/*************************************************************************************************************
 * 												VARIAVEIS EXTERNAVEIS										 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 												  VARIAVEIS GLOBAIS											 *
 ************************************************************************************************************/



/*************************************************************************************************************
 * 										DEFINICOES DE FUNCOES EXTERNAVEIS									 *
 ************************************************************************************************************/



#endif

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

void LwipInitTask(void* pvArguments)
{
	err_t err;

	struct netif fsl_netif0;

	ip_addr_t fsl_netif0_ipaddr, fsl_netif0_netmask, fsl_netif0_gw;

	char msg[] = "This is my message";

	(void)pvArguments;

	// Init lwip stack
	tcpip_init(NULL,NULL);

	printf("%s: lwip init called ..\n", __FUNCTION__);

	// Setup IP Config for DHCP ...
	IP4_ADDR(&fsl_netif0_ipaddr, 0,0,0,0);
	IP4_ADDR(&fsl_netif0_netmask, 0,0,0,0);
	IP4_ADDR(&fsl_netif0_gw, 0,0,0,0);

	// Add a network interface to the list of lwIP netifs.
	netif_add(&fsl_netif0, &fsl_netif0_ipaddr, &fsl_netif0_netmask, &fsl_netif0_gw, NULL, ethernetif_init, ethernet_input);

	// Set the network interface as the default network interface.
	netif_set_default(&fsl_netif0);

	// obtain the IP address, default gateway and subnet mask by using DHCP
	err = dhcp_start(&fsl_netif0);

	printf("%s : Started DCHP request (%s)\n", __FUNCTION__, lwip_strerr(err));

	// Creates a blinky_task task to show the user we're trying to get an IP
	if (xTaskCreate (
		  blinky_task,  /* task function */
		  "Blinky", /* task name for kernel awareness */
		  configMINIMAL_STACK_SIZE, /* task stack size */
		  (void*)NULL, /* optional task startup argument */
		  tskIDLE_PRIORITY,  /* initial priority */
		  &blinky_task_handler /* task handle */
	   ) != pdPASS)
    {
		for( ; ; ) { } /* error! probably out of memory */
    }

	for(int i=0; i < DHCP_TIMEOUT && fsl_netif0.dhcp->state != DHCP_BOUND; i++)
	{
		printf("%s : Current DHCP State : %d\n", __FUNCTION__, fsl_netif0.dhcp->state);

		// Wait a second
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}

	vTaskDelete(blinky_task_handler); // Delete the blinky_task task

	if (fsl_netif0.dhcp->state == 10)
	{
		GPIO_DRV_WritePinOutput(LED_RED, 0);

		// Make it active ...
		netif_set_up(&fsl_netif0);

		printf("\n\n%s : Interface is up : %d\n", __FUNCTION__, fsl_netif0.dhcp->state);
		printf("%s : IP %s\n", __FUNCTION__, ipaddr_ntoa(&fsl_netif0.ip_addr));
		printf("%s : NM %s\n", __FUNCTION__, ipaddr_ntoa(&fsl_netif0.netmask));
		printf("%s : GW %s\n", __FUNCTION__, ipaddr_ntoa(&fsl_netif0.gw));

		if (fsl_netif0.dhcp->state == DHCP_BOUND)
		{
			// Send out some TCP data
			struct netconn* pConnection;

			// Create TCP connection
			pConnection = netconn_new(NETCONN_TCP);

			// Connect to local port
			err = netconn_bind(pConnection, IP_ADDR_ANY, 12345);
			printf("%s : Bound to IP_ADDR_ANY port 12345 (%s)\n", __FUNCTION__, lwip_strerr(err));

			err = netconn_connect(pConnection, IP_ADDR_BROADCAST, 12346 );
			printf("%s : Connected to IP_ADDR_BROADCAST port 12346 (%s)\n", __FUNCTION__, lwip_strerr(err));

			for(int i = 0; i < 10; i++ )
			{
				struct netbuf* buf = netbuf_new();
				void* data = netbuf_alloc(buf, sizeof(msg));

				memcpy (data, msg, sizeof (msg));

				err = netconn_send(pConnection, buf);
				printf("%s : Sending to IP_ADDR_BROADCAST port 12346 (%s)\n", __FUNCTION__, lwip_strerr(err));

				netbuf_delete(buf); // De-allocate packet buffer

				// Wait a second
				vTaskDelay(1000/portTICK_PERIOD_MS);
			}
		}
	}

	else
	{
		GPIO_DRV_WritePinOutput(LED_RED, 1);

		printf("\n\n%s : Interface is down : %d\n", __FUNCTION__, fsl_netif0.dhcp->state);
		printf("%s : IP %s\n", __FUNCTION__, ipaddr_ntoa(&fsl_netif0.ip_addr));
		printf("%s : NM %s\n", __FUNCTION__, ipaddr_ntoa(&fsl_netif0.netmask));
		printf("%s : GW %s\n", __FUNCTION__, ipaddr_ntoa(&fsl_netif0.gw));

		printf("\nPlease try again later ...\n");

		// Wait a second
		vTaskDelay(1000/portTICK_PERIOD_MS);

		// finish the lease of the IP address
		err = dhcp_release(&fsl_netif0);
		printf("%s : DHCP Release (%s)\n", __FUNCTION__, lwip_strerr(err));
	}

	//err = netconn_disconnect(pConnection);
	//printf("%s : Disconnected from IP_ADDR_BROADCAST port 12346 (%s)\n", __FUNCTION__, lwip_strerr(err));

	//err = netconn_delete(pConnection);
	//printf("%s : Deleted connection (%s)\n", __FUNCTION__, lwip_strerr(err));

	//for( ; ; ) {};
}

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

void append(char *fileNameAndPath, char *text)
{
    FATFS fileSystem;

    // mount SD card
    FRESULT fResult = f_mount(SD_DRIVE_NUMBER, &fileSystem);

    if (fResult == FR_OK)
    {
        fResult = f_chdrive(SD_DRIVE_NUMBER);

        if (fResult == FR_OK)
        {
            FIL file;
            static char pathWithDriveLetter[255];
            sprintf(pathWithDriveLetter, "%u:%s", SD_DRIVE_NUMBER, fileNameAndPath);

            /* Open a text file */
            fResult = f_open(&file, pathWithDriveLetter, FA_OPEN_ALWAYS | FA_WRITE);
            if (fResult == FR_OK)
            {
                /* Move to end of the file to append data */
                fResult = f_lseek(&file, file.fsize);

                /* Write to the file */
                uint32_t bytesWritten;
                fResult = f_write(&file, text, strlen(text), &bytesWritten);
            }
            /* Close the file */
            fResult = f_close(&file);
        }

        // unmount SD card
        fResult = f_mount(SD_DRIVE_NUMBER, NULL);
    }
}

void SDCardInitTask(void* pvArguments)
{
	(void)pvArguments;

	printf("%s: Waiting for SD Card ..\n", __FUNCTION__);

	// Check card is already inserted and don't wait for interrupt
    check_card_inserted();

    // If card is not inserted then we must wait till it is inserted
    wait_for_card();

    GPIO_DRV_WritePinOutput(LEDRGB_BLUE, 0);

    printf("%s: SD Card inserted ..\n", __FUNCTION__);

    append("/data.log", "test data");

    printf("%s: data appended ..\n", __FUNCTION__);
}

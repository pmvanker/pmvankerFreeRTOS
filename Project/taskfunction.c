/*
 * taskfunction.c
 *
 *  Created on: 23-Jan-2019
 *      Author: pmvanker
 */
#include<stdio.h>
#include "FreeRTOS.h"
#include "task.h"

void vTaskFunction( void *pvParameters )
{
	char *pcTaskName;
	const TickType_t xDelay250ms =  pdMS_TO_TICKS(250);
	pcTaskName = ( char * ) pvParameters;
	for( ;; )
	{
		/* Print out the name of this task. */
		printf("%s", pcTaskName );
		/* Delay for a period. */
		vTaskDelay(xDelay250ms);
	}
}




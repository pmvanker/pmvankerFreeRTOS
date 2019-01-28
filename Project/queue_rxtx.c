/*
 * queue_rxtx.c
 *
 *  Created on: 23-Jan-2019
 *      Author: pmvanker
 */
#include <stdio.h>
#include "FreeRTOS.h"
#include "queue.h"
extern QueueHandle_t xQueue;
void vSenderTask(void *pvParameters)
{
	int lValueToSend;
	BaseType_t xStatus;
	lValueToSend = (int) pvParameters;
	for(;;)
	{
		xStatus = xQueueSendToBack(xQueue,&lValueToSend,0);
		if(xStatus!=pdPASS)
		{
			printf("Could Not Send Data to Queue\r\n");
		}
	}
}
void vReceiverTask(void *pvParameters)
{
	int lReceivedValue;
	BaseType_t xStatus;
	const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
	for(;;)
	{
		if(uxQueueMessagesWaiting(xQueue)!=0)
		{
			printf("Queue Should havebeen Empty\r\n");
		}
		xStatus = xQueueReceive(xQueue,&lReceivedValue,xTicksToWait);

		if(xStatus==pdPASS)
		{
			printf("Data Receibed %d\r\n",lReceivedValue);
		}
		else
		{
			printf("Fail to Received\r\n");
		}
	}
}




/*
 * struct.c
 *
 *  Created on: 28-Jan-2019
 *      Author: pmvanker
 */
#include <stdio.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "mystruct.h"

extern QueueHandle_t xQueue;
void vSenderTask(void *pvParameters)
{
	BaseType_t xStatus;
	const TickType_t xTicksToWait = pdMS_TO_TICKS(100);
	for(;;)
	{
		xStatus = xQueueSendToBack(xQueue,pvParameters,xTicksToWait);
		if(xStatus!=pdPASS)
		{
			printf("Fail to send Data\r\n");
		}
	}
}
void vReceiverTask(void *pvParameters)
{
	Data_t xReceivedStructure;
	BaseType_t xStatus;
	for(;;)
	{
		if(uxQueueMessagesWaiting(xQueue)!=3)
		{
			printf("Queue is Full\r\n");
		}
		xStatus=xQueueReceive(xQueue,&xReceivedStructure,0);
		if(xStatus==pdPASS)
		{
			if(xReceivedStructure.eDataSource==eSender1)
			{
				printf("From Sender 1 :%d\n",xReceivedStructure.ucValue);
			}
			else
			{
				printf("From Sender 2 :%d\n",xReceivedStructure.ucValue);
			}
		}
		else
		{
			printf("could not Receive Queue Data");
		}
	}
}




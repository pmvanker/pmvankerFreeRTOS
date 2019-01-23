/*
 * twotask.c
 *
 *  Created on: 22-Jan-2019
 *      Author: pmvanker
 */
#include<stdio.h>
void vTask1(void *p)
{
	for( ;; )
	{
		printf("Task 1\r\n");
		vTaskDelay(100);
	}
}
void vTask2(void *p)
{
	for( ;; )
	{
		printf( "Task 2\r\n");
		vTaskDelay(50);
	}
}

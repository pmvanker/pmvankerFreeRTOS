/*
 * struct.h
 *
 *  Created on: 28-Jan-2019
 *      Author: pmvanker
 */

#ifndef PROJECT_MYSTRUCT_H_
#define PROJECT_MYSTRUCT_H_

typedef enum
{
	eSender1,
	eSender2
}DataSource_t;
typedef struct
{
	unsigned int ucValue;
	DataSource_t eDataSource;
}Data_t;




#endif /* PROJECT_MYSTRUCT_H_ */

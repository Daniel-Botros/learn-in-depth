/*
 * fifo.h
 *
 *  Created on: Dec 5, 2023
 *      Author: Daniel
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

#define DPRINTF(...)		{fflush(stdout);\
							fflush(stdin);\
							printf (__VA_ARGS__);\
							fflush(stdout);\
							fflush(stdin);}


/*-----user config-----*/

#define element_type uint8_t	//element type (uint8_t, uint26_t, uint32_t, ....)
#define width 5					//the width of the buffer

/*-----end user config-----*/

element_type uart_buffer[width];

//FIFO data types

typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

//error status type

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null,
}FIFO_BUF_Status;

//FIFO APIs

FIFO_BUF_Status FIFO_init (FIFO_Buf_t* fifo, element_type* buf, uint32_t length);
FIFO_BUF_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item);
FIFO_BUF_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item);
FIFO_BUF_Status FIFO_IS_FULL (FIFO_Buf_t* fifo);
FIFO_BUF_Status FIFO_print (FIFO_Buf_t* fifo);
FIFO_BUF_Status error_print (FIFO_BUF_Status stat);





#endif /* FIFO_H_ */

/*
 * lifo.h
 *
 *  Created on: Dec 2, 2023
 *      Author: Daniel
 */

#ifndef LIFO_H_
#define LIFO_H_

//type defs

typedef struct {
	unsigned int size ;
	unsigned int count ;
	unsigned int* base ;
	unsigned int* head ;
}LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null,
}LIFO_status;

//APIs
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int size );
LIFO_status LIFO_push_item (LIFO_Buf_t* lifo_buf, unsigned int item );
LIFO_status LIFO_pop_item (LIFO_Buf_t* lifo_buf, unsigned int* item);
LIFO_status error_print (LIFO_status stat);

#endif /* LIFO_H_ */

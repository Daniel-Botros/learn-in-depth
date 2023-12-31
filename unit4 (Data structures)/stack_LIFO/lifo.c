/*
 * lifo.c
 *
 *  Created on: Dec 2, 2023
 *      Author: Daniel
 */

#include "lifo.h"
#include "stdio.h"
//APIs
LIFO_status LIFO_init (LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int size ){
	if(buf == NULL)
		return LIFO_Null;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->size = size;
	lifo_buf->count = 0;
	return LIFO_no_error;
}
LIFO_status LIFO_push_item (LIFO_Buf_t* lifo_buf, unsigned int item ){

	//see if lifo is init
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;

	//chick if lifo full
	//if(lifo_buf->head >= lifo_buf->base + lifo_buf->size * sizeof(lifo_buf->base))
	if (lifo_buf->count == lifo_buf->size)
		return LIFO_full;

	//adding item to lifo
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	return LIFO_no_error;

}
LIFO_status LIFO_pop_item (LIFO_Buf_t* lifo_buf, unsigned int* item){

	//see if lifo is init
	if (!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	//chick if lifo empty
	if (lifo_buf->count == 0)
		return LIFO_empty;

	//poping item to lifo
	lifo_buf->head--;
	lifo_buf->count--;

	 *item=*(lifo_buf->head);

	return LIFO_no_error;

}
LIFO_status error_print (LIFO_status stat){
	switch((int)stat) {
	  case 1:
	    printf("LIFO_full \n");
	    break;
	  case 2:
		  printf("LIFO_empty \n");
	    break;
	  case 3:
		  printf("LIFO_Null \n");
	  	    break;
	}
	return stat;

}


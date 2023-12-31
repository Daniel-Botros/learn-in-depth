/*
S * fifo.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Daniel
 */

#include "fifo.h"

//fifo APIS

FIFO_BUF_Status FIFO_init (FIFO_Buf_t* fifo, element_type* buf, uint32_t length){
	if (buf == NULL)
		return FIFO_Null;

	fifo->length = length;
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;

	return FIFO_no_error;
}
FIFO_BUF_Status FIFO_enqueue (FIFO_Buf_t* fifo, element_type item){
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	if(FIFO_IS_FULL(fifo)==FIFO_full)
		return FIFO_full;

	*(fifo->head) = item;
	fifo->count ++;

	//circler fifo
	if(fifo->head == (fifo->base + ((fifo->length-1)*sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_no_error;
}
FIFO_BUF_Status FIFO_dequeue (FIFO_Buf_t* fifo, element_type* item){
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	if(fifo->count == 0)
		return FIFO_empty;

	*item = *(fifo->tail);
	fifo->count --;

	//circler fifo
	if(fifo->tail == (fifo->base + ((fifo->length-1)*sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;
}
FIFO_BUF_Status FIFO_IS_FULL (FIFO_Buf_t* fifo){
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	if (fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}
FIFO_BUF_Status FIFO_print (FIFO_Buf_t* fifo){
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null;

	if(fifo->count == 0)
		return FIFO_empty;

	element_type* temp ;
	int i;

	temp = fifo->base;
	DPRINTF("=====FIFO Print===== \n");
	for(i=0;i<width; i++){
		DPRINTF("\t %x \n", *temp);
		temp++;
	}
	DPRINTF("=====FIFO Print End===== \n");

	return FIFO_no_error;
}
FIFO_BUF_Status error_print (FIFO_BUF_Status stat){
	switch((int)stat) {
	case 1:
		DPRINTF("FIFO_full \n");
		break;
	case 2:
		DPRINTF("FIFO_empty \n");
		break;
	case 3:
		DPRINTF("FIFO_Null \n");
		break;
	}
	return stat;
}


/*
 * main.c
 *
 *  Created on: Dec 5, 2023
 *      Author: Daniel
 */

#include "fifo.h"

void main(){

	FIFO_Buf_t FIFO_uart;
	element_type i, temp ;
	error_print(FIFO_init(&FIFO_uart, uart_buffer, width));

	for(i=0;i<7;i++){
		error_print(FIFO_enqueue(&FIFO_uart,i));
	}

	error_print(FIFO_print(&FIFO_uart));

	for(i=0;i<3;i++){
		error_print(FIFO_dequeue(&FIFO_uart,&temp));
		DPRINTF("%x \n",temp);
	}

	error_print(FIFO_print(&FIFO_uart));

	///////////////////

	for(i=5;i<9;i++){
		error_print(FIFO_enqueue(&FIFO_uart,i));
	}

	error_print(FIFO_print(&FIFO_uart));

	for(i=0;i<5;i++){
		error_print(FIFO_dequeue(&FIFO_uart,&temp));
		DPRINTF("%x \n",temp);
	}

}


/*
 * main.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Daniel
 */

#include "stdio.h"
#include "lifo.h"
#include "stdlib.h"

int main () {
	int i, temp = 0;
	LIFO_Buf_t uart_lifo , I2C_lifo;
	//static allocation
	unsigned int buffer1 [5];
	LIFO_init(&uart_lifo,buffer1, 5);
	//dynamic allocation
	unsigned int* buffer2  = (unsigned int*) malloc(5*sizeof(unsigned int));
	LIFO_init(&I2C_lifo,buffer2, 5);

	//adding items
	for(i=0;i<6;i++){
		if(error_print(LIFO_push_item(&uart_lifo,i))==LIFO_no_error)
			printf("UART_LIFO add : %d \n",i);
	}


	//poping items
	for(i=0;i<6;i++){
		if(error_print(LIFO_pop_item(&uart_lifo,&temp))==LIFO_no_error)
			printf("UART_LIFO get : %d \n",temp);
	}
}

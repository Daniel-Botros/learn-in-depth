#include "uart.h"

unsigned char sting_bufffer[100] = "learn-in-depth:Daniel";

void main (void){

	Uart_Send_string (sting_bufffer);
}

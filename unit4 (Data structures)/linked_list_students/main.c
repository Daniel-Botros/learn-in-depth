/*
 * main.c
 *
 *  Created on: Dec 11, 2023
 *      Author: Daniel
 */



#include "linked_list_st.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"


void main(){

	char temp_text[40];

	while(1){

		printf("\n ==========================================");
		printf("\n \t  Choose One Of The Following Option \n");
		printf("\n 1 : Add Student");
		printf("\n 2 : Delete Student");
		printf("\n 3 : View All Students");
		printf("\n 4 : Delete All Student");
		printf("\n 5 : Find Student In Index");
		printf("\n 6 : List Length (Recursive)");
		printf("\n 7 : Find Student In Index(From The End)");
		printf("\n 8 : Reverse Linked List");
		printf("\n 9 : Print The Middle Item In The List");
		printf("\n Enter Option No. : ");

		gets(temp_text);
		printf("\n ==========================================");

		switch(atoi(temp_text)){

		case 1 :
			AddStudent();
			break;
		case 2 :
			delete_student();
			break;
		case 3 :
			view_Students();
			break;
		case 4 :
			DeleteALL();
			break;
		case 5 :
			Find_student_index();
			break;
		case 6 :
			linked_length_recursive();
			break;
		case 7 :
			Find_student_index_end();
			break;
		case 8 :
			Reverse_Linked_List();
			break;
		case 9 :
			Middle_Of_List();
			break;
		default :
			printf("\n Not An Option");
			break;

		}

	}
}


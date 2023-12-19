/*
 * linked_list_st.h
 *
 *  Created on: Dec 11, 2023
 *      Author: Daniel
 */

#ifndef LINKED_LIST_ST_H_
#define LINKED_LIST_ST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

//effective data

struct Sdata{
	int ID;
	char name [40];
	float height;
};

struct SStudent{
	struct Sdata Student;
	struct SStudent* PNextStudent;
};


//APIs

void AddStudent();
int delete_student();
void view_Students();
void DeleteALL();
int Find_student_index();
void linked_length_recursive();
int Find_student_index_end();
void Reverse_Linked_List();
void Middle_Of_List();



#endif /* LINKED_LIST_ST_H_ */

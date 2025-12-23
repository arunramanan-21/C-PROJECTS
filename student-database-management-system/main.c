#include<stdio.h>
#include "struct_init.h"
#include "student_add.c"
#include "student_show.c"
#include "student_save.c"
#include "student_delete.c"
#include "student_modify.c"
#include "student_sort.c"
static int roll=0;//for unique rollno
int deleted_rolls[50];
int del_count=0;
int main(){
	struct st *hptr=0;
	char choice;
	file_to_node(&hptr,&roll);
	while(1){
	printf("\t\t* * * * * STUDENT RECORD MENU * * * * *\n");
	printf("\t\t*  A/a\t:Add New Record\t\t\t*\n");
	printf("\t\t*  D/d\t:Delete A Record\t\t*\n");
	printf("\t\t*  S/s\t:Show the Records\t\t*\n");
	printf("\t\t*  M/m\t:Modify A Record\t\t*\n");
	printf("\t\t*  V/v\t:Save the Records\t\t*\n");
	printf("\t\t*  T/t\t:Sort the Records\t\t*\n");
	printf("\t\t*  L/l\t:Delete All the Records\t\t*\n");
	printf("\t\t*  R/r\t:Reverse the list\t\t*\n"); 
	printf("\t\t*  E/e\t:Exit\t\t\t\t*\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * \n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&choice);
	printf("\n");
	if((choice=='a')||(choice=='A')){
		add_student(&hptr,roll++);
		//system("clear");
	}
	else if((choice=='d')||(choice=='D')){
		delete_student(&hptr);
		//save_student(hptr);
	}
	else if((choice=='s')||(choice=='S')){
		print_student(hptr);
	//	system("clear");
	}
	else if((choice=='m')||(choice=='M')){
		modify_student(&hptr);
		save_student(hptr);
	}
	else if((choice=='v')||(choice=='V')){
		save_student(hptr);
	//	system("clear");
	}
	else if((choice=='t')||(choice=='T')){
		sort_student(hptr);
		//print_student(hptr);
	}
	else if((choice=='l')||(choice=='L')){
		delete_all(&hptr);
	}
	else if((choice=='r')||(choice=='R')){
		printf("\t\t* * * *ROLL * * * * * NAME * * * * *MARKS * * * *\n");
		rev_print(hptr);
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * *\n");
	}
	else if((choice=='e')||(choice=='E')){
		save_n_exit(hptr);
		return 0;
	}
	}
}

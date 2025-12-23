//#include "struct_init.h"
#include<stdlib.h>
extern int deleted_rolls[];
extern int del_count;
void add_student(struct st **ptr,int roll){
	struct st *temp=(struct st *)malloc(sizeof(struct st));
	printf("Enter the student details:");
	scanf("%s %f",temp->name,&temp->mark);
	if(del_count>0){
		temp->rollno=deleted_rolls[--del_count];
	}
	else{
		++roll;
		temp->rollno=roll;
	}
	if((*ptr==0)||temp->rollno<(*ptr)->rollno){
		temp->next=*ptr;
		*ptr=temp;
	}
	else{
		struct st *last=*ptr;
		while((last->next!=0)&&(temp->rollno>last->next->rollno))
			last=last->next;
		temp->next=last->next;
		last->next=temp;
	}
}
void file_to_node(struct st **ptr,int *roll){
	FILE *fs=fopen("Student_details.txt","r");
	if(fs==NULL)
		return;
	char s[100];
	fgets(s,sizeof(s),fs);
	while(1){
		struct st *temp=(struct st *)malloc(sizeof(struct st));
		if(fscanf(fs,"%d %s %f",&temp->rollno,temp->name,&temp->mark)!=3){
			free(temp);
			break;
		}
		temp->next=NULL;
		if(*ptr==NULL)
			*ptr=temp;
		else{
			struct st *last=*ptr;
			while(last->next!=0)
				last=last->next;
			last->next=temp;
		}
		if(*roll < temp->rollno)
			*roll=temp->rollno;
	}
	fclose(fs);
	del_count=0;
}



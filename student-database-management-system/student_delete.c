//#include "struct_init.h"
#include<string.h>
extern int deleted_rolls[];
extern int del_count;
void delete_student(struct st **ptr){
	char choice_del;
	if(*ptr==0){
		printf("There is no record to delete!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t*\t Enter                                *\n");
        printf("\t\t*\t R/r\t: Enter rollno to delete      *\n");
        printf("\t\t*\t N/n\t: Enter Name to delete        *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&choice_del);
	printf("\n");
	if((choice_del=='r')||(choice_del=='R')){
		delete_roll(ptr);
	}
	else if((choice_del=='n')||(choice_del=='N')){
		delete_name(ptr);
	}
}
void delete_roll(struct st **ptr){
	int roll_del;
	printf("Enter the rollno to delete:");
	scanf("%d",&roll_del);
	struct st *last,*temp;
	temp=*ptr;
	while(temp!=0){
		if(temp->rollno==roll_del){
			if(temp==*ptr)
				*ptr=temp->next;
			else
				last->next=temp->next;
			if(del_count < 50){
				deleted_rolls[del_count]=roll_del;
				del_count++;
			}
			free(temp);
			temp=NULL;
			return;
		}
		else{
			last=temp;
			temp=temp->next;
		}
	}
	printf("Record Deleted Successfully!!\n\n");
}
void delete_name(struct st **ptr){
	int d_roll;
	char name_del[50];
	printf("Enter the name to delete:");
	scanf("%s",name_del);
	struct st *temp=*ptr;;
	while(temp!=0){
		if(strcmp(temp->name,name_del)==0){
			printf("%d %s %f\n",temp->rollno,temp->name,temp->mark);
		}
		temp=temp->next;
	}
	printf("Enter which rollno record to delete:");
	scanf("%d",&d_roll);
	struct st *temp1=*ptr;
	struct st *last;
	while(temp1!=0){
		if(temp1->rollno==d_roll){
			if(temp1==*ptr){
				*ptr=temp1->next;
			}
			else
				last->next=temp1->next;
			if(del_count < 50){
				deleted_rolls[del_count]=d_roll;
				del_count++;
			}
			free(temp1);
			temp1=NULL;
			return;
		}
		else{
			last=temp1;
			temp1=temp1->next;
		}
	}
	printf("Record Deleted Successfully!!\n\n");
}
void delete_all(struct st **ptr){
	if(*ptr==0){
		printf("There is no record to delete!!\n\n");
		return;
	}
	struct st *temp;
	while(*ptr!=0){
		temp=*ptr;
		*ptr=temp->next;
		free(temp);
		temp=NULL;
	}
	//int f=remove("Student_details.txt");
}


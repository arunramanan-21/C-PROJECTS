#include "struct_book.h"
void remove_book(struct book **ptr){
	char choice_del;
	if(*ptr==0){
		printf("There is no record to delete!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t 	REMOVE A BOOK                *\n");
	printf("\t\t*\t A/a\t: By Book ID         	   *\n");
	printf("\t\t*\t B/b\t: By Book Name                *\n");
	printf("\t\t*\t C/c\t: Back To Main Menu           *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&choice_del);
	printf("\n");
	if((choice_del=='a')||(choice_del=='A')){
		remove_id(ptr);
	}
	else if((choice_del=='b')||(choice_del=='B')){
		remove_bookname(ptr);
	}
	else if((choice_del=='c')||(choice_del=='C')){
		printf("Going Back to Main Menu!!\n");
		return;
	}
}
void remove_id(struct book **ptr){
	int id_del,flag=0;
	printf("Enter the book id details to delete:");
	scanf("%d",&id_del);
	struct book *last,*temp;
	temp=*ptr;
	while(temp!=0){
		if(temp->ID==id_del){
			printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
			printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
			printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
			flag=1;
			printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);
			printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");

			if(temp==*ptr)
				*ptr=temp->next;
			else
				last->next=temp->next;
			free(temp);
			temp=NULL;
			return;
		}
		else{
			last=temp;
			temp=temp->next;
		}
	}
	if(flag==0){
		printf("Given Book id is not present!!\n\n");
		return;
	}	
	printf("Book Details Deleted Successfully!!\n\n");
}
void remove_bookname(struct book **ptr){
	int d_id,flag=0;
	char name_del[50];
	printf("Enter the name to delete:");
	scanf(" %[^\n]",name_del);
	struct book *temp=*ptr;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	while(temp!=0){
		if(strcmp(temp->book_name,name_del)==0){
			flag=1;
			printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);
		}
		temp=temp->next;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if(flag==0){
		printf("Given Book Name is not present!!\n\n");
		return;
	}
	printf("Enter which book id details to delete:");
	scanf("%d",&d_id);
	struct book *temp1=*ptr;
	struct book *last;
	while(temp1!=0){
		if(temp1->ID==d_id){
			if(temp1==*ptr){
				*ptr=temp1->next;
			}
			else
				last->next=temp1->next;
			free(temp1);
			temp1=NULL;
			return;
		}
		else{
			last=temp1;
			temp1=temp1->next;
		}
	}
	printf("Book Details Deleted Successfully!!\n\n");
}

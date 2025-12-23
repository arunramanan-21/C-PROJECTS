#include "struct_book.h"
#include<string.h>
void search_book(struct book *ptr){
	int bk_id,flag=0;
	char bk_name[50],aut_name[50];
	char sear_choice;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t 		SEARCH A BOOK                    *\n");
	printf("\t\t*\t A/a\t: By Book ID                              *\n");
	printf("\t\t*\t B/b\t: By Book Name                            *\n");
	printf("\t\t*\t C/c\t: By Author Name                          *\n");
	printf("\t\t*\t D/d\t: Back to Main Menu                       *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&sear_choice);
	printf("\n");

	if((sear_choice=='a')||(sear_choice=='A')){
		printf("Enter the BookID:");
		scanf("%d",&bk_id);
		struct book *temp=ptr;
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
		printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");

		while(temp!=0){
			if(temp->ID==bk_id){
				flag=1;
				printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);
				temp=temp->next;
			}
			else{
				temp=temp->next;
			}
		}
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		if(flag==0){
			printf("There is No Book ID found\n\n");
			return;
		}
	}
	else if((sear_choice=='b')||(sear_choice=='B')){
		printf("Enter the Book Name:");
		scanf(" %[^\n]",bk_name);
		struct book *temp=ptr;
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
		printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
		while(temp!=0){
			if(strcmp(temp->book_name,bk_name)==0){
				flag=1;
				printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);
				temp=temp->next;
			}
			else{
				temp=temp->next;
			}
		}
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		if(flag==0){
			printf("There is No Book Name found\n\n");
			return;
		}
	}
	else if((sear_choice=='c')||(sear_choice=='C')){
		printf("Enter the Author Name:");
		scanf(" %[^\n]",aut_name);
		struct book *temp=ptr;
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
		printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
		while(temp!=0){
			if(strcmp(temp->auth_name,aut_name)==0){
				flag=1;
				printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);
				temp=temp->next;
			}
			else{
				temp=temp->next;
			}
		}
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		if(flag==0){
			printf("There is No Author Name found\n\n");
			return;
		}
	}
	else if((sear_choice=='d')||(sear_choice=='D')){
		printf("Going Back to Main Menu\n\n");
		return;
	}
}


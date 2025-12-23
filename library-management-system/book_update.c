#include "struct_book.h"
#include<string.h>
void update_book(struct book **ptr){
	if(*ptr==0){
		printf("There is no Book to modify!!\n");
		return;
	}
	int b_id,up_quantity,flag=0;
	char sear_choice,mod_choice;
	char bk_name[50],aut_name[50],mod_name[50];
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t 	SEARCH A BOOK FOR MODIFICATION           *\n");
	printf("\t\t*\t A/a\t: By Book ID                              *\n");
	printf("\t\t*\t B/b\t: By Book Name                            *\n");
	printf("\t\t*\t C/c\t: Back to Main Menu                       *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&sear_choice);
	printf("\n");
	if((sear_choice=='a')||(sear_choice=='A')){
		printf("Enter the Book ID:");
		scanf("%d",&b_id);
		struct book *temp=*ptr;
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
		printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");

		while(temp!=0){
			if(temp->ID==b_id){
				flag=1;
				printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);

				print_console();
				scanf(" %c",&mod_choice);
				if((mod_choice=='b')||(mod_choice=='B')){
					printf("Enter Book Name:");
					scanf(" %[^\n]",bk_name);
					strcpy(temp->book_name,bk_name);
					break;
				}
				else if((mod_choice=='a')||(mod_choice=='A')){
					printf("Enter Author Name:");
					scanf(" %[^\n]",aut_name);
					strcpy(temp->auth_name,aut_name);
					break;
				}
				else if((mod_choice=='q')||(mod_choice=='Q')){
					printf("Enter Quantity:");
					scanf("%d",&up_quantity);
					temp->quantity=up_quantity;
					break;
				}
			}
			else if(temp->ID!=b_id){
				temp=temp->next;
			}
		}
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
		if(flag==0){
			printf("Given Book ID is not present!!\n\n");
			return;
		}
	}
	else if((sear_choice=='b')||(sear_choice=='B')){
		printf("Enter the Book Name:");
		scanf(" %[^\n]",bk_name);
		struct book *temp=*ptr;
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
		if(flag==0){
			printf("Given Book Name is not present!!\n\n");
			return;
		}
		printf("Enter which ID's Book to modify:");
		scanf("%d",&b_id);
		struct book *temp1=*ptr;
		while(temp1!=0){
			if(temp1->ID==b_id){
				printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
				printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
				printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
				printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",temp->ID, temp->book_name, temp->auth_name, temp->book_type, temp->quantity, temp->availability);
				printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
				print_console();
				scanf(" %c",&mod_choice);
				if((mod_choice=='b')||(mod_choice=='B')){
					printf("Enter Book Name:");
					scanf(" %[^\n]",mod_name);
					strcpy(temp1->book_name,mod_name);
					break;
				}
				else if((mod_choice=='a')||(mod_choice=='A')){
					printf("Enter Author Name:");
					scanf(" %[^\n]",aut_name);
					strcpy(temp1->auth_name,aut_name);
					break;
				}
				else if((mod_choice=='q')||(mod_choice=='Q')){
					printf("Enter Quantity:");
					scanf("%d",&up_quantity);
					temp1->quantity=up_quantity;
					break;
				}
			}
			else if(temp1->ID!=b_id){
				temp1=temp1->next;
			}
		}
		printf("Updation Done Suucessfully!!\n\n");
	}
}
void print_console(void){
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t         UPDATE BOOK DETAILS          *\n");
	printf("\t\t*\t B/b\t: Update Book Name            *\n");
	printf("\t\t*\t A/a\t: Update Author Name          *\n");
	printf("\t\t*\t Q/q\t: Update Quantity             *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
}

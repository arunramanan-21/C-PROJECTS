#include "struct_book.h"
#include<time.h>
void return_book(struct person **ptr,struct book **iptr){
	char opt;
	if(*ptr==0){
		printf("No Books issued . So no Books to return!!\n\n");
		return;
	}
	char ret_choice;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t           RETURN A BOOK            	            *\n");
	printf("\t\t*\t A/a\t: By Person ID                            *\n");
	printf("\t\t*\t B/b\t: By Person Name                          *\n");
	printf("\t\t*\t C/c\t: Back to Main Menu                       *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&ret_choice);
	if((ret_choice=='a')||(ret_choice=='A')){
		return_pid(ptr,iptr);
	}
	else if((ret_choice=='b')||(ret_choice=='B')){
		return_personame(ptr,iptr);
	}
	else if((ret_choice=='c')||(ret_choice=='C')){
		printf("Going Back to Main Menu!!\n\n");
		return;
	}
	printf("Do U Want to File in the file(s/n):");
	scanf(" %c",&opt);
	if((opt=='s')||(opt=='S')){
		save_issuedbook(*ptr);
		printf("Details Saved Successfully!!\n\n");
	}
	else{
		printf("Details not SAved!!\n\n");
		return;
	}
}

void return_pid(struct person **ptr,struct book **iptr){
	int p_id,b_id;
	char rt_date[20];
	struct person *p=*ptr;
	struct book *q=*iptr;
	printf("Enter the Person's ID:");
	scanf("%d",&p_id);
	struct person *cp=*ptr;
	while((p!=NULL)&&(p->personid!=p_id)){
		p=p->next;
	}
	if(p==NULL){
		printf("There is no Person's ID was present!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* PERSON ID | PERSON NAME        | BOOK ID | BOOK NAME           | AUTHOR NAME        | BOOK TYPE        | ISSUED DATE  |  DUE DATE  | RETURN DATE  |FINE   *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	printf("\t\t* %9d | %-18.18s | %7d | %-18.18s | %-18.18s | %-15.15s | %-11.11s | %-11.11s | %-12.12s | %5d   *\n",p->personid,p->personame,p->bookid,p->bookname,p->authorname,p->booktype,p->iss_date,p->due_date,p->ret_date,p->fine);
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter the Return Book ID:");
	scanf("%d",&b_id);
	while((cp!=NULL)&&(cp->bookid!=b_id)){
		cp=cp->next;
	}
	if(cp==NULL){
		printf("There is no Person's ID was present!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* PERSON ID | PERSON NAME        | BOOK ID | BOOK NAME           | AUTHOR NAME        | BOOK TYPE        | ISSUED DATE  |  DUE DATE  | RETURN DATE  |FINE   *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	printf("\t\t* %9d | %-18.18s | %7d | %-18.18s | %-18.18s | %-15.15s | %-11.11s | %-11.11s | %-12.12s | %5d   *\n",p->personid,p->personame,p->bookid,p->bookname,p->authorname,p->booktype,p->iss_date,p->due_date,p->ret_date,p->fine);
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	while(q!=NULL){
		if(q->ID==b_id){
			q->quantity++;
			q->availability++;
		}
		q=q->next;
	}
	printf("Enter Return Date (dd/mm/yyyy):");
	scanf(" %[^\n]",rt_date);
	printf("\n");
	strcpy(p->ret_date,rt_date);

	p->fine = calculate_fine(p->due_date, rt_date);
	printf("Book Returned Successfully!!\n\n");
}

void return_personame(struct person **ptr,struct book **iptr){
	int b_id,flag=0;
	char p_name[50],rt_date[20];
	struct person *p=*ptr;
	struct book *q=*iptr;
	printf("Enter person name:");
	scanf("%s",p_name);
	struct person *cp=*ptr;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* PERSON ID | PERSON NAME        | BOOK ID | BOOK NAME           | AUTHOR NAME        | BOOK TYPE        | ISSUED DATE |  DUE DATE   | RETURN DATE | FINE   *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	while(p!=NULL){
		if(strcmp(p->personame,p_name)==0){
			flag=1;
			printf("\t\t* %9d | %-18.18s | %7d | %-18.18s | %-18.18s | %-15.15s | %-11.11s | %-11.11s | %-12.12s | %5d   *\n",p->personid,p->personame,p->bookid,p->bookname,p->authorname,p->booktype,p->iss_date,p->due_date,p->ret_date,p->fine);
			p=p->next;
		}
		else{
			p=p->next;
		}
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if(flag==0){
		printf("There is no person name present!!\n\n");
		return;
	}
	p=cp;
	printf("Enter Return Book ID:");
	scanf("%d",&b_id);
	printf("\n");
	while((p!=NULL)&&(p->bookid!=b_id)){
		p=p->next;
	}
	if(p==NULL){
		printf("There is no Book's Name was present!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* PERSON ID | PERSON NAME        | BOOK ID | BOOK NAME           | AUTHOR NAME        | BOOK TYPE        | ISSUED DATE  |  DUE DATE  | RETURN DATE  |FINE   *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	printf("\t\t* %9d | %-18.18s | %7d | %-18.18s | %-18.18s | %-15.15s | %-11.11s | %-11.11s | %-12.12s | %5d   *\n",p->personid,p->personame,p->bookid,p->bookname,p->authorname,p->booktype,p->iss_date,p->due_date,p->ret_date,p->fine);
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	while(q!=NULL){
		if(q->ID==b_id){
			q->quantity++;
			q->availability++;
		}
		q=q->next;
	}
	printf("Enter Return Date (dd/mm/yyyy):");
	scanf(" %[^\n]",rt_date);
	printf("\n");
	strcpy(p->ret_date,rt_date);
	p->fine = calculate_fine(p->due_date, rt_date);
	printf("Book Returned Successfully!!\n\n");
}

int calculate_fine(char due_date[], char return_date[]) {
	int due=atoi(due_date);
	int ret=atoi(return_date);
	int fine=ret-due;

	if(fine>0){
		return fine*50;
	}
	else{
		fine=0;
		return fine;
	}	
}

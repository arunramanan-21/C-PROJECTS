#include "struct_book.h"
#include<time.h>
void issue_book(struct person **ptr,struct book **iptr){
	//file_to_node1(ptr);
	char opt;
	if(*iptr==0){
		printf("There is no books to issue!!\n\n");
		return;
	}
	do{
	char issue_choice;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t         ISSUE A BOOK                             *\n");
	printf("\t\t*\t A/a\t: Issue By Book ID                        *\n");
	printf("\t\t*\t B/b\t: Issue By Book Name                      *\n");
	printf("\t\t*\t C/c\t: Issue By Author Name                    *\n");
	printf("\t\t*\t D/d\t: Back to Main Menu                       *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&issue_choice);
	printf("\n");
	if((issue_choice=='a')||(issue_choice=='A')){
			issue_id(ptr,iptr);

	}
	else if((issue_choice=='b')||(issue_choice=='B')){
			issue_bookname(ptr,iptr);
	}
	else if((issue_choice=='c')||(issue_choice=='C')){
			issue_authname(ptr,iptr);
	}
	printf("Do you want to Issue Another Book(s/n):");
	scanf(" %c",&opt);
	printf("\n");
	}while((opt=='s')||(opt=='S'));
	char op;
	printf("Do You Want to File Issued Details in File(s/n):");
	scanf(" %c",&op);
	printf("\n");
	if((op=='s')||(op=='S')){
		save_issuedbook(*ptr);
		printf("Details Saved Successfully!!\n\n");
		return;
	}
	else{
		printf("Details Not Saved!!\n\n");
		return;
	}
}
void issue_id(struct person **ptr,struct book **iptr){
	int bk_id;
	struct person *p=*ptr;
	struct book *q=*iptr;
	printf("Enter the Book's ID to issue:");
	scanf("%d",&bk_id);
	while((q!=NULL)&&(q->ID!=bk_id)){
		q=q->next;
	}
	if(q==NULL){
		printf("There is no Book's ID was present!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",q->ID, q->book_name, q->auth_name, q->book_type, q->quantity, q->availability);
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");

	if((q->quantity>0)&&(q->availability>0)){
		struct person *temp=(struct person *)malloc(sizeof(struct person));
		temp->bookid=bk_id;
		printf("Enter Person ID:");
		scanf("%d",&temp->personid);
		printf("\n");
		printf("Enter Person name:");
		scanf(" %[^\n]",temp->personame);
		strcpy(temp->bookname,q->book_name);
		strcpy(temp->authorname,q->auth_name);
		strcpy(temp->booktype,q->book_type);
		if(q->quantity>0){
			printf("Your book is here. Take it!!\n\n");
			q->quantity--;
			q->availability--;
		}
		else{
			if(q->availability<0)
				q->availability=0;
			printf("Only %d no.of books are available. Sorry!!\n\n",q->availability);
			return;
		}
		temp->bookquanti=q->quantity;
		temp->aval=q->availability;
		strcpy(temp->iss_date,curr_date());
		strcpy(temp->due_date,due_date());
		strcpy(temp->ret_date,"Not Returned");
		temp->next=NULL;
		if(*ptr==NULL){
			temp->next=*ptr;
			*ptr=temp;
		}
		else{
			struct person *last=*ptr;
			while(last->next!=0)
				last=last->next;
			temp->next=last->next;
			last->next=temp;
		}
	}
	else{
		printf("All Books are issued!!\n\n");
		return;
	}
}
void issue_bookname(struct person **ptr,struct book **iptr){
	char bk_name[50];
	int flag=0;
	struct person *p=*ptr;
	struct book *q=*iptr;
	printf("Enter the Book's Name to issue:");
	scanf(" %[^\n]",bk_name);
	struct book *cp=*iptr;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	while(q!=NULL){
		if(strcmp(q->book_name,bk_name)==0){
			flag=1;
			printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",q->ID, q->book_name, q->auth_name, q->book_type, q->quantity, q->availability);
			q=q->next;
		}
		else{
			q=q->next;
		}
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if(flag==0){
		printf("There is no Book with this name!!\n\n");
	}
	q=cp;
	int bo_id;
	printf("Enter which Book Id's Book to issue:");
	scanf("%d",&bo_id);
	while((q!=NULL)&&(q->ID!=bo_id)){
		q=q->next;
	}
	if(q==NULL){
		printf("There is no Book's Name was present!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",q->ID, q->book_name, q->auth_name, q->book_type, q->quantity, q->availability);
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if((q->quantity>0)&&(q->availability>0)){
		struct person *temp=(struct person *)malloc(sizeof(struct person));
		temp->bookid=q->ID;
		printf("Enter Person ID:");
		scanf("%d",&temp->personid);
		printf("\n");
		printf("Enter Person name:");
		scanf(" %[^\n]",temp->personame);
		strcpy(temp->bookname,q->book_name);
		strcpy(temp->authorname,q->auth_name);
		strcpy(temp->booktype,q->book_type);
		if(q->quantity>0){
			printf("Your book is here. Take it!!\n\n");
			q->quantity--;
			q->availability--;
		}
		else{
			if(q->availability<0)
				q->availability=0;
			printf("Only %d no.of books are available. Sorry!!\n\n",q->availability);
			return;
		}
		temp->bookquanti=q->quantity;
		temp->aval=q->availability;
		strcpy(temp->iss_date,curr_date());
		strcpy(temp->due_date,due_date());
		strcpy(temp->ret_date,"Not Returned");
		temp->next=NULL;
		if(*ptr==NULL){
			temp->next=*ptr;
			*ptr=temp;
		}
		else{
			struct person *last=*ptr;
			while(last->next!=0)
				last=last->next;
			temp->next=last->next;
			last->next=temp;
		}
	}
	else{
		printf("All Books are issued!!\n\n");
		return;
	}

}
void issue_authname(struct person **ptr,struct book **iptr){
	char at_name[50];
	int flag=0;
	struct person *p=*ptr;
	struct book *q=*iptr;
	printf("Enter the Author's Name to issue:");
	scanf(" %[^\n]",at_name);
	struct book *cp=*iptr;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	while(q!=NULL){
		if(strcmp(q->auth_name,at_name)==0){
			flag=1;
			printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",q->ID, q->book_name, q->auth_name, q->book_type, q->quantity, q->availability);
			q=q->next;
		}
		else{
			q=q->next;
		}
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if(flag==0){
		printf("There is no Book with this name!!\n\n");
		return;
	}
	q=cp;
	int bo_id;
	printf("Enter which Book Id's Book to issue:");
	scanf("%d",&bo_id);
	while((q!=NULL)&&(q->ID!=bo_id)){
		q=q->next;
	}
	if(q==NULL){
		printf("There is no Book's Author Name was present!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
	printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",q->ID, q->book_name, q->auth_name, q->book_type, q->quantity, q->availability);
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if((q->quantity>0)&&(q->availability>0)){
		struct person *temp=(struct person *)malloc(sizeof(struct person));
		temp->bookid=q->ID;
		printf("Enter Person ID:");
		scanf("%d",&temp->personid);
		printf("\n");
		printf("Enter Person name:");
		scanf(" %[^\n]",temp->personame);
		strcpy(temp->bookname,q->book_name);
		strcpy(temp->authorname,q->auth_name);
		strcpy(temp->booktype,q->book_type);
		if(q->quantity>0){
			printf("Your book is here. Take it!!\n\n");
			q->quantity--;
			q->availability--;
		}
		else{
			if(q->availability<0)
				q->availability=0;
			printf("Only %d no.of books are available. Sorry!!\n\n",q->availability);
			return;
		}
		temp->bookquanti=q->quantity;
		temp->aval=q->availability;
		strcpy(temp->iss_date,curr_date());
		strcpy(temp->due_date,due_date());
		strcpy(temp->ret_date,"Not Returned");
		temp->next=NULL;
		if(*ptr==NULL){
			temp->next=*ptr;
			*ptr=temp;
		}
		else{
			struct person *last=*ptr;
			while(last->next!=0)
				last=last->next;
			temp->next=last->next;
			last->next=temp;
		}
	}
	else{
		printf("All Books are issued!!\n\n");
		return;
	}

}

char* curr_date(void) {
    static char curr_date[9];   // dd/mm/yy → 8 chars + null
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    snprintf(curr_date, sizeof(curr_date),
             "%02d/%02d/%02d",
             tm_info->tm_mday,
             tm_info->tm_mon + 1,
             (tm_info->tm_year + 1900) % 100);

    return curr_date;
}

char* due_date(void) {
    static char ret_date[9];    // dd/mm/yy → 8 chars + null
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);

    tm_info.tm_mday += 7;
    mktime(&tm_info);           // Normalize the time structure

    snprintf(ret_date, sizeof(ret_date),
             "%02d/%02d/%02d",
             tm_info.tm_mday,
             tm_info.tm_mon + 1,
             (tm_info.tm_year + 1900) % 100);

    return ret_date;
}

#define MIN 1000
#define MAX 5000
#include<stdlib.h>
#include<unistd.h>
#include "struct_book.h"
void add_book(struct book **ptr){
        struct book *temp=(struct book *)malloc(sizeof(struct book));
        printf("Enter Book details:\n\n");
        printf("Enter Book Name:");
        scanf(" %[^\n]",temp->book_name);
        printf("\n");
        printf("Enter Author Name:");
        scanf(" %[^\n]",temp->auth_name);
        printf("\n");
        printf("Enter Book Type:");
        scanf(" %[^\n]",temp->book_type);
        printf("\n");
        printf("Enter Quantity:");
        scanf("%d",&temp->quantity);
	printf("\n");
	printf("Enter Avaliability:");
	scanf("%d",&temp->availability);
	printf("\n");
	temp->ID=rand_id();
        if(*ptr==0){
                temp->next=*ptr;
                *ptr=temp;
        }
        else{
        struct book *last=*ptr;
        while(last->next!=0)
                last=last->next;
        temp->next=last->next;
        last->next=temp;
        }
}

int rand_id(void){
	static int x=1;
	int id;
	srand(getpid()+(x++));
	id=rand()%(MAX-MIN+1)+MIN;
	return id;
}
void file_to_node(struct book **ptr){
        FILE *fs=fopen("Book_details.txt","r");
        if(fs==NULL)
                return;
        char s[100];
        fgets(s,sizeof(s),fs);
        while(1){
                struct book *temp=(struct book *)malloc(sizeof(struct book));
                if(fscanf(fs,"%d %s %s %s %d %d",&temp->ID,temp->book_name,temp->auth_name,temp->book_type,&temp->quantity,&temp->availability)!=6){
                        free(temp);
                        break;
                }
                temp->next=NULL;
                if(*ptr==NULL)
                        *ptr=temp;
                else{
                        struct book *last=*ptr;
                        while(last->next!=0)
                                last=last->next;
                        last->next=temp;
                }
        }
}
void file_to_node1(struct person  **ptr){
        FILE *fs=fopen("Issued_bookdetails.txt","r");
        if(fs==NULL)
                return;
        char s[100];
        fgets(s,sizeof(s),fs);
        while(1){
                struct person *temp=(struct person *)malloc(sizeof(struct person));
                if(fscanf(fs,"%d %s %d %s %s %s %s %s %s %d",&temp->personid,temp->personame,&temp->bookid,temp->bookname,temp->authorname,temp->booktype,temp->iss_date,temp->due_date,temp->ret_date,&temp->fine)!=10){
                        free(temp);
                        break;
                }
                temp->next=NULL;
                if(*ptr==NULL)
                        *ptr=temp;
                else{
                        struct person *last=*ptr;
                        while(last->next!=0)
                                last=last->next;
                        last->next=temp;
                }
        }
}


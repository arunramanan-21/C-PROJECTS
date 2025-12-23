#include "struct_book.h"
void save_book(struct book *ptr){
        char ch;
        //int r=0;
        if(ptr==0){
                printf("There is no file to save!!\n\n");
                return;
        }
        FILE *fs=fopen("Book_details.txt","r");
        if(fs==NULL){
                //fclose(fs);
                fs=fopen("Book_details.txt","w");
		fprintf(fs, "%-5s %-20s %-20s %-15s %-10s %-12s\n","ID", "BOOK NAME", "AUTHOR NAME", "BOOK TYPE", "QUANTITY", "AVAILABILITY");
                goto file_save;
        }
        else{
                fs=fopen("Book_details.txt","w");
		fprintf(fs, "%-5s %-20s %-20s %-15s %-10s %-12s\n","ID", "BOOK NAME", "AUTHOR NAME", "BOOK TYPE", "QUANTITY", "AVAILABILITY");
                file_save:
                while(ptr!=0){
			fprintf(fs, "%-5d %-20.20s %-20.20s %-15.15s %6d %9d\n",ptr->ID, ptr->book_name, ptr->auth_name, ptr->book_type, ptr->quantity, ptr->availability);
                        ptr=ptr->next;
                }
                fclose(fs);
        }
	printf("Book Details Saved Successfully\n\n");
}
void save_n_exit(struct book *ptr){
	char ex_op;
	if(ptr==0){
		printf("There is no record to save!!\n\n");
		return;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t*\t Enter                                *\n");
        printf("\t\t*\t S/s\t: Save And Exit               *\n");
        printf("\t\t*\t E/e\t: Exit Without Saving         *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
        printf("Enter Your Choice:");
	scanf(" %c",&ex_op);
	printf("\n");
	if((ex_op=='s')||(ex_op=='S')){
		save_book(ptr);
		printf("!!File Saved Successfully!Good Bye !!\n");
	}
	else if((ex_op=='e')||(ex_op=='E')){
		printf("Exiting Without Save !!\n");
		return;
	}
}
void save_issuedbook(struct person *p){
        char ch;
        //int r=0;
        if(p==0){
                printf("There is no file to save!!\n\n");
                return;
        }
        FILE *fs=fopen("Issued_bookdetails.txt","r");
        if(fs==NULL){
                //fclose(fs);
                fs=fopen("Issued_bookdetails.txt","w");
		fprintf(fs, "%-10s %-20s %-8s %-20s %-20s %-15s %-12s %-12s %-12s %-6s\n", "PERSON ID", "PERSON NAME", "BOOK ID", "BOOK NAME", "AUTHOR NAME","BOOK TYPE","ISSUE DATE", "DUE DATE", "RETURN DATE", "FINE");
                goto file_save;
        }
        else{
                fs=fopen("Issued_bookdetails.txt","w");
		fprintf(fs, "%-10s %-20s %-8s %-20s %-20s %-15s %-12s %-12s %-12s %-6s\n", "PERSON ID", "PERSON NAME", "BOOK ID", "BOOK NAME", "AUTHOR NAME","BOOK TYPE","ISSUE DATE", "DUE DATE", "RETURN DATE", "FINE");
                file_save:
                while(p!=0){
			fprintf(fs, "%-10d %-20.20s %-8d %-20.20s %-20.20s %-15.15s %-12.12s %-12.12s %-12.12s %4d\n",p->personid,p->personame,p->bookid,p->bookname,p->authorname,p->booktype,p->iss_date,p->due_date,p->ret_date,p->fine);
                        p=p->next;
                }
                fclose(fs);
        }
	printf("Issued Book Details Saved Successfully\n\n");
}


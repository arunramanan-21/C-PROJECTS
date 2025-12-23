#include "struct_book.h"
void view_listbook(struct person *ptr){
//	file_to_node1(&ptr);	
	if(ptr==0){
		printf("There is no issue books to view!!\n");
		return;
	}
	else{
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
		printf("\t\t* PERSON ID | PERSON NAME        | BOOK ID | BOOK NAME           | AUTHOR NAME        | BOOK TYPE        | ISSUED DATE |  DUE DATE   | RETURN DATE | FINE   *\n");
		printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");

		while(ptr!=0){
			printf("\t\t* %9d | %-18.18s | %7d | %-18.18s | %-18.18s | %-15.15s | %-11.11s | %-11.11s | %-12.12s | %5d   *\n",ptr->personid,ptr->personame,ptr->bookid,ptr->bookname,ptr->authorname,ptr->booktype,ptr->iss_date,ptr->due_date,ptr->ret_date,ptr->fine);
			ptr=ptr->next;
		}
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	}
}


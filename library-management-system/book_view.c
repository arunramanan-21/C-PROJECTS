#include "struct_book.h"
void view_book(struct book *ptr){
	if(ptr==0){
		printf("There is no books to view!!\n");
		return;
	}
	else{
	 	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        	printf("\t\t* ID  | BOOK NAME          | AUTHOR NAME        | BOOK TYPE        | QUANTITY | AVAILABILITY  *\n");
        	printf("\t\t*_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _*\n");
		while(ptr!=0){
			 printf("\t\t* %3d | %-20.20s | %-20.20s | %-15.15s | %8d | %8d  *\n",ptr->ID, ptr->book_name, ptr->auth_name, ptr->book_type, ptr->quantity, ptr->availability);
			ptr=ptr->next;
		}
		printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");

	}
}


#include "struct_book.h"
/*#include<stdio.h>
#include<string.h>
#include "book_add.c"
#include "book_view.c"
#include "book_save.c"
#include "book_search.c"
#include "book_update.c"
#include "book_remove.c"
#include "book_issue.c"
#include "listbook_view.c"
#include "book_return.c"*/
int main(){
	struct book *hptr=0;
	struct person *pptr=0;
	file_to_node(&hptr);
	file_to_node1(&pptr);
        char choice;
	system("clear");
        while(1){
       	printf("\t\t* * * * * BOOK MANAGEMENT  MENU * * * * *\n");
        printf("\t\t*  A/a\t:Add New Book\t\t\t*\n");
        printf("\t\t*  U/u\t:Update A Book\t\t\t*\n");
        printf("\t\t*  D/d\t:Remove A Book\t\t\t*\n");
        printf("\t\t*  S/s\t:Search A Book\t\t\t*\n");
        printf("\t\t*  V/v\t:View All Books\t\t\t*\n");
        printf("\t\t*  I/i\t:Issue Book\t\t\t*\n");
        printf("\t\t*  R/r\t:Return Book\t\t\t*\n");
        printf("\t\t*  L/l\t:List Issued Books\t\t*\n");
	printf("\t\t*  Z/z\t:Save\t\t\t\t*\n");
        printf("\t\t*  E/e\t:Exit\t\t\t\t*\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * * *\n\n");

	printf("Enter Your Choice:");
	scanf(" %c",&choice);
	printf("\n");
        if((choice=='a')||(choice=='A')){
                add_book(&hptr);
                system("clear");
        }
	else if((choice=='u')||(choice=='U')){
                update_book(&hptr);
        }
	else if((choice=='d')||(choice=='D')){
                remove_book(&hptr);
        }

	else if((choice=='s')||(choice=='S')){
                search_book(hptr);
	}
	else if((choice=='v')||(choice=='V')){
                view_book(hptr);
        }
	else if((choice=='i')||(choice=='I')){
                issue_book(&pptr,&hptr);
		save_book(hptr);
	//	save_issuedbook(pptr);
        }
	else if((choice=='r')||(choice=='R')){
		return_book(&pptr,&hptr);
		save_book(hptr);
	}
	else if((choice=='l')||(choice=='L')){
		view_listbook(pptr);
	}
	else if((choice=='z')||(choice=='Z')){
                save_book(hptr);
        }
	else if((choice=='e')||(choice=='E')){
                save_n_exit(hptr);
		return 0;
        }
	}
}

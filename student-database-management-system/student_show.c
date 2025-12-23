//#include "struct_init.h"
void print_student(struct st *ptr){
	if(ptr==0){
		printf("THere is no record to show!!\n\n");
		return;
	}
	printf("\t\t* * * *ROLL * * * * * NAME * * * * *MARKS * * * *\n");
	while(ptr!=0){
		printf("\t\t*	%d	      %s	    %0.2f 	*\n",ptr->rollno,ptr->name,ptr->mark);
		ptr=ptr->next;
	}
        printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * *\n\n");	
}
void rev_print(struct st *ptr){
	if(ptr!=0){
		rev_print(ptr->next);
		printf("\t\t*	%d            %s	    %0.2f	*\n",ptr->rollno,ptr->name,ptr->mark);
	}
}


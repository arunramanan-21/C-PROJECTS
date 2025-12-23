//#include "struct_init.h"
#include<string.h>
int count(struct st *);
void sort_student(struct st *ptr){
	char sort_choice,tempname[50];
	int i,j,c;
	float tempmark;
	if(ptr==0){
		printf("There is no record to sort!!\n\n");
		return;
	}
	c=count(ptr);
	struct st *temp=ptr;
	struct st **arr=(struct st **)malloc(c*sizeof(struct st *));
	for(i=0;i<c;i++){
		arr[i]=temp;
		temp=temp->next;
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t*\t Enter                                *\n");
	printf("\t\t*\t N/n\t: Sort With Name              *\n");
	printf("\t\t*\t M/m\t: Sort With Marks             *\n");
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("Enter Your Choice:");
	scanf(" %c",&sort_choice);
	for(i=0;i<c;i++){
		for(j=i+1;j<c;j++){
			if((sort_choice=='n')||(sort_choice=='N')){
				if((strcmp(arr[i]->name,arr[j]->name))>0){
					struct st *p=arr[i];
					arr[i]=arr[j];
					arr[j]=p;
				}
			}
			else if((sort_choice=='m')||(sort_choice=='M')){
				if(arr[i]->mark < arr[j]->mark){
					struct st *p=arr[i];
					arr[i]=arr[j];
					arr[j]=p;
				}
			}
			else{
				return;
			}
		}
	}
	printf("Sorted the Records Successfully!!\n");
	printf("\t\t* * * *ROLL * * * * * NAME * * * * *MARKS * * * *\n");
	for(i=0;i<c;i++){
		printf("\t\t*	%d	      %s           %0.2f	*\n",arr[i]->rollno,arr[i]->name,arr[i]->mark);
	}
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
}
int count(struct st *ptr){
	int c=0;
	while(ptr!=0){
		++c;
		ptr=ptr->next;
	}
	return c;
}


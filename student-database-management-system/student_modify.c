//#include "struct_init.h"
#include<string.h>
void modify_student(struct st **ptr){
	if(*ptr==0){
		printf("There is no record to modify!!\n");
		return;
	}
	int sear_roll,mod_roll;
	char sear_choice,mod_choice;
	char sear_name[50],mod_name[50];
	float mod_mark;
	//struct st *temp=*ptr;
	//struct st *temp1=*ptr;
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t*\t Enter which record to search for modification    *\n");
        printf("\t\t*\t R/r\t: To Search Rollno                        *\n");
        printf("\t\t*\t N/n\t: To Search Name                          *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
        printf("Enter Your Choice:");
	scanf(" %c",&sear_choice);
	printf("\n");
	if((sear_choice=='r')||(sear_choice=='R')){
		printf("Enter the rollno:");
		scanf("%d",&sear_roll);
		struct st*temp=*ptr;
		while(temp!=0){
			if(temp->rollno==sear_roll){
				printf("%d %s %0.2f\n",temp->rollno,temp->name,temp->mark);
				print_console();
				scanf(" %c",&mod_choice);
				if((mod_choice=='n')||(mod_choice=='N')){
					printf("Enter the Name:");
					scanf("%s",mod_name);
					strcpy(temp->name,mod_name);
					break;
				}
				else if((mod_choice=='m')||(mod_choice=='M')){
					printf("Enter the Mark:");
					scanf(" %f",&mod_mark);
					temp->mark=mod_mark;
					break;
				}
			}
			else if(temp->rollno!=sear_roll){
				temp=temp->next;
			}
			/*else{
				printf("Rollno not present!!,Please enter valid rollno\n");
				break;
			}*/
		}
	}
	else if((sear_choice=='n')||(sear_choice=='N')){
		printf("Enter the Name:");
		scanf("%s",sear_name);
		struct st *temp=*ptr;
		while(temp!=0){
			if(strcmp(temp->name,sear_name)==0){
				printf("%d %s %0.2f\n",temp->rollno,temp->name,temp->mark);
				temp=temp->next;
			}
			else if(strcmp(temp->name,sear_name)!=0){
				temp=temp->next;
			}
		}
		printf("Enter which rollno to modify:");
		scanf("%d",&mod_roll);
		struct st *temp1=*ptr;
		while(temp1!=0){
			if(temp1->rollno==mod_roll){
				printf("%d %s %0.2f\n",temp1->rollno,temp1->name,temp1->mark);
				print_console();
				scanf(" %c",&mod_choice);
				if((mod_choice=='n')||(mod_choice=='N')){
                                        printf("Enter the Name:");
                                        scanf("%s",mod_name);
                                        strcpy(temp1->name,mod_name);
                                        break;
                                }
                                else if((mod_choice=='m')||(mod_choice=='M')){
                                        printf("Enter the Mark:");
                                        scanf(" %f",&mod_mark);
                                        temp1->mark=mod_mark;
                                        break;
                                }
                        }
                        else if(temp1->rollno!=sear_roll){
                                temp1=temp1->next;
                        }
		}
		printf("Modification done Siccessfully!!\n\n");
	}
}
void print_console(void){
	printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
        printf("\t\t*\t Enter which record to modification   *\n");
        printf("\t\t*\t N/n\t: To Search Name              *\n");
        printf("\t\t*\t M/m\t: Marks Based                 *\n");
        printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
        printf("Enter Your Choice:");
}


//#include "struct_init.h"
void save_student(struct st *ptr){
	char ch;
	//int r=0;
	if(ptr==0){
		printf("There is no file to save!!\n\n");
		return;
	}
	FILE *fs=fopen("Student_details.txt","r");
	if(fs==NULL){
		//fclose(fs);
		fs=fopen("Student_details.txt","w");
		fprintf(fs," Roll\t\t Name\t\t Marks\n");
		goto file_save;
	}
	else{
		fs=fopen("Student_details.txt","w");
		fprintf(fs," Roll\t\t Name\t\t Marks\n");
                file_save:
		while(ptr!=0){
			fprintf(fs," %d\t\t %s\t\t %0.2f\n",ptr->rollno,ptr->name,ptr->mark);
			ptr=ptr->next;
		}
		fclose(fs);
	}
}
void save_n_exit(struct st *ptr){
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
		save_student(ptr);
		printf("!!File Saved Successfully!Good Bye !!\n");
	}
	else if((ex_op=='e')||(ex_op=='E')){
		printf("Exiting Without Save !!\n");
		return;
	}
}



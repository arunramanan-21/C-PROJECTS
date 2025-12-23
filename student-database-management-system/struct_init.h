#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st{
	int rollno;
	char name[50];
	float mark;
	struct st *next;
};
//for adding student records
void add_student(struct st **,int);
//for printing details
void print_student(struct st *);
//for reverse print
void rev_print(struct st *);
//for save student records in file
void save_student(struct st *);
//for file to node transfer
void file_to_node(struct st **,int *);
//for delete particular student details
void delete_student(struct st **);
void delete_roll(struct st **);
void delete_name(struct st **);
//for modify records
void modify_student(struct st **);
void print_console(void);
//for sorting the records
void sort_student(struct st *);
//int count (struct st *);
//for delete all data
void delete_all(struct st **);
//for save and exit
void save_n_exit(struct st *);

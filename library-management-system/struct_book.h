#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
	int ID;
	char book_name[50];
	char auth_name[50];
	char book_type[20];
	int quantity;
	int availability;
	struct book *next;
};
struct person{
	int bookid;
	char bookname[50];
	int personid;
	char personame[50];
	char authorname[50];
	char booktype[20];
	int bookquanti;
	int aval;
	char iss_date[50];
	char due_date[50];
	char ret_date[50];
	int fine;
	struct person *next;
};
void add_book(struct book **);
int rand_id(void);
void file_to_node(struct book **);
void file_to_node1(struct person **);
void view_book(struct book *);
void save_book(struct book *);
void search_book(struct book *);
void update_book(struct book **);
void print_console(void);
void remove_book(struct book **);
void remove_id(struct book **);
void remove_bookname(struct book **);
void save_n_exit(struct book *);
void issue_book(struct person **,struct book **);
void issue_id(struct person **,struct book **);
void issue_bookname(struct person **,struct book **);
void issue_authname(struct person **,struct book **);
char* curr_date(void);
char* due_date(void);
void view_listbook(struct person *);
void save_issuedbook(struct person *);
void return_book(struct person **,struct book **);
void return_pid(struct person **,struct book **);
void return_personame(struct person **,struct book **);
int calculate_fine(char due_date[], char return_date[]);

/* 
 * Lab 8 -- Boba Shop Command w/ Recursive Functions
 * COEN 11 - Winter 2022
 */

//inputs libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 10

#define true 1
#define false 0

#define NODE struct node

//declare struct
struct node
{
    char cname[MAX_NAME_LENGTH];
    int osize;
    NODE *next;
} ;

//global variables
extern NODE *head;
extern NODE *tail;

//declare functions
void insert(char *name, int ordersize);
void fulfill(int removeDrinks);
void list(void);
int check_dup(char *name);
void read(char *fname);
void save(char *fname);
void free_nodes(NODE *p);
void reverse(NODE *p);
int list_length(NODE *p);
 

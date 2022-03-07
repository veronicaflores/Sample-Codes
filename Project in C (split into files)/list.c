/*
 * Lab 9 -- Boba Shop Command w/ Recursive Functions
 * COEN 11 - Winter 2022
 */

#include "lab8.h"

//insert function
void insert(char *name, int ordersize)
{
	FILE *source;
	//define variables
	NODE *p;

	if((p = (NODE *) malloc (sizeof(NODE))) == NULL) //checks if there is available room for orders
	{
	    printf("There is no orders at this time, check back again later!\n");
	    return;
	}

	p->osize = ordersize;
	strcpy(p->cname, name); 
	
	if(head==NULL)
	{
	    head = tail = p;
	    tail->next = NULL;
	}   
	else
	{
	    tail->next = p;
	    tail = p;
	}	    
}

//fulfill function
void fulfill(removeDrinks)
{
	NODE *p, *q;

	if(head==NULL)
	{
	    printf("There are no orders right now!\n");
	    return;
	}
	    
	p=q=head;	
	
	while(p != NULL)
	{
	    if(removeDrinks!=0)
	    {
		if(p->osize <= removeDrinks)
		{
		    removeDrinks = removeDrinks - p->osize;
		    printf("%s, %d drinks (deleted)\n", p->cname, p->osize);
		    if(p==head)
		    {
			head = p->next;
		    }
		    else
		    {
			q->next = p->next;
		    }
		    free(p);
		    return;
		}
		q = p;
		p = p->next;
	    }
	    else
	    {
		printf("Completed all possible orders!\n");
		break;
	    }
	}
}

//list function
void list(void)
{
	NODE *p;

	if(head==NULL) //in case there are no orders to lost
	{
	    printf("There are no orders currently!\n");
	    return;
	}

	p = head;
	//lisets names of customers and number of drinks
	while(p!=NULL) 
	{
	    printf("%s, %d drinks\n", p->cname, p->osize);
	    p=p->next;
	} 		
}

//check name duplicates function
int check_dup(char *name)
{
	int flag = 0;
	NODE *p;
	
	p=head;

	while(p!=NULL)
	{
	    if((strcmp(name, p->cname)==0)) //checks to see if the input of the user is a name duplicate
	    {
		printf("That name is already taken!\n");
		flag = 1;
		break;
	    }
	    else
	    {
		p=p->next;
	
	    }
	}
	return flag;
 }
  
//search size of an order
void size(int ordersize)
{
    NODE *p;

    if(head==NULL) //tells the worker that there are no orders yet
    {
	printf("There are no orders currently!\n");
	return;
    }

    p=head;

    while(p!=NULL) //traverses array
    {
    	if(ordersize >= p->osize) //checks if the size of an order fits the workers criteria
	{
	    printf("%s, %d drinks\n", p->cname, p->osize); //prints out all orders that fit the criteria
	}
	p = p->next;
    }
}

//reads the file
void read(char *fileName)
{
    char readC[20];
    int readI;
    FILE *source;
    
    if((source = fopen(fileName, "r")) == NULL)
    {
	printf("Creating the file %s...\n", fileName);
    }
    else
    {
	fseek(source, 37, SEEK_SET);
	while(fscanf(source, "%s\t%d\n", readC, &readI) == 2)
	{
	    insert(readC, readI);
	}
	fclose(source);
    }
}

//saves the file
void save(char *fileName)
{
    FILE *source;
    NODE *p;

    source = fopen(fileName, "w");
    fprintf(source, "Name\tGroup Size\n----------------------\n");
    p=head;
    while(p!=NULL)
    {
	fprintf(source, "%s\t%d\n", p->cname, p->osize);
	p = p->next;
    }
    fclose(source);
}

//frees nodes after quitting
void free_nodes(NODE *p)
{
    if(p == NULL)
    {
	return;
    }
    if(p->next == NULL)
    {
	free(p);
	return;
    }
    else if(p->next != NULL)
    {
	free_nodes(p->next);
	free(p);
    }
}

//reverse list function
void reverse(NODE *p)
{
    if(p == NULL)
    {
	return;
    }
    reverse(p->next);
    printf("%s, %d drinks\n", p->cname, p->osize);
}

//display length of list
int list_length(NODE *p)
{
    if(p == NULL)
    {
	return 0;
    }
    return (1 + list_length(p->next));
}


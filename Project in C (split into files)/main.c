/*
 * Lab 8 -- Boba Shop Command w/ Recursive Functions
 * COEN 11
 */

#include "lab8.h"

//global variables
NODE* head = (NODE *)NULL;
NODE* tail = (NODE *)NULL;

//main function
int main(int argc, char *argv[])
{
    FILE *source;
    int answer; //answer for user input
    char name[20];
    int ordersize, removeDrinks;
    if(argc == 1)
    {
	printf("The name of the file is missing!\n");
	return 0;
    }

    read(argv[1]);

    while(true)
    {
	printf("Boba Shop Command Line \n 1 - Insert Order \n 2 - Fulfill Order(s) \n 3 - List Order(s) \n 4 - List Based on Size \n 5 - Reverse List \n 6 - Display Length of List \n 0 - Save & Quit\n"); //print the menu options
	scanf("%d", &answer); //get the user input

    switch(answer)
    {
	case 1: //Insert an order
	    printf("What is the name on the order?\n");
	    scanf("%s", name);
	    if(check_dup(name) == 0)
	    {
		printf("How many drinks is the order?\n");
		scanf("%d", &ordersize);
		insert(name, ordersize);
	    }
	    break;

	case 2: //Fulfill an order
	    printf("How many drinks did you make?\n"); //takes in drinks made
	    scanf("%d", &removeDrinks);
	    fulfill(removeDrinks);
	    break;
	
	case 3: //List the Orders
	    list();
	    break;

	case 4: //List Based on Size
	    printf("You want an order equal to or less than what number?\n"); //asks for worker input
	    scanf("%d", &ordersize);
	    size(ordersize);
	    break;
	
	case 5: //Reverse List
	    reverse(head);
	    break;

	case 6: //Display List Length
	    printf("The list is %d node(s) long\n", list_length(head));
	    break;

	case 0: //Quit order page
	    save(argv[1]);
	    free_nodes(head);
	    printf("List Saved! Thank you!\n");
	    return false;
	
	default:
	    printf("No Option\n"); //For any option other than listed
	    break;
    }
    }
}

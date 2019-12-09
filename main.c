#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itinerary.h"
#include "main.h"

int main(int argc, char *argv[])
{
    /* declare all your variables here */
    int choice;
    Destination *head = NULL;
    Destination *newNode = NULL;
    char airCodeChoice[4];
    char key[4] = "ZZZ";
    
    while(1)
    {
    /* Call the function to print the menu */
        printMenu();
        /* Get the menu choice from the user */
        scanf("%d", &choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                /* 1) ask the user to enter the airport code for the destination
                    2) check to see if the airport code exists in the list with find(), if it does, print an error and break;
                    3) if the airport code does not exist, call create() to make a new destination node
                    4) if the list is empty, call insertAfter() and insert the node to start a new linked list
                    5) if the list is not empty, ask the user where in the list they want to add the node. The user will enter the airport code for which this new node will be added AFTER in the linked list. Then, call insertAfter() with the user provided key code to insert it into the linked list. Note that if the user enters ZZZ as the airport code, it will add the new node to the beginning and if the user enters an invalid airport code, it adds the new node to the end.
                    6) Print a message saying the destination was added
                */
                printf("Enter the airport code for the destination:");
                scanf("%s", airCodeChoice);

                if(head != NULL) {
                    newNode = find(head, airCodeChoice);
                    if(newNode == NULL) {
                        printf("ERROR: Destination already exists!\n");
                        break;
                    }

                    printf("Enter the airport code for which new destination is added after. Enter ZZZ to add to beginning of list:");
                    scanf("%s", key);
                }

                newNode = create(airCodeChoice);

                head = insertAfter(head, newNode, key);

                printf("%s added\n", newNode->airCode);
                //free(newNode);
                break;
            case 2:
                /* 1) ask the user to enter an airport code for the destination
                    2) check to see if the airport code exists in the list with find(), if it does not exist, print an error;
                    3) if it exists, call remove() to remove the airport code from the list  
                    4) print a message saying the destination was removed
                */
                printf("Enter Airport Code to remove: ");
                scanf("%s", airCodeChoice);

                newNode = find(head, airCodeChoice);
                if(newNode == NULL) {
                    head = removeNode(head, airCodeChoice);
                }
                else {
                    printf("ERROR: Destination does not exist!\n");
                }

                //free(newNode);
                break;
            case 3:
                /* print message to print all the destinations in the itinerary and call print() */
                printDestinations(head);
                break;
            case 4:
                /* print message to print the itinerary and call printItinerary() */
                printItinerary(head);
                break;
            case 5:
                /* call destroy() and print the message that the itinerary has been cleared */
                head = destroy(head);

                printf("Itinerary cleared!\n");
                break;
            case 0:
            default:
                /* call destroy() and print a farewell message*/
                head = destroy(head);

                printf("Good-bye!\n");
                return 0;
        }
    }
    return 0;
}

/*
printMenu
---------------------------
This function prints the main menu.
Returns: Nothing
*/
void printMenu() {
    printf("\n#########################################\n");
    printf("#            Trip Planner Menu          #\n");
    printf("#########################################\n");
    printf("\t1 - Insert a Destination\n");
    printf("\t2 - Remove a Destination\n");
    printf("\t3 - Print Destinations\n");
    printf("\t4 - Print Itinerary\n");
    printf("\t5 - Clear Itinerary\n");
    printf("\t0 - Quit\n");
    printf("Enter your selection: ");
}

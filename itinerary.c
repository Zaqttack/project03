#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itinerary.h"

Destination* create(char *code) {
    Destination* newNode = (Destination*)malloc(sizeof(Destination));
    if(newNode == NULL) {
        printf("Was not able to malloc a newNode\n");
        return NULL;
    }

    strcpy(newNode->airCode, code);
    newNode->next = NULL;

    return newNode;
}

Destination* insertAfter(Destination *head, Destination *node, char *key) {
    if(head == NULL) {
        return node;
    }

    Destination *tmp = (Destination*)malloc(sizeof(Destination));
    tmp = head;

    if(strcmp(key, "ZZZ") == 0) {
        node->next = head;
        head = node;

        return head;
    }
    else {
        while(tmp != NULL) {
            if(strcmp(tmp->airCode, key) == 0) {
                node->next = tmp->next;
                tmp->next = node;

                return head;
            }

            if(tmp->next == NULL) {
                tmp->next = node;
                node->next = NULL;

                return head;
            }

            tmp = tmp->next;
        }

        return head;
    }
}

Destination* find(Destination *head, char *key) {
    Destination *tmp = (Destination*)malloc(sizeof(Destination));
    tmp = head;

    while(tmp != NULL) {
        if(strcmp(tmp->airCode, key) == 0) {
            return NULL;
        }

        tmp = tmp->next;
    }
    return head;
}

Destination* removeNode(Destination *head, char *key) {
    Destination *temp = head;
    Destination *prev;

    if (temp == NULL)
        return temp; 

    if (strcmp(temp->airCode, key) == 0) { 
        head = temp->next;
        free(temp);
        return NULL; 
    }

    while (strcmp(temp->airCode, key) != 0) { 
        prev = temp; 
        temp = temp->next; 
    } 

    prev->next = temp->next; 

    free(temp);
    return head;
} 

void printDestinations(Destination *head) {
    Destination *tmp = (Destination*)malloc(sizeof(Destination));
    tmp = head;

    if(tmp == NULL) {
        printf("No Locations added!\n");
        return;
    }

    printf("Destinations in Itinerary\n");
    while(tmp != NULL) {
        printf("%s\n", tmp->airCode);
        
        tmp = tmp->next;
    }
}

void printItinerary(Destination *head) {
    Destination *tmp = (Destination*)malloc(sizeof(Destination));
    tmp = head;

    if(tmp == NULL) {
        printf("No Locations added!\n");
        return;
    }

    printf("Itinerary\n");
    while(tmp->next != NULL) {
        printf("%s-%s\n", tmp->airCode, tmp->next->airCode);

        tmp = tmp->next;
    }
}

Destination* destroy(Destination *head) {
    Destination *prev = (Destination*)malloc(sizeof(Destination));
    prev = head;

    while (head != NULL) {
        head = head->next;

        free(prev);
        prev = head;
    }

    head = NULL;
    return head;
}
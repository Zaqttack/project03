
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

    printf("%s added\n", newNode->airCode);
    return newNode;
}

Destination* insertAfter(Destination *head, Destination *node, char *key) {
    if(head == NULL) {
        return node;
    }

    Destination *ptr = head;
    printf("Enter the airport code for which new destination is added after. Enter ZZZ to add to beginning of list:");
    fgets(key, 4, stdin);

    if(strcmp(key, "ZZZ") == 0) {
        ptr->next = head;
        head = ptr;

        return head;
    }
    else {
        while(ptr->next != NULL) {
            if(strcmp(ptr->airCode, key) == 0)
                node = ptr;
            ptr = ptr->next;
        }
        ptr->next = node;

        return head;
    }

    return head;
}

Destination* find(Destination *head, char *key) {
    while(head != NULL) {
        //printf("comparing %s and %s\n", head->airCode, key);
        if(strcmp(head->airCode, key) == 0) {
            return NULL;
        }

        head = head->next;
    }
    return head;
}

Destination* removeNode(Destination *head, char *key) {

}

void print(Destination *head) {

}

void printItinerary(Destination *head) {

}

Destination* destroy(Destination *head) {

}
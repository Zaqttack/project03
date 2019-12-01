#ifndef ITINERARY_H 
#define ITINERARY_H

/* Your Destination struct declaration will go here */
typedef struct Destination {
    char airCode[4];
    struct Destination *next;
} Destination;


/* Prototypes have been provided to you. No further comments or code is needed here. */
Destination* create(char*);
Destination* insertAfter(Destination*, Destination*, char*);
Destination* find(Destination*, char*);
Destination* removeNode(Destination*, char*);
void print(Destination*);
void printItinerary(Destination*);
Destination* destroy(Destination*);

#endif
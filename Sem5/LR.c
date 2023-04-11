#include <stdlib.h>
#include <stdio.h>

struct node_t {
  struct node_t *next;
  int data;
};

struct node_t * reverse(struct node_t *top) {
    
    struct  node_t* new = NULL;
    struct node_t* first;

    if(top == NULL)
        return NULL;
    
    while (top -> next != NULL)
    {
        first = top -> next;
        top -> next = new;
        new = top;
        top = first;
    }
    
    return top;
}


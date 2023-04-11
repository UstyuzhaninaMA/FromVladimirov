#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct tree_t{
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

int check(struct tree_t *top, int min, int max)
{
    int totalData;

    if(top == NULL)
    {
        return 1;
    }

    totalData = top->data;

    if((totalData < min) || (totalData > max))
    {
        return 0;
    }
    
    if((check(top->left, min, totalData))&&(check(top->right, totalData, max)))
    {
        return 1;
    }
    return 0;
}

int check_is_bst(struct tree_t *top) {
    return check(top, 0, INT_MAX);
}
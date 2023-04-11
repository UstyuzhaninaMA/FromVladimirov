#include <stdlib.h>
#include <stdio.h>

#include <limits.h>

int check_top(struct tree_t *top, int start, int end);

int check_is_bst(struct tree_t *top)
{
    return check_top(top, -1, INT_MAX);
}

int check_top(struct tree_t *top, int start, int end)
{
    int res = 1;

    if (top == NULL)
    {
        return 1;
    }

    if (top->data > end || (*top).data < start)
    {
        return 0;
    }
    else
    {
        if (check_top((*top).left, start, (*top).data) == 0)
        {
            res = 0;
        }
        if (check_top((*top).right, (*top).data, end) == 0)
        {
            res = 0;
        }
        return res;
    }
}

#include <stdlib.h>

struct node_t
{
    struct node_t *next;
    int data;
};

int list_is_a_loop(struct node_t *top)
{

    struct node_t *fast;
    struct node_t *slow;

    if (top == NULL)
    {
        return 0;
    }
    if (top->next == NULL)
    {
        return 0;
    }

    slow = top;
    fast = top->next;

    while (1)
    {
        if (fast->next == NULL)
        {
            return 0;
        }
        if ((fast->next == slow) || (fast->next == slow->next))
        {
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
}
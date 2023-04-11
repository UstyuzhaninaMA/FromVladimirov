#include <stdlib.h>

typedef int (*get_hash_t)(const char *s);

int ncollisions(char **strs, int n, get_hash_t f)
{
    int index;
    int sum;
    int * collision;
    collision = (int*)calloc(HASH_MAX, sizeof(int));

    sum = 0;

    for(index = 0; index < n; index++)
    {
        collision[f(strs[index])] ++;
    }
    
    for(index = 0; index < HASH_MAX; index++)
    {
        if(collision[index] != 0)
        {
            sum += collision[index] - 1;
        }
    }

    return sum;
}
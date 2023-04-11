#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int sum = 0; 
    char total;
    while((total = getchar()) && (total != EOF))
    {
        sum += total;
    }
    printf("%d", sum);
}
#include <stdlib.h>
#include <stdio.h>

int find_bite(char number);

int arrpopcount(const unsigned char *parr, int len)
{
    int index;
    int sum = 0;
    for (index = 0; index < len; index++)
    {
        sum += find_bite(parr[index]);
    }
    return sum;
}

int find_bite(char number)
{
    int inx = 0;
    char sum = 0;
    while ((inx < sizeof(char)*8))
    {
        if (number & (1 << inx))
        {
            sum += 1;
        }
        inx += 1;
    }
    return sum;
}

int main()
{
    unsigned char arr[3] = {1, 8, 32};
    printf("%d\n", arrpopcount(arr, 3));
    return 0;
}
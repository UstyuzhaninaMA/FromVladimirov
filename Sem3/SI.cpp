#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int moveright(int *arr, int key, int last)
{
    int pos = -1;
    int ind = -1;
    for ( pos = 0; pos < last; pos++)
    {
        if ( arr[pos] > key) {  
            break;
        }
    }
    if (pos == -1) {
        return pos;
    }
    for ( ind = last; ind > pos; ind--) {
        arr[ind] = arr[ind - 1];
    }

    return pos;
}



int main()
{
    int arr[10] = {1, 1, 3, 3, 4, 1, 9, 4, 9, 4};
    int key = 1;
    int last = 5;

    printf("%d\n", moveright(arr, key, last));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
    int len;
    int pos;
    int *arr;
    int i;
    int mPos;
    int min;
    int elem;
    int pl;

    assert(scanf("%d", &len) == 1);
    arr = (int *)calloc(len, sizeof(int));
    for (i = 0; i < len; i++)
    {
        assert(scanf("%d", &arr[i]));
    }
    assert(scanf("%d", &pos));

    min = pos;
    for (mPos = pos + 1; mPos < len; mPos++)
    {
        if (arr[mPos] < arr[min])
        {
            min = mPos;
        }
    }
    elem = arr[min];
    // new place
    pl = 0;
    while (arr[pl] <= elem)
    {
        pl++;
    }



    if (arr[min] != arr[pos])
    {

        arr[min] = arr[pos];
        for (i = pos; i > pl; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pl] = elem;
    }

    for (i = 0; i < len; i++)
    {
        assert(printf("%d ", arr[i]));
    }
}
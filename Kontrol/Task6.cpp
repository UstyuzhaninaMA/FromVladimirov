#include <stdio.h>
#include <assert.h>

int main()
{
    int num, i, total, next = 0, fl = 0, inx = 0;
    int arr[1000];

    assert(scanf("%d", &num) == 1);
    
    for (num = num; num != 0; num /= 2)
    {
        if (fl == 1)
        {
            total = num % 2 + 1;
            fl = 0;
        }
        else
        {
            total = num % 2;
        }

        if (total == 2)
        {
            total = 0;
            fl = 1;
        }

        next = (num / 2) % 2 + fl;

        if (next == 2)
        {
            next = 0;
            fl = 1;
        }

        if ((next == 1) && (total == 1))
        {
            total = -1;
            fl = 1;
        }

        arr[inx] = total;

        inx++;
    }

    if (next)
    {
        printf("%d ", next);
    }

    for (i = (inx - 1); i >= 0; i--)
    {
        int num = i;
        printf("%d ", arr[num]);
    }

    return 0;
}
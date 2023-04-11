#include <stdio.h>
#include <stdlib.h>

int rec(int bukv, int ctr)
{
    if (ctr == 1)
    {
        return 1;
    }
    if (bukv == 1)
    {
        return ctr;
    }


    //len
    int i, l = 1;

    for (i = 1; i < ctr; i++)
    {
        l = 2 * l + 1;
    }

    if (bukv > l / 2 + 1)
    {
        return rec(bukv - l / 2 - 1, ctr - 1);
    }
    return rec(bukv - 1, ctr - 1);
}

int main()
{
    int ctr, bukv;

    scanf("%d %d", &ctr, &bukv);

    printf("%c\n", rec(bukv, ctr) + 'a' - 1);

    return 0;
}
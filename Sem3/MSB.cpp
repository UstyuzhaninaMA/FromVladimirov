///Problem MSB — поиск старшего установленного бита в числе

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef unsigned long long uL;

uL find_most(uL number)
{
    int inx = 0;
    uL cons = 0;
    ///см фото, попробуй реализовать напрямую
    while ((inx < 8 * 8))
    {
        //printf("%llu-%d \n", number & (1ll << inx), inx);
        if (number & (1ll << inx))
        {
            cons = inx;
        }
        inx += 1;
    }
    return cons;
}

int main()
{
    uL number;

    assert(scanf("%llu", &number));

    if (number == 0ll)
    {
        printf("-1\n");
        return 0;
    }
    printf("%llu\n", find_most(number));
}
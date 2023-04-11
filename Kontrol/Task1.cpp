#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long number1, number2;
    unsigned long long i;
    int p, k;
    int kol;
    kol = 0;

    scanf("%llu %llu", &number1, &number2);

    for (i = number1; i > 1; i /= 2)
    {
        p = i % 2;
        k = number2 % 2;
        if (p > k)
        {
            kol += 1;
        }
        number2 = number2 / 2;
    }
    if ((number2 % 2) == 0)
    {
        kol += 1;
    }

    printf("%d\n", kol);

    return 0;
}
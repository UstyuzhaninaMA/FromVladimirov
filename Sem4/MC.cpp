// Problem MC — размен монет

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int sum = 0, len = 0;
    int i, j, min;
    int *nominal;
    int *optimalWay;

    // ввод
    assert(scanf("%d %d\n", &sum, &len) == 2);

    nominal = (int *)calloc(len + 2, sizeof(int));
    optimalWay = (int *)calloc(sum + 2, sizeof(int));
    optimalWay[0] = 1;

    for (i = 0; i < len; i++)
    {
        scanf("%d", nominal + i);
    }

    // cортировка
    qsort(nominal, len, sizeof(int), cmp);

    //  поиск пути
    for (int i = 1; i <= sum; i++)
    {
        min = 10001;
        for (int j = 0; j < len; j++)
        {
            if (i - nominal[j] < 0)
                break;
   
            int total = optimalWay[i - nominal[j]];
            //printf("%d/", total);
            if ((optimalWay[i - nominal[j]]) != 0 && optimalWay[i - nominal[j]] < min)
            {
                min = optimalWay[i - nominal[j]];
            }
        }
        if (min != 10001)
            optimalWay[i] = min + 1;
        printf("\n ------%d \n", optimalWay[i]);
    }

    //вывод
/*     for (int i = 0; i < sum; i++)
    {
        printf("%d\n", optimalWay[i]);
    }  */
    printf("%d \n", optimalWay[sum] - 1);

    free(nominal);
    free(optimalWay);

    return 0;
}
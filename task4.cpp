#include <stdio.h>
#include <stdlib.h>

struct par
{
    int gr; //uhel
    int t;
    int b;
    int sum;
};

void swap(struct par *A, struct par *B)
{
    struct par temp = *A;
    *A = *B;
    *B = temp;
}

int main()
{
    //ввод
    int n;
    scanf("%d", &n);

    struct par girl[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &girl[i].gr);
        scanf("%d", &girl[i].t);
        scanf("%d", &girl[i].b);

        girl[i].sum = abs(girl[i].gr - 90) + abs(girl[i].t - 60) + abs(girl[i].b - 90);
    }


    //сортировка
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (girl[j].sum > girl[j + 1].sum)
            {
                swap(&girl[j], &girl[j + 1]);
            }

            if (girl[j].sum == girl[j + 1].sum)
            {
                if (girl[j].gr < girl[j + 1].gr)
                {
                    swap(&girl[j], &girl[j + 1]);
                }

                if (girl[j].gr == girl[j + 1].gr)
                {
                    if (girl[j].t > girl[j + 1].t)
                    {
                        swap(&girl[j], &girl[j + 1]);
                    }
                    if (girl[j].t == girl[j + 1].t)
                    {
                        if (girl[j].b < girl[j + 1].b)
                        {
                            swap(&girl[j], &girl[j + 1]);
                        }
                    }
                }
            }
        }
    } 
 

    //вывод
    for (int i = 0; i < n; i++)
    {
        printf("%d ", girl[i].gr);
        printf("%d ", girl[i].t);
        printf("%d \n", girl[i].b);
    }

    return 0;
}
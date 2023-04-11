#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int f_majority_element(const int *parr, int len);

int majority_element(const int *parr, int len)
{
    int answer, i;
    int kol = 0;
    answer = f_majority_element(parr, len);

    //check
    if (answer != -1)
    {
        for (i = 0; i < len; i++)
        {
            //printf("%d %d\n", parr[i], answer);
            if (parr[i] == answer)
            {
                kol++;
                //printf("--%d %d\n", parr[i], kol);
            }
        }
        if (kol < len / 2 +1)
        {
            //printf("--%d %d\n", kol, len/2+1);
            return -1;
        }
    }
    return answer;
}

int f_majority_element(const int *parr, int len)
{
    int odd;
    int med;
    int m1, m2;
    if (len == 1)
        return *parr;
    if (len == 2)
    {
        if (*parr == parr[1])
        {
            return *parr;
        }
        return -1;
    }
    if (len == 3)
    {
        if (*parr == parr[1] || parr[2] == *parr)
        {
            return *parr;
        }
        if (parr[1] == parr[2])
        {
            return parr[1];
        }
    }

    med = len / 2;
    odd = med;
    if (len % 2 == 1)
        odd += 1;
    m1 = f_majority_element(parr, med);
    m2 = f_majority_element(&parr[med], odd);

    if (m1 != m2)
    {
        if (m1 == -1 && m2 != -1)
        {
            return m2;
        }
        if (m2 == -1 && m1 != -1)
        {
            return m1;
        }
        if (m1 != -1 && m2 != -1)
            if (med < odd)
                return m2;
        return -1;
    }
    else
    {
        return m1;
    }
}

int main()
{
    int Arr[] = {1, 4, 2, 2, 1};
    int N = 5;
    printf("===== %d =====\n", majority_element(Arr, N));
    int Arr1[] = {9, 1, 1, 9, 2, 2};
    N = 6;
    printf("===== %d =====\n", majority_element(Arr1, N));
    int Arr2[] = {3, 4, 3, 2, 4, 4, 2, 4, 4};
    N = 9;
    printf("===== %d =====\n", majority_element(Arr2, N));
    int Arr3[] = {3, 3, 4, 2, 4, 4, 2, 4};
    N = 8;
    printf("===== %d =====\n", majority_element(Arr3, N));
    int Arr4[] = {2, 3, 1, 2, 2};
    N = 5;
    printf("===== %d =====\n", majority_element(Arr4, N));
}
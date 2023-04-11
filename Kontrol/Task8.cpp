#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *x1, const void *x2)
{
    int *mas1 = (int *)x1;
    int *mas2 = (int *)x2;

    if (mas1[0] > mas2[0])
    {
        return 1;
    }
    if (mas1[0] < mas2[0])
    {
        return -1;
    }

    for (int i = 1; i <= (int)mas1[0]; i++)
    {
        if (mas1[i] > mas2[i])
            return 1;
        if (mas1[i] < mas2[i])
            return -1;
    }
    return 0;
}

int main()
{
    int len_arr;
    int **arr;
    int total_len;

    FILE *fp;

    fp = freopen("file.txt", "r", stdin);

    scanf("%d", &len_arr);

    arr = (int **)calloc(len_arr + 1, sizeof(int *));

    for (int i = 0; i < len_arr; i++)
    {
        scanf("%d", &total_len);
        arr[i] = (int *)calloc(total_len + 1, sizeof(int));

        arr[i][0] = total_len;
       

        for (int k = 1; k <= total_len; k++)
        {
            scanf("%d", &arr[i][k]);
        }
    }

    printf("%d\n ", len_arr);

    for (int k = 0; k < len_arr; k++)
    {
        for (int j = 0; j <= arr[k][0]; j++)
        {
            printf("%d ", arr[k][j]);
        }
        printf("\r\n ");
    }

    qsort(arr, len_arr, sizeof(int *), compare);

    printf("%d\n ", len_arr);
    for (int k = 0; k < len_arr; k++)
    {
        for (int j = 0; j <= arr[k][0]; j++)
        {
            printf("%d ", arr[k][j]);
        }
        printf("\r\n ");
    }
}
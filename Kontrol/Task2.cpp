#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M, N;
    int *arr;
    int index;
    int retVal;
    index = 0;

    scanf("%d %d", &M, &N);

    arr = (int *)calloc(N, sizeof(int));

    for (index = 0; index < N; index++)
    {
        assert(scanf("%d", arr + index) == 1);
    }

    int target_level = 0;
    int flag = 0;
    for (index = 0; index < N; index++)
    {
        target_level = index + 1;

        for (int check_index = index; check_index >= 0; check_index--)
        {
            if (arr[check_index] >= target_level)
            {
                retVal = target_level;
                break;
            }
            else if (arr[check_index] + M >= target_level)
            {
                M -= target_level - arr[check_index];
                arr[check_index] = target_level;
            }
            else
            {
                retVal = target_level - 1;
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    printf("%d\n", retVal);

    free(arr);

    return 0;
}
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, x, y;
    unsigned long long k;
    unsigned long long sum;
    sum = 1;
    k = 1;
    assert(scanf("%d", &num) == 1);

    if(num == 1){
        printf("1\n");
        return 0;
    }

    for (x = 2; x < num; x += 2)
    {
        for(y = 1; y <= 4; y++)
        {
            k += x;
            sum += k;
        }        
    }

    printf("%llu\n", sum);
    return 0;
}
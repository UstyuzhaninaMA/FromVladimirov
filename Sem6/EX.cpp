#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    float number;
    int intNum;

    if(scanf("%f", &number) != 1)
    {
        abort();
    }

    memcpy(&intNum, &number, sizeof(float));

    for(int i = 1; i < 22; i += 2)
    {
        intNum = intNum ^ (1u << i);
    }

    memcpy(&number, &intNum, sizeof(float));

    printf("%.5f\n", number);

    return 0;
}

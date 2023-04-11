#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* #define N 100 */

/* struct _Decimal
{
    char a[1000];      // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n; // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0}; */

void div10(Decimal *res, const Decimal *a)
{
    // printf("IN div10()\n\r");
    unsigned int i;

    if (a->n == 0)
    {

        char arr[2] = "0\0";
        printf("(%s)", arr);    
        strcpy(res->a, arr);
        res -> n = 0;
        //printf("(%s)", res->a);        
        return;
    }

    for (i = 0; i < a->n; i++)
    {

        res->a[i] = a->a[i + 1];
        // printf("%d: %c %c\n\r", i,  res->a[i], a->a[i+1]);
    }
    res->n = (a->n) - 1;

    return;
}

/* int main()
{
    char prStr[1000] = "0";
    Decimal a;
    //a.a = (char*) calloc(1000, sizeof(char));
    strcpy(a.a, prStr);
    a.n = strlen(prStr);

    Decimal *res;

    unsigned int i;

    res = (Decimal *)calloc(1, sizeof(Decimal));

    div10(res, &a);
    //res = mult10(&a);
    //printf("!!!%d\n", res->a[0]);
    printf("RES: %s\n", res->a);

    free(res);

    return 0;
} */
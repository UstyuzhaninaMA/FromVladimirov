#include <stdio.h>
#include <stdlib.h>

#define N 100

struct _Decimal
{
    char* a;      // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n; // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

//Decimal zero = {{0}, 0};

#include <stdlib.h>
#include<string.h>

// void div10(Decimal *res, const Decimal *a)
// {
//     printf("IN div10()\n\r");
//     unsigned int i;
//     if (a->n == 0){

//         res = &zero;
//         return;
//     }
//     for (i = 0; i < a->n; i++)
//     {

//         res->a[i] = a->a[i + 1];
//         printf("%d: %c %c\n\r", i,  res->a[i], a->a[i+1]);
//     }
//     res->n = (a -> n) - 1;
// }



Decimal *mult10(const Decimal *a)
{
    //printf("khd");
    Decimal *res;
    res = (Decimal *)calloc(1, sizeof(Decimal));
    
    unsigned int i;
    if ((a->a[0] == '0') && (a->n == 0)) 
    {
        res -> n = 0;
        res -> a = "0\0";
        return res;

    }

    res->a = (char*)calloc((a->n) + 1, sizeof(char));
    res->a[0] = '0';
    for (i = 1; i <= (a->n) + 1; i++)
    {
        res->a[i] = a->a[i - 1];
    }

    res->n = (a->n) + 1;

    return (res);
}



int main()
{
    char prStr[1000] = "3287";
    Decimal a;
    a.a = (char*) calloc(1000, sizeof(char));
    strcpy(a.a, prStr);
    a.n = 3u;

    Decimal *res;


    unsigned int i;

    //res = (Decimal *)calloc(1, sizeof(Decimal));
    
    //div10(res, &a);
    res = mult10(&a);
    //printf("!!!%c\n", res->a[0]);
    printf("RES: %s", res->a);

    return 0;
}
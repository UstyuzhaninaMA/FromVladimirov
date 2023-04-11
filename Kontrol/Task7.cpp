#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int len1, len2;
    int* num1;
    int* num2;
    int inx;
    int nod;

//read
    scanf("%d", &len1);

    num1 = (int *)calloc(len1, sizeof(int));

    for (inx = 0; inx < len1; inx++)
    {
        scanf("%d", num1 + inx);
    }

    scanf("%d", &len2);

    num2 = (int *)calloc(len2, sizeof(int));

    for (inx = 0; inx < len2; inx++)
    {
        scanf("%d", num2 + inx);
    }


    //find
    nod = gcd(len1, num1, len2, num2);

    printf("%d\n", nod);
}

int gcd(int len1, int* num1, int len2, int* num2){
    int nod;
    int s;
    
    nod = gcd(y, (x % y), a, b);
    s = *b;
    *b = *a - (x / y) * *b;
    *a = s;
    return nod;
}
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y, int* a, int*b);

int main(){
    int nod, a, b, x, y;
    
    scanf("%d %d", &x, &y);
    
    nod = gcd(x, y, &a, &b);

    if(nod < 0){
        a = -a;
        b = -b;
        nod = -nod;
    }

    printf("%d %d %d\n", a, b, nod);
}

int gcd(int x, int y, int* a, int* b){
    int nod;
    int s;    
    
    if (y == 0){
        *a = 1;
        *b = 0;
        return x;
    }
    
    nod = gcd(y, (x % y), a, b);
    s = *b;
    *b = *a - (x / y) * *b;
    *a = s;
    return nod;
}
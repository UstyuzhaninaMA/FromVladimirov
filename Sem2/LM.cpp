#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned gcd(int x, int y){
    int nod;  
    
    if (y == 0){
        return x;
    }
    nod = gcd(y, (x % y));
    return nod;
}

unsigned long long lsm(int max_num){
    unsigned long long a = 2, b = 3;
    while (b <= max_num)
    {
        a = (a * b)/gcd(a,b);
        b++;
    }
    return a;
}

int main(){

    unsigned long long max_num;

    assert(scanf("%llu", &max_num) == 1);

    printf("%llu\n", lsm(max_num));
}
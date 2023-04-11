#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(unsigned long long n, unsigned mod) {
    unsigned long long first = 0ull, second = 1ull, idx;
    if (n == 0) return first;
    for (idx = 2; idx <= n; ++idx) {
        unsigned long long tmp = second;
        second = (second + first) % mod;
        first = tmp;
    }
    return second;
}

unsigned find_piz(unsigned mod){
    unsigned long long first = 0ull, second = 1ull;
    int inx;
    for(inx = 2; ; ++inx){
        unsigned long long tmp = second;
        second = (second + first) % mod;
        first = tmp;

        if ((first == 0ull) && (second == 1ull)){
            return inx -1;
        }

    }  
}

int main()
{
    unsigned long long n;
    unsigned mod, piz = 0; 

    scanf("%llu %u", &n, &mod);

    piz = find_piz(mod);

    n = n % piz;

    printf("%llu %u\n", fib(n, mod), piz);
}
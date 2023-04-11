//Problem FM -- вычисления по любому модулю

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long fib(unsigned n, unsigned mod, unsigned* piz) {
    unsigned long long first = 0ull, second = 1ull; int idx;
    if (n == 0) return 0ull;
    for (idx = 2; idx <= n; ++idx) {
        unsigned long long tmp = second;
        second = (second + first) % mod;
        first = tmp;
        if 
    }
    return second;
}

int main()
{
    unsigned n, mod, piz; 

    scanf("%u %u", &n, &mod);

    printf("%llu %u\n", fib(n, mod, &piz) % mod, piz);
}
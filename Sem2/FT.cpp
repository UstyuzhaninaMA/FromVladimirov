#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long nod;
    if (y == 0)
    {
        return x;
    }
    nod = gcd(y, (x % y));
    return nod;
}
///
unsigned long long mul_mod(unsigned long long n, unsigned long long k, unsigned long long m)
{
    unsigned long long mult = n % m;
    unsigned long long prod = 0;
    while (k > 0)
    {
        if ((k % 2) == 1)
        {
            prod = (prod + mult) % m;
            k = k - 1; /// переполнение в умножении, нужно сделать умножение отдельной функцией
        }
        mult = (mult + mult) % m;
        k = k / 2;
    }
    return prod;
}

unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m)
{
    unsigned long long mult = n % m;
    unsigned long long prod = 1;
    while (k > 0)
    {
        if ((k % 2) == 1)
        {
            prod = (mul_mod(prod, mult, m)) % m;
            k = k - 1; /// переполнение в умножении, нужно сделать умножение отдельной функцией
        }
        mult = mul_mod(mult, mult, m) % m;
        k = k / 2;
    }
    return prod;
}

unsigned long long checkPrime(unsigned long long number)
{
    unsigned i;
    unsigned long long a;
    srand(time(NULL));

    for (i = 0; i <= 20; i++)
    {
        a = rand();

        while (gcd(a, number) != 1)
        {
            a = rand();
        }

        if (pow_mod(a, number - 1, number) != 1)
        {
            //printf("%llu %llu %llu ", pow_mod( a, number-1, number), a, number);
            return 0;
        }
    }
    return 1;
}

int main()
{

    unsigned long long number;

    assert(scanf("%llu", &number) == 1);

    printf("%llu\n", checkPrime(number));
}
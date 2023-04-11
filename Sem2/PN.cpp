#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int isPrime(unsigned number) {
    int inx;

    if ((number == 2) || (number == 3)){
        return 1;
    }
    if ((number < 2) || ((number % 2) == 0) || ((number % 3) == 0)) {
        return 0;
    }

    for(inx = 5; inx * inx <= number; inx += 6)
        if (((number % inx) == 0) || ((number % (inx + 2)) == 0))
            return 0;
    return 1;
}

int main() {
    unsigned num = 0;
    unsigned d_num;
    unsigned k = 2;

    assert(scanf("%u", &d_num) == 1);
    while (d_num != num) {
        if (isPrime(k))
            ++num;
        ++k;
    }

    printf("%u\n", k-1);
     
    return 0;
}
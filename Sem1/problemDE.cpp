#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


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

int main()
{
    int a, b, c, x, y, nod;
    
    scanf("%d %d %d", &a, &b , &c);

    if (a == 0){
        if (b == 0){
            if (c == 0){
                //Решений бесконечно много
                printf("1 1\n");
                return 0;
            }
            else{
                printf("NONE\n");
                return 0;
            }
        }
    }
    
    nod = gcd(a, b, &x, &y);

    if (c % nod == 0){
        x = x * (c / nod);
        y = y * (c / nod);

        printf("%d %d\n", x, y);

        return 0;
    }
    else{
        printf("NONE\n");
        return 0;
    }
}
//Problem NS -- системы счисления

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

unsigned deg(unsigned num, unsigned step){
    int inx;
    unsigned num0 = num;
    for(inx = 1; inx < step; ++inx)
    {
        num *= num0;
    }
    return num;
}

int newRadix(unsigned number, unsigned radix){
    unsigned num = number;
    unsigned kol = 1;
    while (1)
    {
        num = num / radix;
        if (num != 0){
            kol++;
            continue;
        }
        break;
    }
    
    while (kol != 0)
    {   
        kol = kol - 1;
        if (kol == 0)
        {
            printf("%u\n", (number % radix));
            break;
        }
        if (number >= deg(radix, kol)){
            printf("%u", number / deg(radix, kol));
        }
        else{
            printf("0");
        }
        number = number % deg(radix, kol);
    }
    return 0;
}

int main()
{
    unsigned int number; //оно же x
    unsigned int radix; // оно же y - основание СС


    assert(scanf("%u %u", &number, &radix ) == 2);
    assert(radix > 1 && radix < 11 && number > 0);
    
    
    newRadix(number, radix);

    return 0;
}

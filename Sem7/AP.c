#include <math.h>
#include <stdio.h>


int main()
{
    int number = 10;

    for (int i = 2; i <= sqrt(number); i++)
    { 
        if(number % i == 0)
        {
            printf("Число не простое");
        }
    }
    printf("Число простое");
}
#include <stdio.h>
#include <math.h>

double function(int a, int b, int c, int x){
    return a * x*x * sin(x) + b * x * cos(x) + c;
}

// float Half(double x1, double x2)
// {

// }

int main()
{
    double a, b, c, N, x1, x2;
    double answer;

    x1 = N;
    x2 = -N;

    if(((function(a, b, c, x1) > 0) && (function(a, b, c, x1) > 0)) || ((function(a, b, c, x1) < 0) && (function(a, b, c, x1) < 0))){
        printf("0.0");
        return 0;
    }

    while (fabs(x1-x2) < 0.000001)
    {
        
    }
    

    return 0;
}
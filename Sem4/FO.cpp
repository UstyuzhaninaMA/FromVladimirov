#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    char b;
    FILE *f = fopen(argv[1], "r");

    while (fscanf(f, "%c", &b)==1)
    {
        printf("%c", b);
    }
    

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char *substring, int lenSubstring)
{
    int i;
    char buffer;
    for (i = 0; i < lenSubstring / 2; i++)
    {
        buffer = substring[lenSubstring - i - 1];
        substring[lenSubstring - i - 1] = substring[i];
        substring[i] = buffer;
    }
}

int main(int argc, char **argv)
{
    printf("%d\n", argc);

    for (int i = 1; i < argc; i++)
    {
        int k = 0;

        if (strstr(argv[i], "-r") != NULL)
        {
            //разворот строки
        }

        //поиск '-'        
        while (argv[i][k] == '-')
        {
            argv[i][k] = '+';
            k+=1;
        }

        

        printf("%s ", argv[i]);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void reverse(char *, int);

int main()
{
    int len1, len2;
    char *substring;
    char *sreverse;
    char *string;
    char *faddress;

    //ввод
    scanf("%d /n", &len1);
    substring = (char *)calloc(len1 + 1, sizeof(char));
    for (int i = 0; i < len1; i++)
    {
        scanf("%c", &substring[i]);
    }

    scanf("%d ", &len2);
    string = (char *)calloc(len2 + 1, sizeof(char));
    for (int i = 0; i < len2; i++)
    {
        scanf("%c", &string[i]);
    }

    //копирование и разворот
    sreverse = (char *)calloc(len1 + 1, sizeof(char));
    strcpy(sreverse, substring);
    reverse(sreverse, len1);

    //поиск и замена
    faddress = strstr(string, substring);
    while (faddress != NULL)
    {
        //замена
        for (int i = 0; i < len1; i++)
        {
            faddress[i] = sreverse[i];
        }
        faddress = strstr(faddress + len1, substring);
    }

    //вывод
    for (int i = 0; i < len2; i++)
    {
        printf("%c", string[i]);
    }

    free(substring);
    free(string);
    free(sreverse);
    free(faddress);
}

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
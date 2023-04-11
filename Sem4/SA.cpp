#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//почитать про realloc
char *strcat_r(char *dest, const char *src, int *bufsz)
{
    int len1 = strlen(dest);
    int len2 = strlen(src);
    char *buffer;

    buffer = dest;
    if (*bufsz - len1 < len2)
    {
        buffer = (char *)calloc(len1 + len2 + 1, sizeof(char));
        *bufsz = (len1 + len2+1);

        for (int inx = 0; inx < len1; inx++)
        {
            buffer[inx] = dest[inx];
        }
    }

    for (int inx = 0; inx < len2; inx++)
    {
        buffer[len1 + inx] = src[inx];
    }

    buffer[len1+len2] = '\0';
    return buffer;
}

#define buf_size 7
int main()
{
    char str1[buf_size] = "Hello";
    int buf_s = buf_size;
    char* str2 = (char*)" world";
    printf("%s %d %u", strcat_r(str1, str2, &buf_s), buf_s, (unsigned int)strcat_r(str1, str2, &buf_s)[12]);

    return 0;
}
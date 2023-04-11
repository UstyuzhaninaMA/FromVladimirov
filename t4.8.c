#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *convert(char *dst, const char *src)
{
    int len = strlen(src);
    int first = 0;
    int ind;
    int dstpos = 0;

    while (src[first] == '0')
    {
        first++;
    }

    if (first == len)
    {
        dst[0] = '0';
        dst[1] = '\0';
        return dst;
    }

    // printf("!!!!!%d\n", first);

    if ((len - first) % 3 == 1)
    {
        dst[dstpos] = src[first];
        dstpos = 1;
    }
    else if ((len - first) % 3 == 2)
    {
        dst[dstpos] = 48 + ((int)(src[first] - 48) * 2 + (int)(src[first + 1] - 48));
        dstpos = 1;
    }

    ind = first + ((len - first) % 3);

    for (; ind < len; ind += 3)
    {
        dst[dstpos] = 48 + ((int)(src[ind] - 48) * 4 + (int)(src[ind + 1] - 48) * 2 + (int)(src[ind + 2] - 48));

        dstpos++;
    }

    dst[dstpos] = '\0';
    return (dst);
}

/*  int main()
{
    char src[100] = "1000000001";
    char* dst = (char*)calloc(100, sizeof(char));


    dst = convert(dst, src);
    //printf("bin_str: %s\n\r", src);
    printf("hexs_str: %s\n\r", dst);

    free(dst);

    // printf("experiment: %c\n\r", 48 + ((int)('1' - 48) * 4 + (int)('0' - 48) * 2 + (int)('1' - 48)));
}  */
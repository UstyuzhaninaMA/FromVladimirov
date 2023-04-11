#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct S_Possition
{
    char *top_slash;
    struct S_Possition *prev;

} Possition;

extern void normalize_path(char*path);

/* int main()
{
    char testString1[100] = "/1///2/nothing1/nothing2/../../3//4.0";
    char testString2[100] = "/1///2/3/nothing2/././../3//4.0";
    char testString3[100] = "fd/s/vaeb./sdvv";
    printf("%s\n", (testString1));
    normalize_path(testString1);
    printf("%s\n", (testString1));

    printf("%s\n", (testString2));
    normalize_path(testString2);
    printf("%s\n", (testString2));

    printf("%s\n", (testString3));
    normalize_path(testString3);
    printf("%s\n", (testString3));

}  */

#define UP_FLAG 1
#define DOWN_FLAG 0

extern void normalize_path(char *path)
{
    char * cl_str;
    int i = 0;
    int len = 0;
    char* k;
    Possition * curPoss;
    int flag_slash;

    while(path[len] != '\0')
    {
        len++;
    }

    cl_str = (char*)calloc(len + 1, sizeof(char));


    k = cl_str;
    flag_slash = 0;

    curPoss = (Possition*)calloc(1, sizeof(Possition));
    curPoss -> top_slash = cl_str;
    curPoss -> prev = NULL;

    while (path[i] != '\0')
    {

        if (path[i] == '/')
        {
            if (flag_slash == DOWN_FLAG)
            {
                Possition * newPoss;
                flag_slash = 1;
                *k = path[i];
                newPoss = (Possition*)calloc(1, sizeof(Possition));
                newPoss ->top_slash = k;
                newPoss->prev= curPoss;
                curPoss = newPoss;
                k++;
                i++;
                continue;
            }
            else
            {
                i++;
                continue;   
            }
        }
        if(path[i] =='.')
        {
            if(path[i + 1] == '\0')
            {
                break;
            }
            if(path[i + 1] == '.')
            {
                Possition * buf;

                k = (curPoss->prev)->top_slash + 1;
                buf = curPoss;
                curPoss = (curPoss->prev);
                free(buf);
                i++;
                continue;
            }
            if(*(k-1) != '/'){
                 *k = path[i];
                 k++;
            }
            i++;
            continue;

        }
        else
        {
            flag_slash = DOWN_FLAG;
            *k = path[i];
            k++;
            i++;

        }

    }
    *k = '\0';
    strcpy(path, cl_str);

    free(cl_str);

    while(curPoss->prev != NULL){
        Possition* buf = curPoss->prev;
        free(curPoss); 
        curPoss = buf;
    }

    free(curPoss);

    //printf("%s\n", (path));
}
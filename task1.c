#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};

struct Rect * transform (const struct Rect * src) 
{
    
    struct Rect *res = calloc(1, sizeof(struct Rect));

    

    res->lt.x = -src->lt.y;
    res->lt.y = src->rb.x;
    res->rb.x = -src->rb.y;
    res->rb.y = src->lt.x;

    return res;
}

int main()
{
struct Rect rect = {{-1, 1}, {4, -2}};
printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
transform(&rect);
printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
return 0;
}
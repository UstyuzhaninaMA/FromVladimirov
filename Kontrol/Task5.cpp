#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x;
    int y;
};
struct Rect
{
    struct Point lt; // left top
    struct Point rb; // right bottom
};

struct Rect transform(struct Rect r)
{

    struct Rect res = {r.lt.x + (r.rb.y - r.lt.y), r.lt.y,
                       r.lt.x, r.lt.y - (r.rb.x - r.lt.x)};
    return res;
}

int main()
{
    struct Rect rect, a = {{2, 4}, {7, 1}};
    rect = transform(a);
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);
    printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
    return 0;
}
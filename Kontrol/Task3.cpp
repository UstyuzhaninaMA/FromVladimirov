#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Point
{
    float x;
    float y;
};

int in_region(struct Point p);

int main()
{

    struct Point point;
    scanf("%f %f", &point.x, &point.y);

    printf("%d", in_region(point));
}

int in_region(struct Point p)
{
    if ((p.x < -1) || (p.x > 2))
    {
        return 0;
    }
    if ((-(p.x) * (p.x) + 4 >= p.y + 1) && (p.y + 1 >= (p.x) * (p.x) - 4))
    {
        return 1;
    }
    return 0;
}
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Euclidean division: a = qb + r, 0 <= r < |b|
// C-style % operation: a == (a / b) * b + (a % b)
// We need proper euclidean division here


int main() {
  int x, y, g, res;
  res = scanf("%d%d", &x, &y);
  if (res != 2 || y == 0) {
    printf("%s\n", "Wrong input");
   
    abort();
  }

  for(;;)
  {
        int q;
        assert(y != 0);

        for(;;)
        {
            int r;
            assert(y != 0);
            r = x % y;
            if (r < 0){
                if (y < 0){
                    r += -y;
                }
                else{
                    r += y;
                }
            }
            q = r;
            break;
        }

        if (q == 0){
           g = y;
           break;
        }
        x = y;
        y = q;
  }

  printf("%d\n", g);
  return 0;
}
void gcd (int a, int b, int *d, int *x, int *y)

{

  int s;

  if (b == 0)

  {

    *d = a; *x = 1; *y = 0;

    return;

  }

  gcd(b, a % b ,d,x,y);

  s = *y;

  *y = *x - (a / b) * (*y);

  *x = s;

}
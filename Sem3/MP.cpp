#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int len;
    int *arr_pos;
} polinom;

void poli_mul(polinom *pol1, polinom *pol2)
{

    //создание полинома с результатом
    int len_res = pol1->len + pol2->len - 1;
    int *pos_res = (int *)calloc(len_res, sizeof(int));
    polinom res = {len_res, pos_res};

    //заполнение полинома
    int i, j;
    for (i = 0; i < pol1->len; i++)
    {
        for (j = 0; j < pol2->len; j++)
        {
            res.arr_pos[i + j] += pol1->arr_pos[i] * pol2->arr_pos[j];
        }
    }
    //вывод
    i = res.len - 1;
    j = 0;

    for(i = res.len - 1; res.arr_pos[i]==0; i--)
    {
        //количество нулей
        j++;
    }
    for(i=0; i < res.len - j; i++)
    {
        printf("%d ", res.arr_pos[i]);
    }

    free(res.arr_pos);
}

int main()
{
    int inx;
    polinom p1, p2;
    assert(scanf("%d %d", &p1.len, &p2.len) == 2);
    p1.arr_pos = (int *)calloc(p1.len, sizeof(int));
    p2.arr_pos = (int *)calloc(p2.len, sizeof(int));
    for (inx = 0; inx < p1.len; inx++)
    {
        assert(scanf("%d", p1.arr_pos + inx) == 1);
    }
    
    for (inx = 0; inx < p2.len; inx++)
    {
        assert(scanf("%d", p2.arr_pos + inx) == 1);
    }

    poli_mul(&p1, &p2);

    free(p1.arr_pos);
    free(p2.arr_pos);
    return 0;
}

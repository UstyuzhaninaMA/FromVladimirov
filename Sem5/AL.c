
#include <stdlib.h>
#include <stdio.h>

struct node_t
{
    struct node_t *next;
    int data;
};


void func(FILE *outp, struct node_t * str);

// считывает список из входного файла, так, чтобы все чётные числа были в начале
struct node_t *read_list(FILE *inp, FILE *outp)
{
    // freopen(inp, "r", stdin);
    // printf("B");
    int currentVal;
    struct node_t *even;
    struct node_t *odd;
    struct node_t *oddCurr;
    struct node_t *evenCurr;
    struct node_t*buf;

    odd = (struct node_t *)calloc(1, sizeof(struct node_t *));
    even = (struct node_t *)calloc(1, sizeof(struct node_t *));

    even->next = NULL;
    odd->next = NULL;

    oddCurr = odd;
    evenCurr = even;

    while (fscanf(inp, "%d", &currentVal) != EOF)
    {
        // printf("B");
        //fprintf(outp, "%d\n", currentVal);
        struct node_t *tmpStruct;

        tmpStruct = (struct node_t *)calloc(1, sizeof(struct node_t *));
        tmpStruct->data = currentVal;
        tmpStruct->next = NULL;

        if (currentVal % 2 == 0)
        {
            oddCurr->next = tmpStruct;
            oddCurr = tmpStruct;
            
            // func(outp, odd->next);
        }
        else
        {
            evenCurr->next = tmpStruct;
            evenCurr = tmpStruct;
            // func(outp, even->next);
        }

    }

    oddCurr->next = even->next;
    buf = odd->next;
    free(odd);
    free(even);
    return buf;
}

// удаляет список элемент за элементом
void delete_list(struct node_t *top)
{
    struct node_t *tmp;

    if (top == NULL)
    {
        return;
    }

    tmp = top;

    while (top->next != NULL)
    {
        tmp = top;
        top = tmp->next;
        free(tmp);
    }

    free(top);
}

void func(FILE *outp, struct node_t * str)
{
    fprintf(outp, "\n");
    int counter = 0;
    while ((counter<20)&&(str->next != NULL))
    {
        fprintf(outp, "%d ", str->data);
        str = str -> next;
        counter++;
    }
    fprintf(outp, "%d ", str->data);
    fprintf(outp, "\n");
}

int main()
{
    FILE *f = fopen("myfile.txt", "r");
    FILE *d = fopen("result.txt", "w");

    // printf("%d", read_list(f, d)->next->data);

    func(d,read_list(f,d));
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//#define DEBUG
enum
{
    CAMPACITY = 256
};
enum braces_t
{
    LBRAC,
    RBRAC
};
enum lexem_kind_t
{
    OP,
    BRACE,
    NUM
};
enum operation_t
{
    ADD,
    SUB,
    MUL,
    DIV
};

typedef struct lexem_t
{
    enum lexem_kind_t kind;
    union
    {
        enum operation_t op;
        enum braces_t b;
        int num;
    } lex;
} lexem_t;

typedef struct lex_array_t
{
    struct lexem_t *lexems;
    int size, capacity;
} lex_array_t;

void printLexArray(lex_array_t *larr)
{
    // printf("\nI'm in printLexArray\n");
    for (int i = 0; i < larr->size; i++)
    {
        switch (larr->lexems[i].kind)
        {
        case BRACE:
            switch (larr->lexems[i].lex.b)
            {
            case LBRAC:
                printf("LBRAC ");
                break;
            case RBRAC:
                printf("RBRAC ");
                break;
            }
            break;
        case OP:
            switch (larr->lexems[i].lex.op)
            {
            case ADD:
                printf("PLUS ");
                break;
            case SUB:
                printf("MINUS ");
                break;
            case MUL:
                printf("MUL ");
                break;
            case DIV:
                printf("DIV ");
                break;
            }
            break;
        case NUM:
            printf("NUMBER:%d ", larr->lexems[i].lex.num);
            break;
        default:
            // printf("In print defalt: %d\n", larr->lexems[i].kind);
            break;
        }
    }
}

int main()
{
    int number;
    int size, corBR;
    int indInLexems;
    struct lex_array_t *larr;

    char inArr[1024] = {0};

    if (scanf("%1023c", inArr) != 1)
    {
        abort();
    }

#ifdef DEBUG
    int i = 0;
    while (inArr[i] != '\0')
    {
        printf("%c", inArr[i]);
        i++;
    }
    printf("\n");
#endif

    corBR = 0;

    size = strlen(inArr);

    larr = (lex_array_t *)calloc(1, sizeof(lex_array_t));
    larr->lexems = (lexem_t *)calloc(CAMPACITY, sizeof(lexem_t));
    larr->size = 0;
    larr->capacity = CAMPACITY;

    indInLexems = 0;

    for (int index = 0; index < size; index++)
    {
        char symb = inArr[index];
        int k;

        if (corBR < 0)
        {
            // error
            break;
        }

        if (symb == '\n')
        {
            break;
        }

        if ((('(' <= symb) && (symb <= '9') && (symb != '.') && (symb != ',')) || (isspace(symb)))
        {
            if (symb == ' ')
                continue;
            switch (symb)
            {
            case '(':
                larr->size++;
                larr->lexems[indInLexems].kind = BRACE;
                larr->lexems[indInLexems].lex.b = LBRAC;
                corBR++;
#ifdef DEBUGBR
                printf("\n in case /(/: corBR = %d \n", corBR);
#endif
                // printf("LBR\n");
                break;
            case ')':
                larr->size++;
                larr->lexems[indInLexems].kind = BRACE;
                larr->lexems[indInLexems].lex.b = RBRAC;
                corBR--;
#ifdef DEBUGBR
                printf("\n in case /)/: corBR = %d \n", corBR);
#endif
                // printf("RBR\n");
                break;
            case '+':
                larr->size++;
                larr->lexems[indInLexems].kind = OP;
                larr->lexems[indInLexems].lex.op = ADD;
                // printf("PL\n");
                break;
            case '*':
                larr->size++;
                larr->lexems[indInLexems].kind = OP;
                larr->lexems[indInLexems].lex.op = MUL;
                // printf("MuL\n");
                break;
            case '/':
                larr->size++;
                larr->lexems[indInLexems].kind = OP;
                larr->lexems[indInLexems].lex.op = DIV;
                // printf("DiV\n");
                break;
            case '-':
                larr->size++;
                larr->lexems[indInLexems].kind = OP;
                larr->lexems[indInLexems].lex.op = SUB;
                // printf("SuB\n");
                break;
            default:
                k = 1;
                while (isdigit(inArr[index + k]))
                {
                    k++;
                }
                // int maxK = k;

                number = 0;
                // for (; k > 0; k--)
                //{
                number += atoi(&inArr[index]);
                // printf("%c - %d - %d\n", inArr[index], k, number);
                // printf("number %d = atoi %d * intPow %d\n", number, atoi(&inArr[index] + k - 1), int(pow(10, (maxK - k))));

                //}
                // printf("number = %d\n", number);
                index += k - 1;
                larr->size++;
                larr->lexems[indInLexems].kind = NUM;
                larr->lexems[indInLexems].lex.num = number;

                // printf("ERROR 3");
            }

            indInLexems += 1;
            // printf("indInLexems = %d\n", indInLexems);
        }
        else
        {
            printf("ERROR\n");
            return 0;
        }
    }

    // if (corBR != 0)
    // {
    //     printf("ERROR br");
    //     return 0;
    // }

    ///Разобраться со случаем, когда оператор рядом со скобкой

    // dump_lexarray(*larr);
    // printf("\n");

    // printf("%d", larr->lexems[0].kind);
    // printf("Before print");
    printLexArray(larr);

    for(int i = 0; i < CAMPACITY; i++){
        free(larr->lexems+i);        
    }
    
    free(larr);



    return 0;
}
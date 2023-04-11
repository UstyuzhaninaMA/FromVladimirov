#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int detSign = 1;

void printMatrix(int matSize, double **matElem);
void inputMatrix(int matSize, double **matElem);
void findMax(int matSize, double **matElem, int start);
void swapRow(double **matElem, int Row1, int Row2);
void swapCol(int matSize, double **matElem, int Col1, int Col2);


//#define DEBUG_PRINT 1

void inputMatrix(int matSize, double **matElem)
{

    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matSize; j++)
        {
            if (scanf("%lf", &matElem[i][j]) != 1)
            {
                abort();
            }
        }
    }
}

void printMatrix(int matSize, double **matElem)
{
    for (int i = 0; i < matSize; i++)
    {
        for (int j = 0; j < matSize; j++)
        {
            printf("%lf ", matElem[i][j]);
        }
        printf("\n");
    }
    printf("\n ------ \n");
}

void findMax(int matSize, double **matElem, int start)
//Поиск максимального по модулю элемента в матрице
{
    int rowWithMaxElem = start;
    int colWithMaxElem = start;
    double maxElem = 0;
    for (int i = start; i < matSize; i++)
    {
        for (int j = start; j < matSize; j++)
        {
            // printf("fabs(%d;%d) = %lf ((max = %lf)) ---- %d\n", i, j, fabs(matElem[i][j]), maxElem, ((matElem[i][j]) > maxElem));

            if (fabs(matElem[i][j]) > maxElem)
            {
                maxElem = fabs(matElem[i][j]);
                rowWithMaxElem = i;
                colWithMaxElem = j;
            }
        }
    }

#ifdef DEBUG_PRINT
    printf("-----%d %d\n", rowWithMaxElem, colWithMaxElem);
#endif

    swapRow(matElem, start, rowWithMaxElem);
    swapCol(matSize, matElem, start, colWithMaxElem);

    if ((rowWithMaxElem != start))
    {
        detSign *= -1;
    }
    if (colWithMaxElem != start)
    {
        detSign *= -1;
    }
}

void swapRow(double **matElem, int Row1, int Row2)
{
    double *elem;
    elem = matElem[Row1];
    matElem[Row1] = matElem[Row2];
    matElem[Row2] = elem;

    return;
}

void swapCol(int matSize, double **matElem, int Col1, int Col2)
{
    double elem;
    for (int i = 0; i < matSize; i++)
    {
        elem = matElem[i][Col2];
        matElem[i][Col2] = matElem[i][Col1];
        matElem[i][Col1] = elem;
    }

    return;
}

void Zanulenie(int matSize, double **matElem, int start)
{
    if (start + 1 >= matSize)
    {
        return;
    }

    if (matElem[start][start] == 0)
    {
        return;
    }

#ifdef DEBUG_PRINT
    printf("In Zanulenie, start = %d\n", start);
    fflush(stdout);
#endif

    for (int i = start; i < matSize - 1; i++)
    {

        double x = matElem[i + 1][start] / matElem[start][start];
        for (int j = start; j < matSize; j++)
        {
            matElem[i + 1][j] -= x * matElem[start][j];
        }
#ifdef DEBUG_PRINT
        printMatrix(matSize, matElem);
#endif
    }
#ifdef DEBUG_PRINT
    printf("In Zanulenie Done!\n");
    fflush(stdout);
#endif
}

void OneIneration(int matSize, double **matElem, int start)
{
    findMax(matSize, matElem, start);

#ifdef DEBUG_PRINT
    printMatrix(matSize, matElem);
#endif

    Zanulenie(matSize, matElem, start);
    return;
}

int main()
{
    int matSize;
    double det;

    double **matElem;

    if (scanf("%d", &matSize) != 1)
    {
        abort();
    }

    // initMatrix
    matElem = (double **)calloc(matSize, sizeof(double *));

    for (int i = 0; i < matSize; i++)
    {
        matElem[i] = (double *)calloc(matSize, sizeof(double));
    }

    inputMatrix(matSize, matElem);
#ifdef DEBUG_PRINT
    printMatrix(matSize, matElem);
#endif

    for (int start = 0; start < matSize; start++)
    {
        OneIneration(matSize, matElem, start);
#ifdef DEBUG_PRINT
        printMatrix(matSize, matElem);
#endif
    }

    det = 1;

    for (int i = 0; i < matSize; i++)
    {
        det *= matElem[i][i];
    }

    det *= detSign;

#ifdef DEBUG_PRINT
    printMatrix(matSize, matElem);
#endif

    for (int i = 0; i < matSize; i++)
    {
        free(matElem[i]);
    }

    free(matElem);

    printf("%d\n", (int)round(det));
}
#include <stdio.h>
#include <stdlib.h>

#define Unit int
#define Matrix Unit **

Matrix InitMatrix(int x, int y)
{
    Matrix matrix;
    matrix = (Matrix)malloc(sizeof(Unit *) * y);
    if (!matrix)
    {
        printf("Allocation error\n");
        return 0; //allocation error
    }

    for (int i = 0; i < y; i++)
    {
        matrix[i] = (Unit *)malloc(sizeof(Unit) * x);
        if (!matrix[i])
        {
            printf("Allocation error\n");
            return 0; //allocation error
        }
    }
    return matrix;
}

void AddMatrix(Matrix array_destination, Matrix array_source1, Matrix array_source2, int n, int m)
{
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            array_destination[y][x] = array_source1[y][x] + array_source2[y][x];
}

void PrintMatrix(Matrix array_source, int n, int m)
{
    printf("{\n\t");
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            printf("%d\t", array_source[y][x]);
        }
        printf("\n\t");
    }
    printf("\r}\n");
}

void AssignMatrix(Matrix array_destination, int n, int m)
{
    printf("Podaj kolejne %d elementow macierzy.\n", n * m);
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            scanf("%d", &array_destination[y][x]);
        }
    }
}

int main(int argc, char *argv[])
{
    int n = 2, m = 3;
    Matrix a;
    Matrix b;
    Matrix c;

    a = InitMatrix(n, m);
    b = InitMatrix(n, m);
    c = InitMatrix(n, m);

    AssignMatrix(a, n, m);
    AssignMatrix(b, n, m);

    printf("Dodaje macierze:\n");
    PrintMatrix(a, n, m);
    printf("Oraz\n");
    PrintMatrix(b, n, m);

    printf("\nWynik:\n");

    AddMatrix(c, a, b, n, m);
    PrintMatrix(c, n, m);
    return 0;
}
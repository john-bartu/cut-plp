/// Tittle: Exercise5
/// Description: Adding matrixes

#include <cstdio>
#include <cstdlib>

#define Unit int
#define Unit2D Unit **

Unit2D InitMatrix(int x, int y)
{
    Unit2D matrix;
    matrix = (Unit2D)malloc(sizeof(Unit *) * y);
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

void AddMatrix(Unit2D array_destination, Unit2D array_source1, Unit2D array_source2, int n, int m)
{
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            array_destination[y][x] = array_source1[y][x] + array_source2[y][x];
}

void PrintMatrix(Unit2D array_source, int n, int m)
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

void AssignMatrix(Unit2D array_destination, int n, int m)
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
    Unit2D a;
    Unit2D b;
    Unit2D c;

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
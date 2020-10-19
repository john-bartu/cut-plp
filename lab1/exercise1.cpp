/// Tittle: Exercise1
/// Description: Sort argument values
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main(int argc, char *argv[])
{
    int count = argc - 1;
    int numbers[count]; //Sometimes Compiler will have error

    for (int i = 1; i < argc; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    for (int i = 0; i < count; i++)
    {

        for (int j = 0; j < count - 1 - i; j++)
        {

            if (numbers[j] > numbers[j + 1])
            {

                swap(&numbers[j], &numbers[j + 1]);
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}
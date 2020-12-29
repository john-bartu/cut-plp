/// Tittle: Exercise2
/// Description: Check if program arguments are palindrom
#include <cstdio>
#include <cstring>

int main(int argc, char **arv)
{
    int error = 0;
    char *stringptr = arv[1];

    int length = strlen(stringptr);
    char *end = stringptr + length;

    for (int i = 0; i < length / 2; i++)
    {
        if (stringptr[i] != stringptr[length - 1 - i])
            error = 1;
    }

    if (error)
        printf("Nie jest palindromem \n");
    else
        printf("Jest palindromem \n");

    return 0;
}
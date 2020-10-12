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
    int masa_ciala = atoi(argv[1]);
    int wzrost = atoi(argv[2]);
    float BMI = 1.0 * (masa_ciala) / (wzrost/100 * wzrost/100);

    printf("Wzrost: %d , Waga: %d\n", wzrost, masa_ciala);
    printf("BMI: %lf - ", BMI);
    if (BMI < 16)
    {
        printf("wyglodzenie");
    }
    else if (BMI < 16.99)
    {
        printf("wychudzenie");
    }
    else if (BMI < 18.49)
    {
        printf("niedowaga");
    }
    else if (BMI < 24.99)
    {
        printf("wartodv prawidlowa");
    }
    else if (BMI < 29.99)
    {
        printf("nadwaga");
    }
    else if (BMI < 34.99)
    {
        printf("I stopien otylosci");
    }
    else if (BMI < 39.99)
    {
        printf("II stopień otylosci");
    }
    else
    {
        printf("otylosc skrajna");
    }

    return 0;
}
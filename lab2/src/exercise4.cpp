/// Tittle: Exercise
/// Description:

#include <iostream>

double RatioAndSum(double x, double y, double *sum)
{
    *sum = x + y;
    return x * y;
}

int main()
{
    double x = 20, y = 15;
    double sum, iloczyn;

    iloczyn = RatioAndSum(x, y, &sum);
    std::cout << "Wynik mnozenia: " << iloczyn << std::endl;
    std::cout << "wynik dodawania: " << sum << std::endl;
    return 0;
}
/// Tittle: Exercise
/// Description:

#include <iostream>

void swap(int &a, int *b)
{
    int c = *b;
    *b = a;
    a = c;
}

int main()
{
    int a = 10, b = 20; // x:10, y:20;
    std::cout << "A: " << a << " ,B: " << b << std::endl;
    swap(a, &b);        // px:20 py:10
    std::cout << "A: " << a << " ,B: " << b << std::endl;

    return 0;
}
/// Tittle: Exercise
/// Description:

#include <iostream>

void swap(int *a, int *b)
{
    if (*b < *a)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
}

int main()
{
    {
        int a = 10, b = 20; // x:10, y:20;
        std::cout << "A: " << a << " ,B: " << b << std::endl;
        swap(&a, &b);       // px:20 py:10
        std::cout << "A: " << a << " ,B: " << b << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        int a = 20, b = 10; // x:20, y:10;
        std::cout << "A: " << a << " ,B: " << b << std::endl;
        swap(&a, &b);       // px:10 py:20
        std::cout << "A: " << a << " ,B: " << b << std::endl;
    }
    return 0;
}
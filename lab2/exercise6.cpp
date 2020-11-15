/// Tittle: Exercise6
/// Description: Swap adresses of variables

#include <iostream>
#include <algorithm>
#include <iomanip>

template <class T>
void swap(T **a, T **b)
{
    T *c(*a);
    *a = *b;
    *b = c;
}

int main()
{
    int x = 10, y = 20; // x:10 y:20
    int *ptrX = &x;
    int *ptrY = &y;

    std::cout << "X: " << *ptrX << " ,Y: " << *ptrY << std::endl;
    swap(&ptrX, &ptrY); // px:20 py:10
    std::cout << "X: " << *ptrX << " ,Y: " << *ptrY << std::endl;
    return 0;
}
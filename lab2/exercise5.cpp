/// Tittle: Exercise5
/// Description: SWAP values of variables

#include <iostream>
#include <algorithm>
#include <iomanip>

template <class T>
void swap(T *a, T *b)
{
    T c(*a);
    *a = *b;
    *b = c;
}

int main()
{
    int x = 10, y = 20; // x:10 y:20
    std::cout << "X: " << x << " ,Y: " << y << std::endl;
    swap(&x, &y);       // px:20 py:10
    std::cout << "X: " << x << " ,Y: " << y << std::endl;
    return 0;
}
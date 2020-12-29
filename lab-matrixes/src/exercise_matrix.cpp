#include <iomanip>
#include <iostream>
#include "../matrix-lib/matrix.h"

using namespace std;

void printLine() {
    cout << endl;
    for (int i = 0; i < 64; i++) {
        cout << "#";
    }
    cout << endl;
}

void printLineError(const char *msg) {
    cout << msg;
}


int main() {
    try {
        cout << "Czytam macierz m1 z pliku: " << endl;
        Matrix m1 = Matrix("m1.txt", "G:/School/PK ROK 2/JiPP/jipp-labs-pk/lab-matrixes");
        m1.print();

        printLine();

        cout << "Czytam macierz m2 z pliku: " << endl;
        Matrix m2 = Matrix("m2.txt", "G:/School/PK ROK 2/JiPP/jipp-labs-pk/lab-matrixes");
        m2.print();

        printLine();

        cout << "Set m1[2][2] as m1[2][2]" << endl;
        m1.set(2, 2, m1.get(2, 2));
        cout << "M1[2][2] = " << m1.get(2, 2) << endl;

        printLine();

        cout << "Get m1[2][2]" << endl;
        cout << "M1[2][2] = " << m1.get(2, 2) << endl;

        printLine();

        cout << "Wykonuje: m1 + m2:" << endl;
        Matrix temp = m1 + m2;
        temp.print();

        printLine();

        cout << "Wykonuje: m1 - m2:" << endl;
        temp = m1 - m2;
        temp.print();

        printLine();

        cout << "Wykonuje: m1 * m2:" << endl;
        temp = m1 * m2;
        temp.print();

        printLine();

        cout << "Zapisuje m1 * m2 do pliki m3.txt" << endl;
        temp.store("m3.txt", ".");

        cout << "-- Koniec Demonstracji  --" << endl << endl;
    }
    catch (matrix_error &e) {
        printLineError(e.what());
    }

    return 0;
}

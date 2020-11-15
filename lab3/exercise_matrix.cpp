/// Tittle: Matrix Class
/// Description:

#include <iostream>
#include <fstream>
#include <iomanip>

#define Unit double
#define Unit2D Unit **

using namespace std;

class Matrix
{

private:
    int n, m;
    Unit2D data;

public:
    Matrix(int n)
    {
        this->n = n;
        this->m = n;

        data = new Unit *[n];

        for (int i = 0; i < n; i++)
        {
            data[i] = new Unit[n];

            for (int j = 0; j < n; j++)
                data[i][j] = 0;
        }
    }

    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;

        data = new Unit *[n];

        for (int i = 0; i < n; i++)
        {
            data[i] = new Unit[m];

            for (int j = 0; j < m; j++)
                data[i][j] = 0;
        }
    }

    void set(int n, int m, Unit value)
    {
        data[n][m] = value;
    }

    Unit get(int n, int m)
    {
        return data[n][m];
    }

    Matrix add(Matrix m2)
    {
        Matrix temp(n, m);

        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++)
                temp.data[y][x] = this->data[y][x] + m2.data[y][x];

        return temp;
    }

    Matrix subtract(Matrix m2)
    {
        Matrix temp(n, m);

        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++)
                temp.data[y][x] = this->data[y][x] - m2.data[y][x];

        return temp;
    }

    Matrix multiply(Matrix m2)
    {
        Matrix temp(this->n, m2.m);

        int i, j, k;
        Unit sum;

        for (i = 0; i < this->n; i++)
            for (j = 0; j < m2.m; j++)
            {
                sum = 0;
                for (k = 0; k < m2.n; k++)
                    sum += this->data[i][k] * m2.data[k][j];

                temp.data[i][j] = sum;
            }

        return temp;
    }

    // Matrix operator=(const Matrix &m2)
    // {
    //     // if the same size just change data
    //     if (this->n == m2.n && this->m == m2.m)
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             for (int j = 0; j < m; j++)
    //                 data[i][j] = m2.data[i][j];
    //         }
    //     }
    //     // if the size changed realloc memorry
    //     else
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             delete (this->data[i]);
    //         }

    //         delete (this->data);

    //         this->n = m2.n;
    //         this->m = m2.m;

    //         data = new Unit *[n];

    //         for (int i = 0; i < n; i++)
    //         {
    //             data[i] = new Unit[m];

    //             for (int j = 0; j < m; j++)
    //                 data[i][j] = 0;
    //         }
    //     }

    //     return this;
    // }

    Matrix operator+(const Matrix &m2)
    {
        return add(m2);
    }
    Matrix operator-(const Matrix &m2)
    {
        return subtract(m2);
    }
    Matrix operator*(const Matrix &m2)
    {
        return multiply(m2);
    }

    int cols()
    {
        return m;
    }

    int rows()
    {
        return n;
    }

    void print()
    {
        cout << "MATRIX N: " << n << "  M: " << m << "\n{\n\t";
        for (int y = 0; y < this->n; y++)
        {
            for (int x = 0; x < this->m; x++)
            {
                cout << "\t" << this->data[y][x];
            }
            cout << "\n\t";
        }
        cout << "\r}\n";
    }

    void store(string filename, string path)
    {
        string fullpath = path + '/' + filename;
        ofstream file(fullpath);
        if (file.is_open())
        {
            file << n << " " << m << endl;

            for (int y = 0; y < n; y++)
            {
                for (int x = 0; x < m; x++)
                {
                    file << data[y][x] << " ";
                }

                file << endl;
            }

            file.close();
        }
        else
        {
            throw runtime_error("Could not create file: " + fullpath + "\n");
        }
    }

    Matrix(string filename, string path)
    {
        string fullpath = path + '/' + filename;
        ifstream file(fullpath);
        if (file.is_open())
        {
            file >> this->n;
            file >> this->m;

            data = new Unit *[n];

            for (int i = 0; i < n; i++)
            {
                data[i] = new Unit[m];
                for (int j = 0; j < m; j++)
                    file >> data[i][j];
            }
            file.close();
        }
        else
        {
            throw runtime_error("Could not open file: " + fullpath + "\n");
        }
    }
};

void printLine()
{

    cout << endl;
    for (int i = 0; i < 64; i++)
    {
        cout << "#";
    }
    cout << endl;
}

int main()
{
    cout << "Czytam macierz m1 z pliku: " << endl;
    Matrix m1 = Matrix("m1.txt", "G:/School/PK ROK 2/JiPP/jipp-labs-pk/lab3");
    m1.print();

    printLine();

    cout << "Czytam macierz m2 z pliku: " << endl;
    Matrix m2 = Matrix("m2.txt", "G:/School/PK ROK 2/JiPP/jipp-labs-pk/lab3");
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

    return 0;
}

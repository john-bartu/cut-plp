//
// Created by bartu on 11/22/2020.
//

#include "matrix.h"
#include <exception>

using namespace std;

Matrix::Matrix(int n) {
    Matrix(n, n);
}

Matrix::Matrix(int n, int m) {
    if(n<=0){
        throw matrix_error(18, "sizes of matrix can't be <= zero");
    }

    this->n = n;
    this->m = m;

    data = new Unit *[n];

    for (int i = 0; i < n; i++) {
        data[i] = new Unit[m];

        for (int j = 0; j < m; j++)
            data[i][j] = 0;
    }
}

void Matrix::set(int n, int m, Unit value) {
    data[n][m] = value;
}

Unit Matrix::get(int n, int m) {
    return data[n][m];
}

Matrix Matrix::add(Matrix m2) {
    Matrix temp(n, m);

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            temp.data[y][x] = this->data[y][x] + m2.data[y][x];

    return temp;
}

Matrix Matrix::subtract(Matrix m2) {
    Matrix temp(n, m);

    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
            temp.data[y][x] = this->data[y][x] - m2.data[y][x];

    return temp;
}

Matrix Matrix::multiply(Matrix m2) {
    Matrix temp(this->n, m2.m);

    int i, j, k;
    Unit sum;

    for (i = 0; i < this->n; i++)
        for (j = 0; j < m2.m; j++) {
            sum = 0;
            for (k = 0; k < m2.n; k++)
                sum += this->data[i][k] * m2.data[k][j];

            temp.data[i][j] = sum;
        }

    return temp;
}

// Matrix Matrix::operator=(const Matrix &m2)
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

Matrix Matrix::operator+(const Matrix &m2) {
    return add(m2);
}

Matrix Matrix::operator-(const Matrix &m2) {
    return subtract(m2);
}

Matrix Matrix::operator*(const Matrix &m2) {
    return multiply(m2);
}

int Matrix::cols() {
    return m;
}

int Matrix::rows() {
    return n;
}

void Matrix::print() {
    cout << "MATRIX N: " << n << "  M: " << m << "\n{\n\t";
    for (int y = 0; y < this->n; y++) {
        for (int x = 0; x < this->m; x++) {
            cout << "\t" << this->data[y][x];
        }
        cout << "\n\t";
    }
    cout << "\r}\n";
}

void Matrix::store(string filename, string path) {
    string fullpath = path + '/' + filename;
    ofstream file(fullpath);
    if (file.is_open()) {
        file << n << " " << m << endl;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                file << data[y][x] << " ";
            }
            file << endl;
        }

        file.close();
    } else {
        throw runtime_error("Could not create file: " + fullpath + "\n");
    }
}

Matrix::Matrix(string filename, string path) {
    string fullpath = path + '/' + filename;
    ifstream file(fullpath);
    if (file.is_open()) {
        file >> this->n;
        file >> this->m;

        if(n<=0){
            throw matrix_error(176, "sizes of matrix can't be <= zero");
        }

        data = new Unit *[n];

        for (int i = 0; i < n; i++) {
            data[i] = new Unit[m];
            for (int j = 0; j < m; j++)
                file >> data[i][j];
        }
        file.close();
    } else {
        throw ("Could not open file: " + fullpath + "\n");
    }
}

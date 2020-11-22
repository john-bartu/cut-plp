//
// Created by bartu on 11/22/2020.
//

#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

#include <iostream>
#include <fstream>

#define Unit int
#define Unit2D Unit**


using namespace std;

class Matrix {

private:
    int n, m;
    Unit2D data;

public:
    Matrix(int n);

    Matrix(int n, int m);

    void set(int n, int m, Unit value);

    Unit get(int n, int m);

    Matrix add(Matrix m2);

    Matrix subtract(Matrix m2);

    Matrix multiply(Matrix m2);

    // Matrix operator=(const Matrix &m2);

    Matrix operator+(const Matrix &m2);

    Matrix operator-(const Matrix &m2);

    Matrix operator*(const Matrix &m2);

    int cols();

    int rows();

    void print();

    void store(string filename, string path);

    Matrix(string filename, string path);
};

#endif //LAB3_MATRIX_H

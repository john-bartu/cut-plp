//
// Created by bartu on 11/22/2020.
//

#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

#define Unit int
#define Unit2D Unit**

using namespace std;

struct matrix_error : public exception {
private:
    string message = "";

public:
    matrix_error(string text) {
        this->message += "[ERROR] Matrix Class\n\t";
        this->message += text;
        this->message += "\n";
    }

    matrix_error(int line, string text) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        this->message += "[ERROR] Matrix Class\n\t";
        this->message += "on line: ";
        this->message += to_string(line);
        this->message += "\n\t";
        this->message += text + "\n";

    }

    const char *what() const throw() {
        return message.c_str();
    }
};


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

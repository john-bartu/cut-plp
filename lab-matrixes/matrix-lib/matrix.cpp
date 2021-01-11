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
    if (n <= 0) {
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

        if (n <= 0) {
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

Matrix &Matrix::operator=(const Matrix &m2) {
    if (this == &m2)
        return *this;

    this->n = m2.n;
    this->m = m2.m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            this->data[i][j] = m2.data[i][j];
    }

    return *this;
}

bool Matrix::operator==(const Matrix &m2) {

    // Check if this is not the same matrix
    if (this == &m2)
        return true;

    // Check n size
    if (this->n != m2.n)
        return false;

    // Check m size
    if (this->m != m2.m)
        return false;

    // Check all values
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (this->data[i][j] != m2.data[i][j])
                return false;


    return true;
}


int loadMatrixData(void *data, int argc, char **argv, char **azColName) {
    vector<string> *vectorPointer = (vector<string> *) (data);
    vectorPointer->push_back(argv[1]);
    vectorPointer->push_back(argv[2]);
    vectorPointer->push_back(argv[3]);
    return 0;
}

void Matrix::store(sqlite3 *db, const string &name) {
    char *zErrMsg = nullptr;
    int resultCode;

    stringstream stringStream;
    stringStream << "INSERT INTO matrices ('matrix_name', 'n', 'm', 'data') ";
    stringStream << "VALUES ('" << name << "', '" << this->n << "', '" << this->m << "', '";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            stringStream << data[i][j] << ' ';
    stringStream << "');";

    const string &sql_str = stringStream.str();
    const char *sql = sql_str.c_str();

    resultCode = sqlite3_exec(db, sql, nullptr, nullptr, &zErrMsg);

    if (resultCode != SQLITE_OK) {
        string errorMsg;

        if (!strcmp(zErrMsg, "UNIQUE constraint failed: matrices.matrix_name"))
            errorMsg = "Matrix with name \"" + name + "\" already exists in database";
        else
            errorMsg = "Could not store matrix \"" + name + "\"";

        throw (matrix_error(errorMsg));
    }

    cout << "Successfully stored matrix \"" << name << '"' << endl;

}

Matrix::Matrix(sqlite3 *database, const string &name) {
    char *zErrMsg = nullptr;
    int resultCode;
    const char *sql;
    string sql_str;
    vector<string> matrixData;
    sql_str = "SELECT * FROM matrices WHERE matrix_name == '" + name + "';";

    sql = sql_str.c_str();
    resultCode = sqlite3_exec(database, sql, loadMatrixData, &matrixData, &zErrMsg);


    if (resultCode != SQLITE_OK) {
        string errorMsg = "Database: loading matrix \"" + name + "\"" + zErrMsg;
        throw matrix_error(errorMsg);
    }

    if (matrixData.empty()) {
        throw matrix_error("Database: matrix in database not found");
    }

    cout << "Successfully loaded matrix \"" << name << '"' << endl;

    string nString = matrixData[0];
    string mString = matrixData[1];
    stringstream dataSS(matrixData[2]);

    this->n = atoi(nString.c_str());
    this->m = atoi(mString.c_str());

    this->data = new Unit *[this->n];

    for (int i = 0; i < this->n; i++) {
        this->data[i] = new Unit[this->m];

        for (int j = 0; j < this->m; j++) {

            string buf;
            dataSS >> buf;

            this->data[i][j] = atof(buf.c_str());;
        }
    }
}

bool Matrix::operator!=(const Matrix &m2) {
    return !operator==(m2);
}


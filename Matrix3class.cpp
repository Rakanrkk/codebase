//
// Created by Rakan on 2022/4/24.
//
#include <iostream>

using namespace std;

class Matrix3 {
public:
    Matrix3() = default;

    explicit Matrix3(const int a[]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                data[i][j] = a[i * 3 + j];
    }

    ~Matrix3() = default;

    Matrix3 operator+(const Matrix3 &matrix3) {
        Matrix3 tmp = matrix3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                tmp.data[i][j] += data[i][j];
            }
        }
        return tmp;
    }

    Matrix3 operator-(const Matrix3 &matrix3) {
        Matrix3 tmp = matrix3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp.data[i][j] -= data[i][j];
            }
        }
        return tmp;
    }

    Matrix3 operator*(const Matrix3 &matrix3) {
        Matrix3 tmp;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    tmp.data[i][j] += data[i][k] * M.data[k][j];
        return tmp;
    }

    Matrix3 operator*(int k) const {
        Matrix3 tmp(*this);
        for (auto & i : tmp.data)
            for (int & j : i)
                j *= k;
        return tmp;
    }

    friend istream &operator>>(istream &input, Matrix3 &matrix) {
        for (auto &i: matrix.data) {
            for (int &j: i) {
                cin >> j;
            }
        }
        return input;
    }

    friend ostream &operator<<(ostream &output, Matrix3 &matrix) {
        for (auto &i: matrix.data) {
            for (int &j: i) {
                cout << j << ' ';
            }
        }
        return output;
    }

private:
    int data[3][3]{};

};
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

    Matrix3 operator+(const Matrix3 &matrix3) const {
        Matrix3 tmp = *this;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                tmp.data[i][j] += matrix3.data[i][j];
            }
        }
        return tmp;
    }

    Matrix3 operator-(const Matrix3 &matrix3) const {
        Matrix3 tmp = *this;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp.data[i][j] -= matrix3.data[i][j];
            }
        }
        return tmp;
    }

    Matrix3 operator*(const Matrix3 &matrix3) const {
        Matrix3 tmp ;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    tmp.data[i][j] += data[i][k] * matrix3.data[k][j];
        return tmp;
    }

    Matrix3 operator*(int k) const {
        Matrix3 tmp = *this;
        for (auto &i: tmp.data)
            for (auto &j: i)
                j *= k;
        return tmp;
    }

    friend Matrix3 operator*(int k, const Matrix3 &M) {
        return M * k;
    }

    friend istream &operator>>(istream &input, Matrix3 &matrix) {
        for (auto &i: matrix.data) {
            for (auto &j: i) {
                input >> j;
            }
        }
        return input;
    }

    friend ostream &operator<<(ostream &output, const Matrix3 &matrix) {
        for (auto &i: matrix.data) {
            for (auto &j: i) {
                output << j << ' ';
            }
        }
        return output;
    }

private:
    int data[3][3]{};

};

int main() {
    int k;
    cin >> k;
    Matrix3 m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    cout << (m1 + m2 - m3) * k << endl;
    cout << (m1 * m2 * m3) * k << endl;
    return 0;
}
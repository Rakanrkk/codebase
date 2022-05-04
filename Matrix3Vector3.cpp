//
// Created by Rakan on 2022/5/4.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


class Vector3;

class Matrix3;

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
        Matrix3 tmp;
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

    Vector3 operator*(const Vector3 &vector3);

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

    friend class Vector3;
};

class Vector3 {
public:
    explicit Vector3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    ~Vector3() = default;

    double abs() const {
        return sqrt(x * x + y * y + z * z);
    }

    bool operator==(const Vector3 &cv) const {
        return this->abs() == cv.abs();
    }

    bool operator!=(const Vector3 &cv) const {
        return !(*this == cv);
    }

    bool operator<(const Vector3 &cv) const {
        return this->abs() < cv.abs();
    }

    bool operator<=(const Vector3 &cv) const {
        return this->abs() <= cv.abs();
    }

    bool operator>(const Vector3 &cv) const {
        return this->abs() > cv.abs();
    }

    bool operator>=(const Vector3 &cv) const {
        return this->abs() >= cv.abs();
    }

    Vector3 &operator=(const Vector3 &cv) = default;

    Vector3 operator+(const Vector3 &cv) const {
        Vector3 result;
        result.x = x + cv.x;
        result.y = y + cv.y;
        result.z = z + cv.z;
        return result;
    }

    Vector3 operator-(const Vector3 &cv) const {
        Vector3 result;
        result.x = x - cv.x;
        result.y = y - cv.y;
        result.z = z - cv.z;
        return result;
    }

    Vector3 operator*(const int k) const {
        Vector3 result;
        result.x = x * k;
        result.y = y * k;
        result.z = z * k;
        return result;
    }

    Vector3 operator*(const Vector3 &cv) const {
        Vector3 result;
        result.x = y * cv.z - z * cv.y;
        result.y = z * cv.x - x * cv.z;
        result.z = x * cv.y - y * cv.x;
        return result;
    }

    Vector3 operator*(const Matrix3 &matrix3) const {
        Vector3 ans;
        ans.x = x * matrix3.data[0][0] + y * matrix3.data[1][0] + z * matrix3.data[2][0];
        ans.y = x * matrix3.data[0][1] + y * matrix3.data[1][1] + z * matrix3.data[2][1];
        ans.z = x * matrix3.data[0][2] + y * matrix3.data[1][2] + z * matrix3.data[2][2];
        return ans;
    }

    friend istream &operator>>(istream &input, Vector3 &cv) {
        input >> cv.x >> cv.y >> cv.z;
        return input;
    }

    friend ostream &operator<<(ostream &output, const Vector3 &cv) {
        output << cv.x << " " << cv.y << " " << cv.z;
        return output;
    }

private:
    int x;
    int y;
    int z;

    friend class Matrix3;
};


Vector3 Matrix3::operator*(const Vector3 &vector3) {
    Vector3 ans;
    ans.x = vector3.x * data[0][0] + vector3.y * data[0][1] + vector3.z * data[0][2];
    ans.y = vector3.x * data[1][0] + vector3.y * data[1][1] + vector3.z * data[1][2];
    ans.z = vector3.x * data[2][0] + vector3.y * data[2][1] + vector3.z * data[2][2];
    return ans;
}

int main()
{
    Vector3 v;
    cin >> v;
    Matrix3 m;
    cin >> m;
    cout << v * v<<endl;
    cout << v * m<<endl;
    cout << m * v<<endl;
    cout << m * m<<endl;
    return 0;
}
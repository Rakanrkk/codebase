//
// Created by Rakan on 2022/5/3.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Vector3;

class Matrix3 {
    friend class Vector3;

    int v[3][3]{};
public:
    Vector3 operator*(const Vector3 &V);

    Matrix3() {
        memset(v, 0, sizeof v);
    }

    explicit Matrix3(const int a[]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                v[i][j] = a[i * 3 + j];
    }

    Matrix3(const Matrix3 &M) {
        memcpy(v, M.v, sizeof M.v);
    }

    int rowsum(int k) const {
        int ans = 0;
        for (int i = 0; i < 3; i++) ans += v[k][i];
        return ans;
    }

    Matrix3 &operator=(const Matrix3 &M) {
        if (this == &M) return *this;
        memcpy(v, M.v, sizeof M.v);
        return *this;
    }

    Matrix3 operator+(const Matrix3 &M) {
        Matrix3 ans(*this);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                ans.v[i][j] += M.v[i][j];
        return ans;
    }

    Matrix3 operator-(const Matrix3 &M) {
        Matrix3 ans(*this);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                ans.v[i][j] -= M.v[i][j];
        return ans;
    }

    Matrix3 operator*(const Matrix3 &M) {
        Matrix3 ans;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    ans.v[i][j] += v[i][k] * M.v[k][j];
        return ans;
    }

    Matrix3 operator*(int k) const {
        Matrix3 ans(*this);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                ans.v[i][j] *= k;
        return ans;
    }

    friend Matrix3 operator*(int k, const Matrix3 &M) {
        return M * k;
    }

    friend ostream &operator<<(ostream &os, const Matrix3 &M) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                os << M.v[i][j] << " ";
        return os << endl;
    }

    friend istream &operator>>(istream &is, Matrix3 &M) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                is >> M.v[i][j];
        return is;
    }
};

class Vector3 {
    friend class Matrix3;

    int x, y, z;
public:
    Vector3(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {

    }

    Vector3(const Vector3 &V) {
        x = V.x;
        y = V.y;
        z = V.z;
    }

    Vector3 &operator=(const Vector3 &V) {
        if (this == &V) return *this;
        x = V.x;
        y = V.y;
        z = V.z;
        return *this;
    }

    Vector3 operator+(const Vector3 &V) {
        Vector3 ans;
        ans.x = x + V.x;
        ans.y = y + V.y;
        ans.z = z + V.z;
        return ans;
    }

    Vector3 operator-(const Vector3 &V) {
        Vector3 ans;
        ans.x = x - V.x;
        ans.y = y - V.y;
        ans.z = z - V.z;
        return ans;
    }

    Vector3 operator*(const Vector3 &V) const {
        Vector3 ans;
        ans.x = y * V.z - V.z * y;
        ans.y = V.x * z - x * V.z;
        ans.z = x * V.y - V.x * y;
        return ans;
    }

    Vector3 operator*(int k) {
        return Vector3(x * k, y * k, z * k);
    }

    Vector3 operator*(const Matrix3 &M) {
        Vector3 ans;
        ans.x = x * M.v[0][0] + y * M.v[1][0] + z * M.v[2][0];
        ans.y = x * M.v[0][1] + y * M.v[1][1] + z * M.v[2][1];
        ans.z = x * M.v[0][2] + y * M.v[1][2] + z * M.v[2][2];
        return ans;
    }

    friend Vector3 operator*(int k, const Vector3 &V) {
        return V * k;
    }

    friend ostream &operator<<(ostream &os, const Vector3 &V) {
        os << V.x << " " << V.y << " " << V.z;
        return os << endl;
    }

    friend istream &operator>>(istream &is, Vector3 &V) {
        is >> V.x >> V.y >> V.z;
        return is;
    }
};


Vector3 Matrix3::operator*(const Vector3 &V) {
    Vector3 ans;
    ans.x = V.x * v[0][0] + V.y * v[0][1] + V.z * v[0][2];
    ans.y = V.x * v[1][0] + V.y * v[1][1] + V.z * v[1][2];
    ans.z = V.x * v[2][0] + V.y * v[2][1] + V.z * v[2][2];
    return ans;
}

int main() {
    Vector3 v;
    cin >> v;
    Matrix3 m;
    cin >> m;
    cout << v * v;
    cout << v * m;
    cout << m * v;
    cout << m * m;
    return 0;
}

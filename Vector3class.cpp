//
// Created by Rakan on 2022/4/22.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

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
};

int main() {
    int n;
    cin >> n;
    Vector3 data[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data, data+n);
    for (int i = 0; i < n; i++) {
        cout << data[i]<<endl;
    }
    return 0;
}
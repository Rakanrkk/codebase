//
// Created by Rakan on 2022/4/22.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class CubeVector {
public:
    explicit CubeVector(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    ~CubeVector() = default;

    double abs() const {
        return sqrt(x * x + y * y + z * z);
    }

    bool operator==(const CubeVector &cv) const {
        return this->abs() == cv.abs();
    }

    bool operator!=(const CubeVector &cv) const {
        return !(*this == cv);
    }

    bool operator<(const CubeVector &cv) const {
        return this->abs() < cv.abs();
    }

    bool operator<=(const CubeVector &cv) const {
        return this->abs() <= cv.abs();
    }

    bool operator>(const CubeVector &cv) const {
        return this->abs() > cv.abs();
    }

    bool operator>=(const CubeVector &cv) const {
        return this->abs() >= cv.abs();
    }

    CubeVector &operator=(const CubeVector &cv) = default;

    CubeVector operator+(const CubeVector &cv) const {
        CubeVector result;
        result.x = x + cv.x;
        result.y = y + cv.y;
        result.z = z + cv.z;
        return result;
    }

    CubeVector operator-(const CubeVector &cv) const {
        CubeVector result;
        result.x = x - cv.x;
        result.y = y - cv.y;
        result.z = z - cv.z;
        return result;
    }

    CubeVector operator*(const int k) const {
        CubeVector result;
        result.x = x * k;
        result.y = y * k;
        result.z = z * k;
        return result;
    }

    CubeVector operator*(const CubeVector &cv) const {
        CubeVector result;
        result.x = y * cv.z - z * cv.y;
        result.y = z * cv.x - x * cv.z;
        result.z = x * cv.y - y * cv.x;
        return result;
    }

    friend istream &operator>>(istream &input, CubeVector &cv) {
        input >> cv.x >> cv.y >> cv.z;
        return input;
    }

    friend ostream &operator<<(ostream &output, const CubeVector &cv) {
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
    CubeVector data[n];
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data, data+n);
    for (int i = 0; i < n; i++) {
        cout << data[i]<<endl;
    }
    return 0;
}
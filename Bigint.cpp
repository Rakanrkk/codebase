//
// Created by Rakan on 2022/5/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Bigint : public vector<int> {
public:

    Bigint(int n = 0)//默认初始化为0，但0的保存形式为空
    {
        push_back(n);
        check();
    }

    Bigint &check() {
        while (!empty() && !back())pop_back();//去除最高位可能存在的0
        if (empty())return *this;
        for (int i = 1; i < size(); ++i) {
            (*this)[i] += (*this)[i - 1] / 10;
            (*this)[i - 1] %= 10;
        }
        while (back() >= 10) {
            push_back(back() / 10);
            (*this)[size() - 2] %= 10;
        }
        return *this;//为使用方便，将进位后的自身返回引用
    }//在各类运算中经常用到的进位小函数，不妨内置

    Bigint operator*(const Bigint &bigint) const {
        Bigint result;
        result.assign(size() + bigint.size() - 1, 0);
        for (int i = 0; i != size(); ++i)
            for (int j = 0; j != bigint.size(); ++j)
                result[i + j] += (*this)[i] * bigint[j];
        result.check();
        return result;
    }

    Bigint &operator+=(const Bigint &b) {
        if (size() < b.size()) resize(b.size());
        for (int i = 0; i != b.size(); ++i) (*this)[i] += b[i];
        return check();
    }

    Bigint operator+(const Bigint &b) {
        return *this += b;
    }

//减法，返回差的绝对值，由于后面有交换，故参数不用引用
    Bigint &operator-=(Bigint b) {
        if (*this < b) swap( b);
        for (int i = 0; i != b.size(); (*this)[i] -= b[i], ++i)
            if ((*this)[i] < b[i])//需要借位
            {
                int j = i + 1;
                while (!(*this)[j])++j;
                while (j > i) {
                    --(*this)[j];
                    (*this)[--j] += 10;
                }
            }
        return check();
    }

    Bigint operator-(const Bigint &b) {
        return *this -= b;
    }

    Bigint &operator*=(const Bigint &bigint) {
        return *this = *this * bigint;
    }


    bool operator!=(const Bigint &bigint) {
        if (size() != bigint.size()) return true;
        for (int i = (int) size() - 1; i >= 0; --i)
            if ((*this)[i] != bigint[i]) return true;
        return false;
    }

    bool operator==(const Bigint &b) {
        return !(*this != b);
    }

    bool operator==(const Bigint &a, const Bigint &b) {
        return !(a != b);
    }


    Bigint pow(const Bigint &k) {
        if (k.empty()) return 1;
        if (k == 2) return *this * *this;
        if (k.front() % 2)return *this * pow(*this, k - 1);
        return pow(pow(*this, k / 2), 2);
    }

//    friend bool operator==(const Bigint &a, const Bigint &b) {
//        return !(a != b);
//    }

    friend istream &operator>>(istream &input, Bigint &bigint) {
        string tmp;
        input >> tmp;
        bigint.clear();
        for (int i = (int) tmp.size() - 1; i >= 0; i++) bigint.push_back(tmp[i] - '0');
        return input;
    }

    friend ostream &operator<<(ostream &output, const Bigint &bigint) {
        if (bigint.empty()) output << 0;
        for (int i = (int) bigint.size() - 1; i >= 0; --i) output << bigint[i];
        return output;
    }

};


bool operator==(const Bigint &a, const Bigint &b) {
    return !(a != b);
}




bool operator!=(const Bigint &a, const Bigint &b) {
    if (a.size() != b.size())return true;
    for (int i = a.size() - 1; i >= 0; --i)
        if (a[i] != b[i])return true;
    return false;
}

Bigint pow(const Bigint &n, const Bigint &k) {
    if (k.empty())return 1;
    if (k == 2)return n * n;
    if (k.front() % 2)return n * pow(n, k - 1);
    return pow(pow(n, k / 2), 2);
}
int main() {
    Bigint k(2);
    k = 2;
    k = k * 2;
    return 0;
}

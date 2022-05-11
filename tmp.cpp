//
// Created by Rakan on 2022/5/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Bigint : public vector<int> {
public:

    Bigint(int n = 0){
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
    }

    bool operator!=(const Bigint &bigint) const {
        if (size() != bigint.size()) return true;
        for (int i = (int) size() - 1; i >= 0; --i)
            if ((*this)[i] != bigint[i]) return true;
        return false;
    }

//    friend bool operator!=(const Bigint &a, const Bigint &b){
//        if (a.size() != b.size()) return true;
//        for (int i = (int) a.size() - 1; i >= 0; --i)
//            if (a[i] != b[i]) return true;
//        return false;
//    }

    Bigint test(const Bigint &bigint)
    {
        return bigint != 2;
    }
};


int main() {
    Bigint k;
    k = 2;
    k != 2;
    return 0;
}

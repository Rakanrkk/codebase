//
// Created by Rakan on 2022/4/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SeqList {
public:
    explicit SeqList() = default;

    ~SeqList() = default;

    SeqList &operator=(const SeqList &sl) = default;

    void sort() {
        ::sort(data.begin(), data.end());
    }

    SeqList intersect(const SeqList &sl) {
        SeqList result;
        for (auto i: data) {
            for (auto j: sl.data) {
                if (i == j)
                    result.data.push_back(i);
            }
        }
        return result;
    }

    SeqList operator+(const SeqList &sl) const {
        SeqList result;
        result = *this;
        for (auto i: sl.data) {
            result.data.push_back(i);
        }
        return result;
    }

    friend ostream &operator<<(ostream &output, const SeqList &sl) {
        for (auto i: sl.data) {
            output << i << ' ';
        }
        return output;
    }

    friend istream &operator>>(istream &input, SeqList &sl) {
        int tmp;
        input >> tmp;
        sl.data.push_back(tmp);
        return input;
    }

private:
    vector<int> data;
};


int main() {
    int n, m;
    SeqList a, b, result;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b;
    }
    result = a + b;
    result.sort();
    cout << result;
    return 0;
}
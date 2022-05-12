//
// Created by Rakan on 2022/5/4.
//

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

class Polylist {
public:

    int calculate(int x) {
        int ans = 0;
        for (auto pair: m) {
            ans += pair.second * (int) pow(x, pair.first);
        }
        return ans;
    }

    Polylist operator+(const Polylist &polylist) const {
        Polylist result = *this;
        for (auto pair: polylist.m)
            result.m[pair.first] += pair.second;
        return result;
    }

    Polylist operator*(const Polylist &polylist) const {
        Polylist temp;
        auto iter1 = m.begin();
        while (iter1 != m.end()) {
            auto iter2 = polylist.m.begin();
            while (iter2 != polylist.m.end()) {
                temp.m[iter1->first + iter2->first] += iter1->second * iter2->second;
                iter2++;
            }
            iter1++;
        }
        return temp;
    }

    friend istream &operator>>(istream &input, Polylist &polylist) {
        int n, k;
        input >> n >> k;
        polylist.m[k] += n;
        return input;
    }

    friend ostream &operator<<(ostream &output, const Polylist &polylist) {
        for (auto iter = polylist.m.rbegin(); iter != polylist.m.rend(); iter++) {
            if (iter->second)
                output << iter->second << " " << iter->first << ' ';
        }
        return output;
    }

private:
    map<int, int> m;
};


int main() {
    Polylist pl1, pl2;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pl1;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pl2;
    }
    cout << pl1 + pl2 << endl;
    cout << pl1 * pl2 << endl;
    return 0;
}
// author:shujakuin  2022-05-02  14:22:06
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class PolyListNode {
    map<int, int> m;
public:
    friend istream &operator>>(istream &in, PolyListNode &list) {
        int n, k;
        in >> n >> k;
        list.m[k] += n;
        return in;
    }

    int calculate(int x) {
        auto iter = m.begin();
        int ans = 0;
        while (iter != m.end()) {
            ans += (iter->second) * pow(x, iter->first);
            iter++;

        }
        return ans;
    }

    PolyListNode operator+(const PolyListNode &other) const {
        PolyListNode temp(*this);
        auto iter = other.m.begin();
        while (iter != other.m.end()) {
            temp.m[iter->first] += iter->second;
            iter++;
        }
        return temp;
    }

    friend ostream &operator<<(ostream &out, const PolyListNode &Li) {
        auto iter = Li.m.rbegin();
        while (iter != Li.m.rend()) {
            if (iter->second)
                out << iter->second << " " << iter->first << " ";
            iter++;
        }
        return out;
    }
};

int main() {

    PolyListNode Li1, Li2;
    int n;
    cin >> n;
    while (n--)
        cin >> Li1;
    cin >> n;
    while (n--)
        cin >> Li2;
    cout << Li1 + Li2 << endl;


    return 0;

}

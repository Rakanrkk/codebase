#include <iostream>

using namespace std;

class Date {
public:
    explicit Date(int y = 1970, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    void set(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    bool isleap() const {
        if (year % 400 == 0) return true;
        if (year % 100 != 0 && year % 4 == 0) return true;
        return false;
    }

    int monthLen() const {
        if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
        if (month == 2) return 28 + isleap();
        return 31;
    }

    void alteration(int d) {
        day += d;
        while (day > monthLen()) {
            day -= monthLen();
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        while (day <= 0) {
            month--;
            if (month <= 0) {
                month = 12;
                year--;
            }
            day += monthLen();
        }
    }

    int distance(Date d) const {
        Date tmp = *this;
        int cnt = 0;
        while (tmp != d) {
            tmp++;
            cnt++;
        }
        return cnt;
    }

    Date operator+(int d) const {
        Date date;
        date = *this;
        date.alteration(d);
        return date;
    }

    void operator++() {
        *this = *this + 1;
    }

    void operator++(int) {
        *this = *this + 1;
    }

    void operator=(const Date &d) {
        year = d.year;
        month = d.month;
        day = d.day;
    }

    bool operator==(const Date &d) const {
        if (year == d.year && month == d.month && day == d.day) return true;
        else return false;
    }

    bool operator!=(const Date &d) {
        return !(*this == d);
    }

    void operator+=(int d) {
        this->alteration(d);

    }

    int operator-(Date &d) const {
        return d.distance(*this);
    }

    friend ostream &operator<<(ostream &output, const Date &date) {
        output << date.year << ' ' << date.month << ' ' << date.day;
        return output;
    }

    friend istream &operator>>(istream &input, Date &date) {
        input >> date.year >> date.month >> date.day;
        return input;
    }

private:
    int year;
    int month;
    int day;
};

int main() {
    Date d1, d2;
    cin >> d1 >> d2;
    int c = d1.distance(d2);

    cout << c;

    return 0;
}
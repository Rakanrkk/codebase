//
// Created by Rakan on 2022/5/12.
//
#include <iostream>

using namespace std;

class Date {
public:
    explicit Date(int y = 1970, int m = 1, int d = 1) : year(y), month(m), day(d) {
        cout << "Date is Constructed: " << year << "-" << month << "-" << day << endl;
    }

    ~Date() {
        cout << "Date is Deconstructed: " << *this << endl;
    }

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

    Date &operator=(const Date &d) = default;

    bool operator>(const Date &d) const {
        if (year > d.year) return true;
        if (month > d.month) return true;
        if (day > d.day) return true;
        return false;
    }

    bool operator>=(const Date &d) const {
        if (year < d.year) return false;
        if (month < d.month) return false;
        if (day < d.day) return false;
        return true;
    }

    bool operator<(const Date &d) const {
        if (year < d.year) return true;
        if (month < d.month) return true;
        if (day < d.day) return true;
        return false;
    }

    bool operator<=(const Date &d) const {
        if (year > d.year) return false;
        if (month > d.month) return false;
        if (day > d.day) return false;
        return true;
    }

    bool operator==(const Date &d) const {
        if (year == d.year && month == d.month && day == d.day) return true;
        return false;
    }

    bool operator!=(const Date &d) const {
        return !(*this == d);
    }

    void operator+=(int d) {
        this->alteration(d);

    }

    int operator-(Date &d) const {
        return d.distance(*this);
    }

    friend ostream &operator<<(ostream &output, const Date &date) {
        output << date.year << '-' << date.month << '-' << date.day;
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

class Person {
public:
    Person(string name = "", int y1 = 0, int m1 = 0, int d1 = 0, int y2 = 0, int m2 = 0, int d2 = 0) :
            Birth(y1, m1, d1), Leave(y2, m2, d2), name(name) {
        cout << "Person is Constructed: " << name << endl;
    }

    ~Person() {
        cout << "Person is Deconstructed: " << name << endl;
    }

    void print() {
        cout << name << " " << Birth << " " << Leave << endl;
    }

    bool operator<(Person &other) {
        return Birth < other.Birth;
    }

private:
    Date Birth, Leave;
    string name;
};

int main() {
    int y1, m1, d1, y2, m2, d2;
    string name;
    cin >> name >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    Person *p1 = new Person(name, y1, m1, d1, y2, m2, d2);
    cin >> name >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    Person *p2 = new Person(name, y1, m1, d1, y2, m2, d2);
    p1->print();
    p2->print();
    if (*p1 < *p2) {
        delete p2;
        delete p1;
    } else {
        delete p1;
        delete p2;
    }
    return 0;
}

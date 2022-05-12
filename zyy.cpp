#include "bits/stdc++.h"

using namespace std;

class Date {
    int year, month, day;
    int mo_stand[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
public:
    Date(int y = 0, int mo = 0, int day = 0) : year(y), month(mo), day(day) {
        cout << "Date is Constructed: " << y << "-" << mo << "-" << day << endl;
    };

    ~Date() {
        cout << "Date is Deconstructed: " << *this << endl;
    }

    Date(string s) {
        int year = 0, mo = 0, day = 0;
        int index = 0;
        while (s[index] != '-') {
            year += s[index++] - '0';
            year *= 10;
        }
        year /= 10;
        index++;
        while (s[index] != '-') {
            mo += s[index++] - '0';
            mo *= 10;
        }
        mo /= 10;
        index++;
        while (index < s.length()) {
            day += s[index++] - '0';
            day *= 10;
        }
        day /= 10;
    }

    friend istream &operator>>(istream &in, Date &d) {
        in >> d.year >> d.month >> d.day;
        return in;
    }

    int leap_year() {
        return leap_year(year);
    }

    int leap_year(int y) {
        return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
    }

    void standard() {
        year += (month - 1) / 12;
        if (month > 12)
            month = month % 12 + 1;
        while (day > mo_stand[leap_year()][month]) {
            if (day > mo_stand[leap_year()][month]) {
                day -= mo_stand[leap_year()][month];
            }
            month += 1;
            if (month > 12) {
                year += 1;
                month = 1;
            }
        }
    }

    void change(int t) {
        day += t;
        standard();
    }

    friend ostream &operator<<(ostream &out, const Date &d) {
        out << d.year << "-" << d.month << "-" << d.day;
        return out;
    }

    int daystramp() {
        standard();
        long long daystr = 0;
        for (int i = 0; i < year; i++)
            daystr += 365 + leap_year(i);
        for (int j = 1; j < month; j++)
            daystr += mo_stand[leap_year()][j];
        daystr += day;
        return daystr;
    }

    bool operator<(Date &other) {
        return daystramp() < other.daystramp();
    }
};


class Person {
    Date Birth, Leave;
    string name;
public:
    Person(string name = "", int y1 = 0, int m1 = 0, int d1 = 0, int y2 = 0, int m2 = 0, int d2 = 0) : Birth(y1, m1,
                                                                                                             d1),
                                                                                                       Leave(y2, m2,
                                                                                                             d2),
                                                                                                       name(name) {
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
};

class Persons {
    vector<Person *> v;
public:
    Persons() {
        cout << "Persons is Constructed." << endl;
    }

    void push_back(Person *other) {
        v.push_back(other);
    }

    void print() {
        for (int i = 0; i < v.size(); i++) {
            v[i]->print();
        }
    }

    ~Persons() {
        const int nums = v.size();
        for (int i = 0; i < nums; i++) {
            delete v[i];
        }
        cout << "Persons is Deconstructed." << endl;
    }
};

int main() {
    string name;
    Persons ps;
    int y1, m1, d1, y2, m2, d2;
    int n;
    cin >> n;
    while (n--) {
        cin >> name >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
        ps.push_back(new Person(name, y1, m1, d1, y2, m2, d2));
    }
    ps.print();

    return 0;
}

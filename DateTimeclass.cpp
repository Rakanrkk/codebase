//
// Created by Rakan on 2022/4/15.
//

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

class Time {
public:
    explicit Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        delta_day = 0;
        this->check();
    }

    ~Time() = default;

    void set(int h, int m, int s) {
        hour = h;
        minute = m;
        second = s;
    }

    int get_delta_day() const
    {
        return delta_day;
    }

    void check() {
        while (second >= 60) {
            second -= 60;
            minute += 1;
        }
        while (minute >= 60) {
            minute -= 60;
            hour += 1;
        }
        while (hour >= 24) {
            hour -= 24;
            delta_day++;
        }
        while (second < 0) {
            second += 60;
            minute -= 1;
        }
        while (minute < 0) {
            minute += 60;
            hour -= 1;
        }
        while (hour < 0) {
            hour += 24;
            delta_day--;
        }
    }

    Time operator+(int s) const {
        Time time;
        time.second = this->second + s;
        time.minute = this->minute;
        time.hour = this->hour;
        time.check();
        return time;
    }

    Time &operator+=(int s) {
            *this = *this + s;
          return *this;
    }

    Time operator-(int s) const {
        Time time;
        time.second = this->second - s;
        time.minute = this->minute;
        time.hour = this->hour;
        time.check();
        return time;
    }

    Time &operator=(const Time &time) = default;

    int operator-(Time &time) const {
        Time tmp;
        int ans = 0;
        tmp.hour = this->hour - time.hour;
        tmp.minute = this->minute - time.minute;
        tmp.second = this->second - time.second;
        ans = tmp.hour * 3600 + tmp.minute * 60 + tmp.second;
        return ans;
    }

    friend ostream &operator<<(ostream &output, const Time &time) {
        output << time.hour << ' ' << time.minute << ' ' << time.second;
        return output;
    }

    friend istream &operator>>(istream &input, Time &time) {
        input >> time.hour >> time.minute >> time.second;
        return input;
    }

private:
    int hour;
    int minute;
    int second;
    int delta_day;
};

class DateTime {
public:
    explicit DateTime(int year = 1970, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0) :
            date(year, month, day), time(hour, minute, second) {}

    ~DateTime() = default;

    DateTime operator+(int s) {
        time+=s;
        date+=time.get_delta_day();
        return *this;
    }

    int operator-(DateTime &dt) {
        int ans=0;
        ans+=(date-dt.date)*3600*24;
        ans+=time-dt.time;
        return ans;
    }

    DateTime &operator=(const DateTime &d) = default;

    friend ostream &operator<<(ostream &output, const DateTime &dt) {
        output << dt.date << ' ' << dt.time;
        return output;
    }

    friend istream &operator>>(istream &input, DateTime &dt) {
        input >> dt.date >> dt.time;
        return input;
    }

private:
    Date date;
    Time time;
};

int main()
{
    DateTime dt1, dt2;
    cin>>dt1>>dt2;
    cout<<dt2-dt1;
    return 0;
}
#include <iostream>
using namespace std;
class Time
{
public:
    explicit Time(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){this->check();}
    ~Time()= default;
    void set(int h,int m,int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void check()
    {
        while(second>=60)
        {
            second-=60;
            minute+=1;
        }
        while(minute>=60)
        {
            minute-=60;
            hour+=1;
        }
        while(hour>=24)
        {
            hour-=24;
        }
        while(second<=0)
        {
            second+=60;
            minute-=1;
        }
        while(minute<=0)
        {
            minute+=60;
            hour-=1;
        }
        while(hour<=0)
        {
            hour+=24;
        }
    }
    Time operator+(int s) const
    {
        Time time;
        time.second=this->second+s;
        time.minute=this->minute;
        time.hour=this->hour;
        time.check();
        return time;
    }
    Time operator-(int s) const
    {
        Time time;
        time.second=this->second-s;
        time.minute=this->minute;
        time.hour=this->hour;
        time.check();
        return time;
    }
    int operator-(Time &time) const
    {
        Time tmp;
        int ans=0;
        tmp.hour=this->hour-time.hour;
        tmp.minute=this->minute-time.minute;
        tmp.second=this->second-time.second;
        ans=tmp.hour*3600+tmp.minute*60+tmp.second;
        return ans;
    }
    friend ostream &operator<<(ostream &output,const Time &time)
    {
        output<<time.hour<<' '<<time.minute<<' '<<time.second;
        return output;
    }
    friend istream &operator>>(istream &input,Time &time)
    {
        input>>time.hour>>time.minute>>time.second;
        return input;
    }

private:
    int hour;
    int minute;
    int second;
};

int main()
{
    Time t;
    cin>>t;
    t.check();
    cout<<t;
    return 0;
}
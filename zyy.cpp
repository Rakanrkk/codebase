#include "bits/stdc++.h"
using namespace std;
class SeqList
{
private:
    vector<int> data;
public:
    friend istream& operator >>(istream& in,SeqList& v)
    {
        int temp;
        in >> temp ;
        v.data.push_back(temp);
        return in;
    }
    void add_min(const SeqList &other)
    {
        for(auto X:other.data)
        {
            if(X<0)
            {
                auto p = data.begin();
                while(p!=data.end())
                {
                    if(*p==-X)
                    {
                        auto now = p;
                        p++;
                        data.erase(now);
                        continue;
                    }
                    p++;
                }
            }
            else
                data.push_back(X);
        }
    }
    SeqList intersect(const SeqList& other)
    {
        SeqList s;
        for(auto Y:data)
        {
            for(auto X:other.data)
                if(X==Y)
                    s.data.push_back(X);
        }
        return s;
    }
    SeqList  Merge(const SeqList& other) const
    {
        SeqList s;
        auto p1=data.begin();auto p2=other.data.begin();
        while(p1!=data.end() && p2!=other.data.end())
        {
            if(*p1<*p2) {s.data.push_back(*p1);p1++;}
            else {s.data.push_back(*p2);p2++;}
        }
        while(p1!=data.end())
        {
            s.data.push_back(*p1);
            p1++;
        }
        while(p2!=other.data.end())
        {
            s.data.push_back(*p2);
            p2++;
        }
        return s;
    }
    friend ostream& operator<<(ostream& out,SeqList s)
    {
        for(auto X:s.data)
            out << X << " ";
        return out;
    }

};

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    int n;
    SeqList s1,s2,s;
    cin >> n;
    while(n--)
        cin>>s1;
    cin >> n;
    while(n--)
        cin>>s2;
    s = s1.Merge(s2);
    cout << s;
    return 0;
}

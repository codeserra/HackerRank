#include <bits/stdc++.h>

using namespace std;

const int base = 1000000000;
const int base_digits = 9;

struct bigint
{
    vector<int > a;
    int sign;
    bigint(): sign(1){}
    bigint(long long v) {
        *this = v;
    }
    //bigint(const string & s){
    //    read(s);
    //}
    void operator=(const bigint &v){
        sign = v.sign;
        a = v.a;
    }
    void operator=(long long v){
        sign = 1;
        if (v<0) sign =-1, v=-v;
        for(; v>0; v/=base)
            a.push_back(v%base);
    }
    void operator*=(int v){
        if(v<0)  sign =-1, v=-v;
        for(int i=0, carry=0; i< (int)a.size()||carry; ++i)
        {
            if(i == (int)a.size()) 
                a.push_back(0);
            long long cur = a[i]* (long long)v +carry;
            carry = (int) (cur/base);
            a[i] = (int)(cur%base);
        }
    }
    bigint operator*(int v) const{
        bigint res = *this; 
        res*=v;
        return res;
   }

     
    friend ostream& operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1)
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
};

void extraLongFactorials(int n) {
    // Complete this function
    bigint fact = 1; 
    for (int i =1; i<=n; i++)
        fact *=i;
    cout<<fact;
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}

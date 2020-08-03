//*************************************
//
//      大整数类,用于高精度的储存非负整数
//
//
#include<bits/stdc++.h>
using namespace std;
struct BigInteger{
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;

    BigInteger(long long num = 0)   { *this = num; }
    BigInteger operator= (long long num) {
        s.clear();
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator= (const string& str) {
        s.clear();
        int x, len = (str.length() - 1) / WIDTH + 1;
        for(int i = 0; i < len; i++){
            int end = str.length() - i * WIDTH;
            int start = max(0, end - WIDTH);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    BigInteger operator+ (const BigInteger& x) const {
        BigInteger c;
        int t = 0, a;
        c.s.clear();
        for(int i = 0; i < x.s.size(); i++){
            a = this->s[i] + x.s[i];
            c.s.push_back((a % BASE) + t);
            t = a / BASE;
        }
        return c;
    }
    BigInteger operator+= (const BigInteger& x) {
        *this = *this + x;
        return *this;
    }
};

ostream& operator<< (ostream &os, const BigInteger& x) {
    for(int i = x.s.size() - 1; i >= 0; i--){
        os << x.s[i];
    }
    return os;
}

istream& operator>> (istream &is, BigInteger& x) {
    string s;
    if(!(is >> s))  return is;
    x = s;
    return is;
}
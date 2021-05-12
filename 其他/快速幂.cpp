#include<iostream>
#define ll long long
#define mod 1000
using namespace std;
//normal
ll normalpower(ll base, ll power) {
    ll ans = 1;
    while(power--){
        ans = ans * base % mod;
        
    }
    return ans % mod;
}

ll fastpower(ll base, ll power) {
    ll ans = 1;
    while(power){
        if(power & 1)   ans = ans * base % mod;
        power >>= 1;
        base = base * base % mod;
    }
    return ans;
}
int main() {
    ll b, p;
    while(cin >> b >> p && b){
        cout << fastpower(b, p) << endl;
    }
    return 0;
}
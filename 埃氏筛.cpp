/**
 * 例: 用埃氏筛筛选n以内的质数
 */


#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
bool num[1000000000];
ll n;

void esratosthenes(ll n) {
    memset(num, 0, sizeof(num));
    for(int i = 2; i < n; i++){
        if(num[i] == true)  continue;
        for(int j = 2; j * i < n; j++){
            num[j * i] = true;
        }
    }
}
int main() {
    freopen("test.out", "w+", stdout);
    cin >> n;
    esratosthenes(n);
    for(int i = 2; i < n; i++){
        if(!num[i]) cout << ' ' << i;
    }
}

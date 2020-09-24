#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool num[1000000005];
int p[60000000];
ll n;

/**
 * 例: 用埃氏筛筛选n以内的质数
 * 用未被标为false的数(质数)把它的倍数剔除,剩下的就是素数
 * 只需要筛到n^(1/2)就行了
 */

/*



void esratosthenes(ll n) {
    memset(num, 1, sizeof(num));
    for(int i = 2; i <= sqrt(n) + 1; i++){
        if(!num[i])  continue;
        for(int j = 2; j * i <= n; j++){
            num[j * i] = false;
        }
    }
}

*/

/**
 * 欧拉筛(线性筛)
 * 埃氏筛的时间复杂度为O(nloglogn), 其中有些合数会被重复筛出使时间浪费(如12会被2, 3筛出)
 * 利用合数的最小质因数唯一的特性, 对于一个合数, 总是用它的最小质因数筛出它,就能达到O(n)
 */

void linesieve(ll n) {
    memset(num, 1, sizeof(num));
    int c = 0;
    for(int i = 2; i <= n / 2 + 1; i++){
        if(num[i]) p[c++] = i;
        for(int j = 0; j < c; j++){
            if(p[j] * i > n)    break;
            num[i * p[j]] = false;
            if(i % p[j] == 0)   break;
        }
    }
}

int main() {
    //freopen("test.out", "w+", stdout);
    cin >> n;
    //esratosthenes(n);
    linesieve(n);
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(num[i]) cnt++;
    }
    cout << endl << cnt;
}

/**
 * min25筛
 */
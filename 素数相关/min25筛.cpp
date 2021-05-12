/**
 * min25筛求n以内素数的和
 */
/*
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const ll maxn = 1e10;
bool isprime[(int)(1e6) + 1];
ll prime[(int)1e6 + 1];
int cnt = 0;

void linesieve(int n) {
    memset(isprime, 1, sizeof(isprime));
    int i;
    for(i = 2; i <= n / 2 + 1; i++){
        if(isprime[i])  prime[cnt++] = i;
        for(int j = 0; j < cnt; j++){
            if(i * prime[j] > n)    break;
            isprime[i * prime[j]] = false;
            if(i % prime[j] == 0)   break;
        }
    }
    for(i; i <= n; i++){
        if(isprime[i])  prime[cnt++] = i;
    }
}

ll G(const ll n, const ll j) {
    if(j == 0)  return n * (n + 1) / 2 - 1;
    else if(prime[j - 1] * prime[j - 1] > n)    return G(n, j - 1);
    return G(n, j - 1) - prime[j - 1] * (G(n / prime[j - 1], j - 1) - G(prime[j - 1] - 1, j - 1));
}

ll g(const ll n) {
    ll past = 0, pre = G(n, 0);
    for(int i = 1; i <= cnt; i++){
        if(prime[i - 1] * prime[i - 1] > n) break;
        past = pre - prime[i - 1] * (G(n / prime[i - 1], i - 1) - G(prime[i - 1] - 1, i - 1));
        pre = past;
    }
    return past;
}



int main() {
    linesieve(100000);
    ll n;
    cin >> n;
    cout << g(n);
    return 0;
    
}*/


/**
 * 自己写的好慢,抄自 https://my.oschina.net/u/4678692/blog/4645150
 */
#include <math.h>
#include <stdio.h>
#include <assert.h>
#define LINT long long

inline LINT V2IDX(LINT v, LINT N, LINT Ndr, LINT nv) {
    return v >= Ndr ? (N/v - 1) : (nv - v);
}

LINT primesum(LINT N) {
    LINT *S;
    LINT *V;

    LINT r = (LINT)sqrt(N);
    LINT Ndr = N/r;

    assert(r*r <= N and (r+1)*(r+1) > N);

    LINT nv = r + Ndr - 1;

    V = new LINT[nv];
    S = new LINT[nv];

    for (LINT i=0; i<r; i++) {
        V[i] = N/(i+1);
    }
    for (LINT i=r; i<nv; i++) {
        V[i] = V[i-1] - 1;
    }

    for (LINT i=0; i<nv; i++) {
        S[i] = V[i] * (V[i] + 1) / 2 - 1;
    }

    for (LINT p=2; p<=r; p++) {
        if (S[nv-p] > S[nv-p+1]) {
            LINT sp = S[nv-p+1];
            LINT p2 = p*p;
            for (LINT i=0; i<nv; i++) {
                if (V[i] >= p2) {
                    S[i] -= p * (S[V2IDX(V[i]/p, N, Ndr, nv)] - sp);
                } else {
                    break;
                }
            }
        }
    }

    return S[0];
}

int main() {
    LINT N = 1000000000;
    printf("%lld\n", primesum(N));
}
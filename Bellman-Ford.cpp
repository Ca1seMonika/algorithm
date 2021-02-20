#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
const int maxm = (maxn * (maxn - 1)) / 2;
const int INF = 0x3f3f3f3f;
int u[maxm], v[maxm], w[maxm];
int d[maxn];

//朴素实现
void Bellman_Ford1(int n, int m, int x) {
    memset(d, 0x3f3f, sizeof d);
    d[x] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int f = u[j], t = v[j];
            if(d[f] < INF)  d[t] = min(d[t], d[f] + w[j]);
        }
    } 
}
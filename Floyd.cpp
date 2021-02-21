#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100;
int d[maxn][maxn];

void init() {
    memset(d, 0x3f3f, sizeof d);
    for(int i = 0; i < maxn; i++) {
        d[i][i] = 0;
    }
}

void Floyd(int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
//*****************************************
//
//      给定硬币的种类,总金额,输出能组成此金额
//  的硬币数量最大值和最小值
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100 + 5;
const int maxs = 10000 + 5;
const int INF = 0x3f3f3f3f;
int s, n, d[maxs], p[maxs], v[maxn];

int solved(int s) {
    if(d[s] != -1)  return d[s];
    int m = -1;
    for(int i = 0; i < n; i++){
        if(s - v[i] >= 0)   m = max(m, solved(s - v[i]));
    }
    return m == -1 ? -1 : d[s] = m + 1;
}

int solvep(int s) {
    if(p[s] != -1)  return p[s];
    int m = INF;
    for(int i = 0; i < n; i++){
        if(s - v[i] >= 0)   m = min(m, solvep(s - v[i]));
    }
    return m == INF ? INF : p[s] = m + 1; 
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w+", stdout);
    memset(d, -1, sizeof(d));
    memset(p, -1, sizeof(p));
    d[0] = p[0] = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        p[v[i]] = 1;
    }
    solved(s);
    solvep(s);
    cout << d[s] << endl;
    cout << p[s] << endl;
}
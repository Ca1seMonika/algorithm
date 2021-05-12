/*有n种物品, 每种只有一个.第i种物品的体积为Vi, 重量为Wi. 选一些物品装到一个容量为C的背包,要求在总体积不大于C的情况下尽可能多的装物品,输出最大重量. 1 <= n <= 100, 1 <= Vi <= C <= 10000, 1 <= Wi <= 1e6*/
/*#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100 + 5;
int v[maxn], w[maxn], n, p[maxn][10000 + 5], mark[maxn], c;
int dp(int step, int allw) {
    if(step == n + 1)   return 0;
    if(p[step][allw] != -1)   return p[step][allw];
    for(int i = 0; i < n; i++){
        if(mark[i]) continue;
        if(v[i] <= allw){
            mark[i] = 1;
            p[step][allw] = max(p[step][allw], dp(step + 1, allw - v[i]) + w[i]);
            mark[i] = 0;
        }
    }
    if(p[step][allw] == -1)   return 0;
    return p[step][allw];
}
int main() {
    memset(mark, 0, sizeof(mark));
    memset(p, -1, sizeof(p));
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }
    cout << dp(1, c) << endl;
}*/
//递推
#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn = 100 + 5;
int v[maxn], w[maxn], n, mark[maxn], c;
ll p[maxn][10000 + 5];
void dp() {
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= c; j++){
            p[i][j] = (i == 1 ? 0 : p[i - 1][j]);
            if(j >= v[i])   p[i][j] = max(p[i][j], p[i - 1][j - v[i]] + w[i]);
        }
    }
}

int main() {
    memset(p, 0, sizeof(p));
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }
    dp();
    cout << p[n][c] << endl;
}
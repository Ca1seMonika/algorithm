//****************************
//
//  最小生成树,Kruskal算法实现
//
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 20 + 5;
int f1[maxn], f2[maxn], w[maxn], r[maxn], n;
int p[100];//并查集

bool cmp(const int& x, const int& y) {
    return w[x] < w[y];
}

int _find(int x) {
    return p[x] == x ? x : p[x] = _find(p[x]);
}

int kruskal() {
    int ans = 0;
    for(int i = 0; i < n; i++)  r[i] = i;
    for(int i = 0; i < 100; i++)    p[i] = i;
    sort(r, r + n, cmp);
    for(int i = 0; i < n; i++){
        int e = r[i]; int x = _find(f1[e]); int y = _find(f2[e]);
        if(x != y){
            ans += w[e];
            p[x] = y;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> f1[i] >> f2[i] >> w[i];
    }
    cout << kruskal() << endl;
}
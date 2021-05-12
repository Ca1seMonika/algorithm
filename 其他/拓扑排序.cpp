/**
 * 参考问题: Uva10305, 此问题只是简单做了一个无环的拓扑排序
 * 现在加个判环
 */
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 100 + 5;
int n, m, t, G[maxn][maxn], mark[maxn], topo[maxn];

bool dfs(int u) {
    mark[u] = -1;
    for(int i = 1; i <= n; i++) if(G[u][i]) {
        if(mark[i] < 0) return false;
        else if(!mark[i] && !dfs(i))    return false;
    }
    mark[u] = 1;
    topo[t--] = u;
    return true;
}

void TopoOrder() {
    t = n - 1;
    for(int i = 1; i <= n; i++){
        if(!mark[i] && !dfs(i)){
            cout << -1 << endl;
            return;
        }
    }
    cout << topo[0];
    for(int i = 1; i < n; i++){
        cout << " " << topo[i];
    }
    cout << endl;
}

int main() {
    int u, v;
    while(cin >> n >> m && n){
        memset(G, 0, sizeof(G));
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            G[u][v] = 1;
        }
        TopoOrder();
    }
}
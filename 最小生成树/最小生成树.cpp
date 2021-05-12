#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
const int maxm = (maxn - 1) * maxn / 2;
struct Edge {
    Edge() = default;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    int u, v, w;
    bool operator< (const Edge& rhs) const {
        return w < rhs.w;
    }
};
int farr[maxn];
int Find(int i) {
    if(farr[i] < 0) return i;
    farr[i] = Find(farr[i]);
    return farr[i];
}
void Union(int a, int b) {
    farr[a] = b;
}
int main() {
    memset(farr, -1, sizeof farr); 
    Edge edges[maxm];
    vector<Edge> mst;
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    }
    sort(edges, edges + m);
    for(int i = 0; i < m; i++) {
        Edge& e = edges[i];
        int k = Find(e.u), j = Find(e.v);
        if(k != j) {
            mst.push_back(e);
            Union(k, j);
            if(++cnt < n - 1)   break; 
        }
    } 
    for(auto& it: mst) {
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
    return 0;
}

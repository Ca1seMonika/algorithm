// 未优化版本
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100;
int mp[maxn][maxn];
int p[maxn];
int d[maxn];
void dijkstra1(int n) {
    memset(mp, 0, sizeof(mp));
    memset(d, 0x3f3f, sizeof(d));
    bool vis[maxn] = {0};

    d[0] = 0;

    for(int i = 0; i < n; i++) {
        int x, m = INF;
        for(int j = 0; j < n; j++)  if(!vis[j] && d[j] < m) m = d[x = j]; 
        vis[x] = 1;
        for(int j = 0; j < n; j++)  if(d[j] > d[x] + mp[x][j]) {
            d[j] = d[x] + mp[x][j];
            p[j] = x;
        }
    } 
}


// 优先队列优化版本
struct Side {
    int form, to, dist;
    Side(int from, int to, int dist): form(from), to(to), dist(dist) {}
};

struct Dijkstra {
    int n;
    vector<Side> sides;
    vector<int> G[maxn];
    int d[maxn];
    int p[maxn];
    bool vis[maxn];
    typedef pair<int, int> pii;

    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        sides.clear();
        memset(this->d, 0x3f3f, sizeof(this->d));
        memset(this->vis, 0, sizeof(this->vis));
    }

    void addSide(int from, int to, int dist) {
        G[from].push_back(sides.size());
        sides.push_back(Side(from, to, dist));
    }

    void dijkstra(int x) {
        d[x] = 0;
        
        priority_queue<pii, vector<pii>, greater<pii>> Q;
        Q.push(make_pair(0, x));
        while(!Q.empty()) {
            pii t = Q.top(); Q.pop();
            if(vis[t.second])   continue;
            vis[t.second] = 1;
            for(int i = 0; i < G[t.second].size(); i++) {
                auto& it = sides[G[t.second][i]];
                if(d[it.to] > d[t.second] + it.dist) {
                    d[it.to] = d[t.second] + it.dist;
                    p[it.to] = G[t.second][i];
                    Q.push(make_pair(d[it.to], it.to));
                }
            } 
        }
    }
};

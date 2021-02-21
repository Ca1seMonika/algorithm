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


//队列实现
struct Edge {
    int from, to, dist;
    Edge(int from, int to, int dist): from(from), to(to), dist(dist) {}
};
struct BellmanFord {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxm];
    int path[maxn];
    int d[maxn];
    int cnt[maxn];

    void init(int n) {
        this->n = n;
        edges.clear();
        for(int i = 0; i < n; i++)  G[i].clear();
        memset(inq, 0, sizeof inq);
        memset(d, 0x3f3f, sizeof d);
        memset(cnt, 0, sizeof cnt);
    }

    void add_edge(int from, int to, int dist) {
        G[from].push_back(edges.size());
        edges.push_back(Edge(from, to, dist));
    }

    bool Bellman_Ford(int s) {
        queue<int> q;
        d[s] = 0;

        q.push(s);
        while(!q.empty()) {
            int t = q.front(); q.pop();
            inq[t] = 0;
            for(int i = 0; i < G[t].size(); i++) {
                Edge& it = edges[G[t][i]];
                if(d[t] < INF && d[it.to] > d[t] + it.dist) {
                    d[it.to] = d[t] + it.dist;
                    path[it.to] = t;
                    if(!inq[it.to]) {
                        q.push(it.to);
                        inq[it.to] = true;
                        if(++cnt[it.to] > n)    return false;
                    }
                }
            }
        }
        return true;
    }
};
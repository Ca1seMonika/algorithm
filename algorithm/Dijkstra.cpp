//***************************************
//                                      
//  Dijkstra算法的优化,时间复杂度mlogn     
//                                      

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<functional>
#include<queue>
using namespace std;

const int maxn = 20;
const int INF = 0x3f3f3f3f;

struct Edge {
    int from, to, dis;
    Edge(int u, int v, int w) : from(u), to(v), dis(w) {}
};

struct HeapNode {
    int d, i;
    HeapNode(int a, int b) : d(a), i(b) {}
    bool operator < (const HeapNode& rhs) const {
        return d > rhs.d;
    }
};

struct Dijkstra {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];//储存从某点出发的边的编号
    bool done[maxn];    //是否已永久标号
    int d[maxn];        //s 到各个点的距离
    int p[maxn];        //最短路中的上一条弧

    void init(int n) {
        this->n = n;
        for(int i = 0; i < n; i++)  G[i].clear();
        edges.clear();
    }

    void addedge(int from, int to, int dis) {
        edges.push_back(Edge(from, to, dis));
        m = edges.size();
        G[from].push_back(m - 1);
    }
    /*  
    void dijkstra(int s) {
        memset(done, 0, sizeof(done));
        memset(d, 0x3f, sizeof(d));
        d[s] = 0;
        for(int i = 0; i < n; i++){
            int x, m = INF;
            for(int j = 0; j < n; j++)  if(!done[j] && d[j] <= m)   m = d[x = j];
            done[x] = 1;
            for(int j = 0; j < G[x].size(); j++){
                Edge e = edges[G[x][j]];
                if(d[e.to] > d[x] + e.dis){
                    d[e.to] = d[x] + e.dis;
                    p[e.to] = G[x][j];
                }
            }
        }
    }
    */
    //队列优化
    void dijkstra(int s) {
        memset(done, 0, sizeof(done));
        memset(d, 0x3f, sizeof(d));
        d[s] = 0;
        priority_queue<HeapNode> Q;
        Q.push(HeapNode(d[s], s));
        while(!Q.empty()){
            HeapNode t = Q.top();   Q.pop();
            int x = t.i;
            if(done[x]) continue;
            done[x] = true;
            for(int i = 0; i < G[x].size(); i++){
                Edge& e = edges[G[x][i]];
                if(d[e.to] > d[x] + e.dis){
                    d[e.to] = d[x] + e.dis;
                    p[e.to] = G[x][i];
                    Q.push(HeapNode(d[e.to], e.to));
                }
            }
        }
    }
};

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w+", stdout);
    Dijkstra* dij = new Dijkstra;
    int n, s, f, t, d, a;
    cin >> n >> s >> a;
    dij->init(n);
    while(cin >> f >> t >> d){
        dij->addedge(f, t, d);
        dij->addedge(t, f, d);
    }
    dij->dijkstra(s);
    cout << dij->d[a] << endl;
}
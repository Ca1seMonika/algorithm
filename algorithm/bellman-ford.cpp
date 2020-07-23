//***************************************
//                                      
//  Bellman-ford的队列优化    
//                                      

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int maxn = 20;
const int INF = 0x3f3f3f3f;

struct Edge {
    int from, to, dis;
    Edge(int u, int v, int w) : from(u), to(v), dis(w) {}
};

struct BellmanFord {
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];    //储存从某点出发的边的编号
    bool inq[maxn];         //是否已永久标号
    int d[maxn];            //s 到各个点的距离
    int p[maxn];            //最短路中的上一条弧
    int cnt[maxn];       

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
    //队列优化
    bool bellmanford(int s) {
        queue<int> Q;
        memset(d, 0x3f, sizeof(d));
        memset(cnt, 0, sizeof(cnt));
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = true;
        Q.push(s);
        while(!Q.empty()){
            int t = Q.front();  Q.pop();
            inq[t] = false;
            for(int i = 0; i < G[t].size(); i++){
                Edge& e = edges[G[t][i]];
                if(d[e.to] > d[t] + e.dis){
                    d[e.to] = d[t] + e.dis;
                    p[e.to] = G[t][i];
                    if(!inq[e.to]){
                        Q.push(e.to);
                        inq[e.to] = true;
                        if(++cnt[e.to] > n) return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w+", stdout);
    BellmanFord* sp = new BellmanFord;
    int n, s, f, t, d, a;
    cin >> n >> s >> a;
    sp->init(n);
    while(cin >> f >> t >> d){
        sp->addedge(f, t, d);
    }
    bool judge = sp->bellmanford(s);
    if(judge){
        cout << sp->d[a] << endl;
    }else{
        cout << "负环" << endl;
    }
}
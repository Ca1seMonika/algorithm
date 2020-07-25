//*********************************************
//  
//    输入若干个矩形,用a, b表示矩形如a > b, c > d 或      
//  a > d, c > b则两个矩形可嵌套,输出最多个能嵌套的矩形
//  的个数
//
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 20 + 5;
vector<pair<int, int>> rectangle;
vector<int> G[maxn];
int d[maxn];
int solve(int i) {
    if(d[i] != -1)  return d[i];
    int m = 0;
    for(int j = 0; j < G[i].size(); j++){
        m = max(m, solve(G[i][j]));
    }
    return d[i] = m + 1;
}
int main()  {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w+", stdout);
    memset(d, -1, sizeof(d));
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        for(int j = 0; j < rectangle.size(); j++){
            if((rectangle[j].first < a && rectangle[j].second < b) || (rectangle[j].first < b && rectangle[j].second < a)){
                G[j].push_back(rectangle.size());
            }else if((rectangle[j].first > a && rectangle[j].second > b) || (rectangle[j].first > b && rectangle[j].second > a)){
                G[rectangle.size()].push_back(j);
            }
        }
        rectangle.push_back(make_pair(a, b));
    }
    int m = 0;
    for(int i = 0; i < n; i++){
        m = max(m, solve(i));
    }
    cout << m << endl;
}
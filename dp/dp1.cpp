//*********************************************
//        动态规划1
//           1
//         3   2
//       4  10   1
//     4   3   2   20
//  给定一个数字三角形,求出从顶到底数字和最大的路径的和
//
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 20 + 5;
int n, num[maxn][maxn], sum[maxn][maxn];
/*  递推
int main()  {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w+", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i; j++){
            cin >> num[i][j];
        }
    }
    for(int i = 1; i <= n; i++) sum[n][i] = num[n][i];
    for(int i = n - 1; i > 0; i--){
        for(int j = 1; j <= i; j++){
            sum[i][j] = num[i][j] + max(sum[i + 1][j], sum[i + 1][j + 1]);
        }
    }
    cout << sum[1][1] << endl;
}*/

//  记忆化搜索
int dp(int i, int j) {
    if(i == n + 1)  return 0;
    else if(sum[i][j] != -1) return sum[i][j];
    return sum[i][j] = num[i][j] + max(dp(i + 1, j), dp(i + 1, j + 1));
}
int main()  {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w+", stdout);
    cin >> n;
    memset(sum, -1, sizeof(sum));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i; j++){
            cin >> num[i][j];
        }
    }
    cout << dp(1, 1) << endl;
}
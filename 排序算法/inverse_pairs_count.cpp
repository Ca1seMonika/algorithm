#include<bits/stdc++.h>
using namespace std;
int mergeSortCount(int *vec, int s, int t, int *T) {
    int cnt = 0;
    if(t - s > 1) {
        int i = s, r = s;
        int m = (s + t) / 2, j = m;
        cnt += mergeSortCount(vec, s, m, T);
        cnt += mergeSortCount(vec, m, t, T);
        while(i < m || j < t) {
            if(j >= t || (i < m && vec[i] <= vec[j]))
                T[r++] = vec[i++];
            else {
                if(i < m)   cnt += m - i;
                T[r++] = vec[j++];
            }
        }
        for(i = s; i < t; i++)  vec[i] = T[i];
    }
    return cnt;
}
int main() {
    int arr[10] = {2, 5, 3, 4, 2, 7, 6, 8, 10, 8};
    int T[10];
    cout << mergeSortCount(arr, 0, 10, T) << endl;
    return 0;
}
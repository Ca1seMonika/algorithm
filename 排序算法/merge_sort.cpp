#include<bits/stdc++.h>
using namespace std;
void merge_sort(int *vec, int s, int t, int *T) {
    if(t - s > 1) {
        int m = (s + t) / 2;
        int i = s, j = m, r = s;
        merge_sort(vec, s, m, T);
        merge_sort(vec, m, t, T);
        while(i < m || j < t) {
            if(j >= t || (i < m && vec[i] <= vec[j]))
                T[r++] = vec[i++];
            else
                T[r++] = vec[j++];
        }
        for(i = s; i < t; i++)  vec[i] = T[i];
    }
}
int main() {
    int arr[10] = {2, 5, 3, 4, 2, 7, 6, 8, 10, 8};
    int T[10];
    merge_sort(arr, 0, 10, T);
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
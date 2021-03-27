#include<bits/stdc++.h>
using namespace std;
void quick_sort(int *vec, int s, int t) {
    if(t - s > 1) {
        int tmp = vec[s];
        int i = s, j = t - 1;
        while(i < j) {
            while(i < j && vec[j] >= tmp)   j--;
            vec[i] = vec[j];
            while(i < j && vec[i] < tmp)    i++;
            vec[j] = vec[i]; 
        }
        vec[i] = tmp;
        quick_sort(vec, s, i);
        quick_sort(vec, i + 1, t);
    }
}
int main() {
    int arr[10] = {2, 5, 3, 4, 2, 7, 6, 8, 10, 8};
    quick_sort(arr, 0, 10);
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
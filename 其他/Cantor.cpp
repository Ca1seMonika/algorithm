#include<iostream>
#include<vector>
using namespace std;
const int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cantor(int* arr, int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        int small = 0;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) small++;
        }
        res += small * FAC[n - i - 1];
    }
    return res;
}

vector<int> decantor(int cantor, int n) {
    vector<int> rest;
    for(int i = 1; i <= n; i++) {
        rest.push_back(i);
    }

    vector<int> res;
    int d, r;
    for(int i = n - 1; i >= 0; i--) {
        d = cantor / FAC[i];
        cantor = cantor % FAC[i];
        res.push_back(rest[d]);
        rest.erase(rest.begin() + d);
    }
    return res;
}

int main() {
    int arr[] = {3, 4, 1, 5, 2};
    cout << cantor(arr, 5) << endl;
    
    auto res = decantor(61, 5);
    for(auto it: res) {
        cout << it << ' ';
    }
    cout << endl;
    return 0;
}
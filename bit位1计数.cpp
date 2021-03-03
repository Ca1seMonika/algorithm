#include<bits/stdc++.h>
using namespace std;
int bitCount(int num) {
    int ans = 0;
    while(num) {
        num &= num - 1;
        ans++;
    }
    return ans;
}
int main() {
    cout << bitCount(3) << endl;
}
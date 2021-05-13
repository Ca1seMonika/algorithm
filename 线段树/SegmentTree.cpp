#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;

//每个点的值
int a[maxn];

class SegmentTree {
private:
    int* d;
    int* lazy;

    void build(int s, int t, int p) {
        if(s == t) {
            d[p] = a[s];
            return;
        } 

        int m = (s + t) >> 1;
        build(s, m, 2 * p);
        build(m + 1, t, 2 * p + 1);
        d[p] = d[2 * p] + d[2 * p + 1]; 
    }

    void checkLazy(int s, int t, int m, int p) {
        if(lazy[p] && s != t) {
            d[2 * p] += (m - s + 1) * lazy[p];
            d[2 * p + 1] += (t - m) * lazy[p];
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
            lazy[p] = 0;
        }
    }

public:
    SegmentTree(int n): d(new int[n << 2]), lazy(new int[n << 2]) {
        build(0, n - 1, 1);
    }
    ~SegmentTree() {
        if(d != nullptr) {
            delete[] d;
            delete[] lazy;
            d = nullptr;
            lazy = nullptr;
        }
    }

    int getSum(int l, int r, int s, int t, int p) {
        if(l <= s && t <= r)
            return d[p];
        int m = (s + t) >> 1, sum = 0;
        checkLazy(s, t, m, p);
        if(l <= m)  sum += getSum(l, r, s, m, 2 * p);
        if(r > m)   sum += getSum(l, r, m + 1, t, 2 * p + 1);
        return sum;
    }

    void update(int l, int r, int v, int s, int t, int p) {
        if(l <= s && t <= r) {
            d[p] += (t - s + 1) * v;
            lazy[p] = v;
            return;
        }
        int m = (s + t) >> 1;
        checkLazy(s, t, m, p); 
        if(l <= m)    update(l, r, v, s, m, 2 * p);
        if(r > m)   update(l, r, v, m + 1, t, 2 * p + 1);
        d[p] = d[2 * p] + d[2 * p + 1];
    }

};

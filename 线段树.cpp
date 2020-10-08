/**
 * 学习自博客https://blog.csdn.net/qq_39826163/article/details/81436440
 */

#include<iostream>
using namespace std;

const int maxn = 1000 + 5;
struct Node {
    int l, r, w, lazy;
}tree[maxn >> 2];
int ans, x, a, y, add;
//建树
void build(int l, int r, int k) {
    tree[k].l = l; tree[k].r = r;
    if(l == r){
        cin >> tree[k].w;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, k * 2);
    build(m + 1, r, k * 2 + 1);
    tree[k].w = tree[2 * k].w + tree[2 * k + 1].w;
}

//单点查询x是查询点, ans为查询答案
void ask(int k) {
    if(tree[k].l == tree[k].r){
        ans = tree[k].w;
        return;
    }
    int m = (tree[k].l + tree[k].r) / 2;
    if(x <= m)  ask(k * 2);
    else    ask(k * 2 + 1);
}

//单点修改 a 为节点修改后的值
void change(int k) {
    if(tree[k].l == tree[k].r){
        tree[k].w = a;
        return;
    }
    int m = (tree[k].l + tree[k].r) / 2;
    if(x <= m)  change(k * 2);
    else    change(k * 2 + 1);
    tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}

//区间查询 x, y 为查询左右端点,ans为查询答案
void uniask(int k) {
    if(tree[k].l >= x && tree[k].r <= y){
        ans += tree[k].w;
        return;
    }
    int m = (tree[k].r + tree[k].l) / 2;
    if(x <= m)    uniask(k * 2);
    if(y > m) uniask(k * 2 + 1);
}

//区间修改 x, y 为修改左右端点, 懒标记, add为加值

void down(int k) {
    tree[k * 2].lazy += tree[k].lazy;
    tree[k * 2 + 1].lazy += tree[k].lazy;
    tree[k * 2].w += (tree[k * 2].r - tree[k * 2 + 1].l + 1) * tree[k].lazy;
    tree[k * 2 + 1].w += (tree[k * 2 + 1].r - tree[k * 2 + 1].l) * tree[k].lazy;
    tree[k].lazy = 0;
}

void unichange(int k) {
    if(tree[k].l >= x && tree[k].r <= y){
        tree[k].w += add * (tree[k].r - tree[k].l + 1);
        tree[k].lazy += add;
        return;
    }
    if(tree[k].lazy)    down(k);
    int m = (tree[k].l + tree[k].r) / 2;
    if(x <= m)  unichange(k * 2);
    if(m < y)   unichange(k * 2 + 1);
    tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}


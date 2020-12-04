//kmp字符串匹配算法
//https://www.zhihu.com/question/21923021
//非常好的一个讲解

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;

void getNext(char* p, int* next) {
    int i = 0, j = -1;
    next[0] = -1;

    while(i < strlen(p)){
        if(j == -1 || p[i] == p[j]){
            i++,j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

int KMP(char* t, char* p, int* next) {
    int i = 0, j = 0;

    while(i < (int)strlen(t) && j < (int)strlen(p)){
        if(j == -1 || t[i] == p[j]){
            i++,j++;
        }else{
            j = next[j];
        }
    }

    if(j == strlen(p)){
        return i - j;
    }else{
        return -1;
    }
}

int main() {
    int* next = new int[maxn]();
    char* tar = new char[maxn]();
    char* mod = new char[100]();

    cin >> tar >> mod;
    
    getNext(mod, next);
    cout << KMP(tar, mod, next) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct LazySegTree{
    int n, h=0;
    vector<int> e,l;
    void apply(int i, int val){
        e[i]+=val;
        if(i<n)l[i]+=val;
    }
    void build(int i){
        while(i>1)i>>=1, e[i]=e[p<<1]+e[p<<1|1];
    }
    void push(int i){
        for(int s=h; s>0; s--){
            int j = i>>s;
            if(d[j]!=0){
                apply(j<<1,d[i]);
            }
        }
    }
    LazySegTree(vector<int>&& a):n(a.size()),e(2*n){
        for(int i=n; i<2*n; i++)e[i]=a[i-n];
        for(int i=n-1; i>=1; i--)e[i]=e[i*2]+e[i*2+1];
        int t = a.size();
        while(t>>=1)h++;
    }

}
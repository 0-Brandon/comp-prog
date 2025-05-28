#include <bits/stdc++.h>

using namespace std;

struct Segtree{
    int n;
    vector<int> e,lazy;
    int h;
    Segtree(int n):n(n), e(2*n), lazy(n), h(sizeof(int)*8-__builtin_clz(n)){};
    void apply(int i, int v){
        e[i]+=v;
        if(i<n)lazy[i]+=v;
    }
    void build(int i){
        while(i>1)i>>=1,e[i]=max(e[i<<1],e[i<<1|1])+lazy[i];
    }
    void push(int i){
        for(int s = h; s>0; s--){
            int j = i>>s;
            if(lazy[j]!=0){
                apply(j<<1,lazy[j]);
                apply(j<<1|1,lazy[j]);
                lazy[j]=0;
            }
        }
    }
    void update(int l, int r, int val){
        l+=n,r+=n+1;
        int l0 = l;
        int r0 = r;
        for(;l<r; l>>=1,r>>=1){
            if(l&1)apply(l++,val);
            if(r&1)apply(--r,val);
        }
        build(l0);
        build(r0-1);
    }
    int query(int l, int r){
        l+=n,r+=n;
        push(l);
        push(r-1);
        int ans = e[r];
        for(;l<r; l/=2,r/=2){
            if(l&1)ans = max(ans,e[l++]);
            if(r&1)ans = max(ans,e[--r]);
        }
        return ans;
    }
};
int main(){
    int n, k;
    cin>>n>>k;
    Segtree seg(n);
    vector<int> x(n);
    vector<int> prev(n);
    vector<int> id(n+1,0);
    set<int> cur;
    for(int i=0; i<n; i++){
        cin>>x[i];
        prev[i] = id[x[i]];
        id[x[i]]=i;
        cur.insert(x[i]);
        seg.update(i,i,cur.size());
    }
    for(int j=2; j<=k; j++){
        Segtree ns(n);
        for(int i=0; i<n; i++){
            seg.update(prev[i],i-1,1);
            ns.update(i,i,seg.query(0,i)); 
        }
        swap(ns,seg);
    }
    cout<<seg.query(n-1,n-1)<<"\n";
}
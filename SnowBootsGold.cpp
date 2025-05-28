#include <bits/stdc++.h>

using namespace std;
struct Query{
    int s, d, id;
    Query(int i, int j, int k):s(i),d(j),id(k){}
    bool operator<(Query i){
        return s<i.s;
    }
};
struct Segtree{
    int n;
    vector<int> m, l, r;
    Segtree(int a):n(a),m(4*n,0),l(4*n,0),r(4*n,0){
        for(int i=0; i<n; i++){
            upd(0,0,n-1,i,1);
        }
    }
    void upd(int i, int dl, int dh, int idx, int val = 0){
        if(dl==dh&&dl==idx){m[i]=l[i]=r[i]=val;return;}
        if(dl>idx||dh<idx)return;
        int mid = (dl+dh)/2;
        int ni = i*2+1, j = i*2+2;
        upd(ni, dl, mid, idx,val);
        upd(j, mid+1, dh, idx,val);
        m[i] = max({m[ni], m[j], r[ni]+l[j]});
        l[i] = l[ni]==(mid-dl+1) ? l[ni]+l[j] : l[ni];
        r[i] = r[j]==dh-(mid+1)+1 ? r[j]+r[ni] : r[j];
    }
    int query(){
        return m[0];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    int n, b;
    cin>>n>>b;
    vector<int> x(n);
    map<int,vector<int>> occ;
    for(int i=0; i<n; i++){
        cin>>x[i];
        occ[x[i]].push_back(i);
    }
    sort(x.begin(),x.end());
    vector<Query> q;
    for(int i=0; i<b; i++){
        int a, b;
        cin>>a>>b;
        q.emplace_back(a,b,i);
    }
    int p = 0;
    vector<bool> ans(b, false);
    sort(q.begin(),q.end());
    Segtree seg(n);
    for(auto i:q){
        while(p<n&&x[p]<=i.s){
            for(auto& o:occ[x[p]]){
                seg.upd(0,0,n-1,o);
            }
            p++;
        }
        if(seg.query()<i.d)ans[i.id]=true;
    }
    for(int i=0; i<b; i++)cout<<ans[i]<<"\n";
}
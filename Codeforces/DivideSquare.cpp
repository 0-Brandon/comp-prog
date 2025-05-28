#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree{
    int n;
    vector<int> e;
    SegTree(int n):n(n),e(2*n,0){}
    void update(int i, int inc){
        for(e[i+=n]+=inc; i>>=1;){
            e[i] = e[i*2]+e[i*2|1];
        }
    }
    int query(int l, int r){
        int ans = e[r+=n];
        for(l+=n;l<r;r/=2,l/=2){
            if(l&1)ans+=e[l++];
            if(r&1)ans+=e[--r];
        }
        return ans;
    }
};
signed main(){
    int N = 1e6+10;
    int n, m;
    cin>>n>>m;
    vector<vector<int>> start(N),end(N);
    vector<pair<int,int>> query(N,{-1,-1});
    int lol=0;
    for(int i=0; i<n; i++){
        int y, l, r;
        cin>>y>>l>>r;
        start[l].push_back(y);
        end[r].push_back(y);
        if(l==0&&r==1e6)lol++;
    }
    for(int i=0; i<m; i++){
        int x, l, r;
        cin>>x>>l>>r;
        query[x] = {l,r};
        if(l==0&&r==1e6)lol++;
    }
    int ans = 0;
    SegTree seg(N+10);
    for(int i=0; i<=N; i++){
        if(start[i].size())for(auto& j:start[i]){
            seg.update(j,1);
        }
        if(query[i].first!=-1){
            ans+=seg.query(query[i].first,query[i].second);
        }
        if(end[i].size())for(auto& j:end[i]){
            seg.update(j,-1);
        }
    }
    cout<<1+ans+lol<<"\n";
}
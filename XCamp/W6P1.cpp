#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, x, y;
    cin>>n>>x>>y;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int ans = 0;
    if(x>=y){
        ans = n-1; for(int i=0; i<n; i++)if(adj[i].size()==n-1)ans=n-2;
    }
    else{
        //x<y, maximise x
        auto dfs = [&](auto dfs, int i, int p)->int {
            int cnt = 0;
            for(auto& c:adj[i]){
                if(c!=p)cnt+=dfs(dfs,c,i);
            }
            if(cnt>=2){ans+=cnt-1;return 0;}
            return 1;
        };
        ans+=dfs(dfs,0,0);ans--;
    }
    cout<<(n-1-ans)*x+ans*y;
}


//we make a bunch of chains going up
//if we have more than two children, we connect two of the chains. now, we have numchildren-1 contained chains
//in order to access each chain, we need one outside edge
//we use ans-- at the end, because we can start at one chain
//however, we never check if the chain going up to root gets counted as a chain
//it is only counted if we use it to join two chains. otherwise, if it is uncapped, we never mention that we need one suboptimal edge to get to this chain
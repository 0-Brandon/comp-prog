#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    vector<int> vis(n);
    auto dfs = [&](auto&& dfs, int i, int g)->void {
        if(g){
            vector<int> mark;
            vis[i]=1;
            for(auto& c:adj[i]){
                if(!vis[c]){
                    vis[c] = -1;
                    mark.push_back(c);
                }
            }
            for(auto& c:mark)dfs(dfs,c,0);
        }else{
            for(auto& c:adj[i]){
                if(!vis[c]){
                    dfs(dfs, c,1);
                }
            }
        }
    };
    dfs(dfs, 0,1);
    for(int i=0; i<n; i++){
        if(vis[i]==0){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
    int ans = 0;
    for(int i=0; i<n; i++){
        if(vis[i]==1)ans++;
    }
    cout<<ans<<"\n";
    for(int i=0; i<n; i++){
        if(vis[i]==1)cout<<i+1<<" ";
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
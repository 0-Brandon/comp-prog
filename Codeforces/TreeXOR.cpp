#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++)cin>>x[i];
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> sub(n);
    int ans = 0;
    vector<int> change(n,0);
    auto dfs = [&](auto dfs, int i, int p) -> void {
        sub[i] = 1;
        for(auto& c:adj[i])if(c!=p){
            dfs(dfs,c,i);
            sub[i]+=sub[c];
            ans+=sub[c]*(x[c]^x[i]);
            change[c] = (n - sub[c]*2)*(x[i]^x[c]);
        }
    };
    dfs(dfs,0,0);
    auto dfs2 = [&](auto dfs2, int i, int p) -> void {
        for(auto& c:adj[i])if(c!=p){
            change[c]+=change[i];
            dfs2(dfs2,c,i);
        }
    };
    dfs2(dfs2,0,0);
    for(int i=0; i<n; i++)cout<<ans+change[i]<<" ";
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
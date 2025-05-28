#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 1;
    auto dfs = [&](auto dfs, int i, int p) -> int {
        int cu = 1;
        for(auto& c:adj[i])if(c!=p){
            cu=cu*(dfs(dfs,c,i)+1)%mod;
        }
        ans = (ans+cu)%mod;
        return cu;
    };
    dfs(dfs,0,0);
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
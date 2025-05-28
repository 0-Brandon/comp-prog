#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> val(n,0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k;cin>>k;
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        val[a] ^= 1<<i;
        val[b]^= 1<<i;
    }
    set<int> ss;
    auto dfs = [&](auto dfs, int i, int p)-> int {
        int cur = val[i];
        for(auto& c:adj[i]){
            if(c!=p){
                cur^=dfs(dfs,c,i);
            }
        }
        ss.insert(cur);
        return cur;
    };
    dfs(dfs,0,0);
    vector<int> s;
    for(auto& i:ss)s.push_back(i);
    vector<int> dp(1<<k,k+1);
    dp[0]=0;
    for(int i=0; i<1<<k; i++){
        for(auto& j:s){
            dp[i|j] = min(dp[i|j],dp[i]+1);
        }
    }
    cout<<dp[(1<<k)-1]<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
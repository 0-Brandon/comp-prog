#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
signed main(){
    int n, k;cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;
        a--,b--;adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n, vector<int>(k+2));
    //dp[i][j] is number of ways to cut subtree of i so max depth going to i is less than or equal to k
    auto dfs = [&](auto&& dfs, int cur, int p)->int {
        dp[cur][0]=1;
        int d = 0;
        for(auto& c:adj[cur]){
            if(c==p)continue;
            vector<int> ndp(k+1);
            int nd = dfs(dfs,c,cur);
            for(int i=0; i<=min(k,d); i++){
                for(int j=0; j<=min(k,nd); j++){
                    if(i+j+1<=k){
                        ndp[max(i,j+1)] =(ndp[max(i,j+1)] +0LL+ dp[cur][i]*1LL*dp[c][j]%mod)%mod;
                    }
                    if(i<=k&&j<=k){
                        ndp[i] = (ndp[i]+0LL+ dp[cur][i]*1LL*dp[c][j]%mod)%mod;
                    }
                }
            }
            swap(dp[cur],ndp);
            d = max(d,nd+1);
        }
        return d;
    };
    dfs(dfs,0,0);
    int ans = 0;
    for(auto& i:dp[0])ans = (ans+0LL+i)%mod;
    cout<<ans<<"\n";
}
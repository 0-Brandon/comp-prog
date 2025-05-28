#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
    for(int i=0; i<m; i++){
        int a, b,c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a][b] = adj[b][a] = min(adj[b][a],c);
    }
    //dp[i][j][mask] distance from start to j is i, non connected set is mask
    //iterate over submask smask
    //iterate over connecting node k
    //dp[i][j][mask] = dist(j,k)+dp[i+1][k][smask^1<<k] +dp[i][j][mask^smask]
    int dp[n][n][1<<n];
    for(int i=0; i<n; i++)for(int j=0; j<n; j++)for(int k=0; k<1<<n; k++) dp[i][j][k] = INT_MAX;
    for(int i=0; i<n; i++)dp[n-1][i][0] = 0;
    for(int i = n-2; i>=0; i--){
        for(int j=0; j<n; j++){
            dp[i][j][0]=0;
            for(int mask = 1; mask<(1<<n); mask++){
                if(((mask>>j)&1)||__builtin_popcount(mask)>n-i-1)continue;
                for(int smask = mask; smask;smask=(smask-1)&mask){
                    if(dp[i][j][mask^smask]>=dp[i][j][mask])continue;
                    int t = smask;
                    for(int k = __builtin_ctz(t);t;k = __builtin_ctz(t^=(1<<k))){
                        if(adj[j][k]==INT_MAX)continue;
                        dp[i][j][mask] = min(dp[i][j][mask],adj[j][k]*(i+1)+dp[i+1][k][smask^(1<<k)]+dp[i][j][mask^smask]);
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++)ans = min(ans,dp[0][i][((1<<n)-1)^(1<<i)]);
    cout<<ans<<"\n";
}
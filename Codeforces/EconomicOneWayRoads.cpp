#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 1e15;
signed main(){
    int n;
    cin>>n;
    vector g(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>g[i][j];
        }
    }
    int ad = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(g[i][j]!=-1){
                int t = min(g[i][j],g[j][i]);
                g[i][j]-=t;
                g[j][i]-=t;
                ad+=t;
            }
            else g[i][j] = g[j][i] = inf;
        }
    }
    vector<int> dp(1<<n,inf);
    dp[1] = 0;//start node
    vector dp2(1<<n, vector(n,vector<int>(n,inf)));
    for(int mask=1; mask<1<<n; mask+=2){//no point iterating over masks not including start
        vector<int> in,out;
        for(int i=0; i<n; i++)if(1&(mask>>i))in.push_back(i);else out.push_back(i);
        for(auto& j:in) for(auto& i:in) dp[mask] = min(dp[mask], dp2[mask][i][j]+g[i][j]); //connect this cycle
        for(auto& i:in)for(auto& j:in){
            if(dp[mask]!=inf)if(i!=j)dp2[mask][i][j] = min(dp2[mask][i][j], dp[mask]); //this one is set 
            for(auto& k:out) dp2[mask|1<<k][k][j] = min(dp2[mask|1<<k][k][j],dp2[mask][i][j]+g[i][k]); //extend this by one
        }
        if(dp[mask]!=inf)for(auto& i:in) for(auto& j:out) for(auto& k:out) if(j!=k) dp2[mask|1<<j|1<<k][j][k] = min(dp2[mask|1<<j|1<<k][j][k],dp[mask]+g[i][j]+g[k][i]);//starting a cycle requires at least 2 other nodes
    }
    if(dp[(1<<n)-1]+ad>=inf)cout<<"-1\n";
    else cout<<ad+dp[(1<<n)-1]<<"\n";
}
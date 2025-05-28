#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
    int n, m, c;
    cin>>n>>m>>c;
    vector<vector<int>> adj(n);
    vector<int> cost(n);
    for(int i=0; i<n; i++){
        cin>>cost[i];
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
    }
    int ans = 0;
    vector<vector<int>> dp(n, vector<int> (1001, -10000));
    dp[0][0]=0;
    for(int i=0; i<1000; i++){
        for(int j=0; j<n; j++){ 
            for(auto& child:adj[j]){
                dp[child][i+1]=max(dp[child][i+1], dp[j][i]+cost[child]);
            }
        }
    }
    for(int i=0; i<1001; i++){
        ans = max(ans,dp[0][i]-c*i*i);
    }
    cout<<ans<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, ma, red, blue;
    cin>>n>>ma>>red>>blue;
    vector<vector<int>> m(2,vector<int>(n));
    vector<vector<int>> mp(2,vector<int>(n));
    vector<vector<array<int,3>>> adj(n);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(red+1, vector<int>(blue+1,INT_MAX)));
    for(int i=0; i<ma; i++){
        int u, v, x, c;
        cin>>u>>v>>x>>c;u--,v--,c--;
        adj[u].push_back({v,x,c});
        adj[v].push_back({u,x,c});
        if(c>=0)m[c][u] = min(m[c][u], x);
        if(c>=0)m[c][v] = min(m[c][v],x);
    }
    int start, dest;cin>>start>>dest;
    dp[0][0][0]=0;
    vector<bool> visited(n);
    //dp[i][j][k], minimum length path starting from s that pass through j red and k blue
    auto dfs = [&](auto& dfs, int i)->void {
        visited[i]=true;
        cout<<i<<" ";
        for(int r=0; r<red; r++){
            for(int b=0; b<blue; b++){
               for(auto& [c,d,col]:adj[i]){
                if(col==-1)dp[c][r][b] = min(dp[c][r][b], dp[i][r][b]+d);
                else if (col^1+r<=red && col^0+b<=blue)dp[c][r+col^1][b+col^0] = min(dp[c][r+col^1][b+col^0], dp[i][r][b]+d);
               }
            }
        }
        for(auto& c:adj[i]){
            if(visited[c[0]])continue;
            dfs(dfs,c[0]);
        }
    };
    dfs(dfs,0);
    cout<<"a";
    visited.assign(n,0);
    //now, dp[i][j][k] has all non redundant paths, 
    //we consider paths lengthening paths that are too short
    //m[i][j] is minimum red edge connected to path from i to j
    auto dfs2 = [&](auto dfs2, int i)->void {
        for(auto& [c,d,col]:adj[i]){
            if(visited[c])continue;
            mp[col][c] = min(mp[col][i],m[col][c]);
            //min color from s to c is min from s to i plus min c
            dfs2(dfs2,c);
        }
    };
    dfs2(dfs2,start);
    //iterate on same parity
    int ans = 0;
    for(int i=red&1; i<red; i+=2){
        for(int j=blue&1; j<blue; j+=2){
            ans = min(ans,dp[dest][i][j]+mp[0][dest]*(red-i)+mp[1][dest]*(blue-j));
        }
    }
    cout<<ans<<"\n";
}
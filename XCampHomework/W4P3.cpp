#pragma GCC optimize ("03")
#include <bits/stdc++.h>
using namespace std; 
vector<int> sub, a;
vector<vector<int>> freee, adj, path;
vector<vector<vector<int>>> on;
long long int dp[151][151][151][2][2];
void dfs(int& r, int& i, int& p){
    if(p!=r)freee[r][i] = freee[r][p]+sub[p]-sub[i]-1;
    else freee[r][i]=0;
    for(auto& c:adj[i]){
        if(c!=p)dfs(r,c,i);
    }
}
void dsub(int& i, int& p){
    sub[i]=1;
    for(auto& c:adj[i]){
        if(c==p)continue;
        dsub(c,i);
        sub[i]+=sub[c];
    }
}
void solve(){
    int n;
    cin>>n;n++;
    sub.assign(n,0);
    freee.assign(n,vector<int>(n));
    adj.assign(n,vector<int>(0));
    path.assign(n, vector<int>(n));
    on.assign(n, vector<vector<int>>(n,vector<int>(n)));
    a.assign(n-1,0);
    for(int i=0; i<n-1; i++)cin>>a[i];
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //precompute freee(u,v) = number of freee edges on path between u, v
    for(int i=0; i<n; i++){
        freee[i][i]=0;
        dsub(i,i);
        dfs(i,i,i);
    }
    const auto dfs3 = [&](const auto& dfs3, int& s, int& t, int& i, int& p)->bool {
        if(i==t){
            on[i][s][t] = true;
            return true;
        }
        for(auto& c:adj[i]){
            if(c!=p){
                if(dfs3(dfs3,s,t,c,i)){
                    on[i][s][t]=true;
                    path[s][t]++;
                    return true;
                }
            }
        }
        return false;
    };
    //get nodes on path, get path length
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dfs3(dfs3, i,j,i,i);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                for(int l=0; l<2; l++){
                    for(int p=0; p<2; p++)dp[i][j][k][l][p]=-1e15;
                }
            }
        }
    }
    //dp[i][u][v][au][av]
    //if we have freee edge, 
    //we can do dp[i+1][u][v][au][av] = dp[i][u][v][au][av] trash(a[i])
    //if au or av is 0,
    // we can do dp[i+1][u][v][1][av]=dp[i][u][au][av]+a[i]; (assign ai to this node)
    // if au or av is one, we can extend to a child, i.e
    // dp[i][c][v][0][av] = dp[i][u][v][1][av]
    //how to iterate?
    for(int i=0; i<n; i++)dp[0][i][i][1][1]=0;
    long long ans = -1;
    for(int i=0; i<n-1; i++){
    for(int au = 1; au>=0; au--){
    for(int av = 1; av>=0; av--){
    for(int u=0; u<n; u++){
    for(int v=0; v<n; v++){
        if(dp[i][u][v][au][av]<0)continue; //ignore unreachable states
        long long cur = dp[i][u][v][au][av];
        if(au==0){
            dp[i+1][u][v][1][av] = max(dp[i+1][u][v][1][av], cur+a[i]);
        }else{
            for(auto& c:adj[u]){
                if(!on[c][u][v])dp[i][c][v][0][av] = max(dp[i][c][v][0][av], cur);
            }
        }
        if(av==0){
            dp[i+1][u][v][au][1] = max(dp[i+1][u][v][au][1], cur+a[i]);
        }else{
            for(auto& c:adj[v]){
                if(!on[c][u][v])dp[i][u][c][au][0] = max(dp[i][u][c][au][0], cur);
            }
        }
        //check freee edge
        //number of numbers placed on main path is path[u][v]-au-av
        if(path[u][v]-(au==0)-(av==0)+freee[u][v]-i>=1) //number of trash edges used
        dp[i+1][u][v][au][av]=max(dp[i+1][u][v][au][av],cur);
    }
    }
    }
    }
    }
    // answer is max across dp.[n-1][u][v][1][1];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[n-1][i][j][1][1]);
        }
    }
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
#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a,b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<int,int> mp;
    vector<bool> vis(n);
    auto dfs = [&] (auto dfs,int i)->int {
        vis[i]=true;
        int ans = 1;
        for(auto& c:adj[i]){
            if(!vis[c]){
                vis[c]=true;
                ans+=dfs(dfs,c);
            }
        }
        return ans;
    };
    for(int i=0; i<n; i++){
        if(!vis[i])mp[dfs(dfs,i)]++;
    }
    vector<pair<int,int>> items;
    for(auto& i:mp){
        int s = i.first, cnt = i.second;
        //binary decomp, we can represent all possible number of components we take
        //in log(cnt) items
        for(int j=1; j<=cnt; j*=2){
            items.push_back({j*s,j});
            cnt-=j;
        }
        if(cnt){
            items.push_back({s*cnt,cnt});
        }
    }
    vector<int> dp(n+5,INT_MAX);
    dp[0]=0;
    for(auto& [s,cost]:items){
        for(int i=n; i>=s; i--){
            if(dp[i-s]!=INT_MAX)dp[i] = min(dp[i],dp[i-s]+cost);
        }
    }
    int ans = INT_MAX;
    auto ok = [&](int i)->bool {
        while(i){
            if(i%10!=4&&i%10!=7)return false;
            i/=10;
        }
        return true;
    };
    for(int i=1; i<=n; i++){
        if(ok(i))ans = min(ans,dp[i]);
    }
    if(ans==INT_MAX)ans = 0;
    cout<<ans-1<<"\n";
}
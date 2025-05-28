#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> x;
int ans;
vector<vector<int>> adj;
vector<vector<int>> dp;
int get(int i){
    return max({dp[i][0],dp[i][1]-x[i],dp[i][2]+x[i],dp[i][3]});
}
void dfs(int i, int p){
    dp[i][0] = x[i];
    dp[i][1]=dp[i][2]=dp[i][3]=INT_MIN;
    vector<int> ch;
    for(auto& c:adj[i])if(c!=p){
        dfs(c,i);
        ch.push_back(get(c));
    }
    sort(ch.rbegin(),ch.rend());
    if(ch.size()>=1){
        dp[i][1] = x[i]+ch[0];
    }
    if(ch.size()>=2){
        dp[i][2] = ch[0]+ch[1];
    }
    if(ch.size()>=3){
        dp[i][3] = x[i]+ch[0]+ch[1]+ch[2];
        for(int j=3; j<ch.size(); j++){
            if(ch[j]<0)break;
            dp[i][3]+=ch[j];
        }
    }
    ans = max({ans,dp[i][0],dp[i][1],dp[i][2],dp[i][3]});
}
void solve(){
    int n;
    cin>>n;
    x.assign(n,0);
    adj.assign(n,vector<int>());
    dp.assign(n,vector<int>(4,0));
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans=0;
    dfs(0,0);
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
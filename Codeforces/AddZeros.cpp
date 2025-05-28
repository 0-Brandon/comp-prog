#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    map<int,vector<int>,greater<int>> mp;
    for(int i=0; i<n; i++){
        cin>>x[i];
        mp[-(n-i-x[i])].push_back(i);
    }
    int ans = 0;
    map<int,int> dp;
    dp[0] = 0;
    for(auto& [i,c]:dp){
        for(auto& j:mp[i]){
            dp[i+j] = max(dp[i+j],dp[i]+j);
            ans = max(ans,dp[i+j]);
        }
    }
    cout<<ans+n<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
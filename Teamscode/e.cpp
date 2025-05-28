#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a,b,c,n;cin>>a>>b>>c>>n;
    vector<int> dp(5*n+5,1e18);
    dp[1]=a;
    int ans = 1e18;
    for(int i=1; i<dp.size(); i++){
        if(i<dp.size()-1)dp[i+1] = min(dp[i+1],dp[i]+a);
        for(int j=2*i; j<dp.size(); j+=i){
            dp[j] = min(dp[j],dp[i]+b+c*((j-i)/i));
        }
        if(i>=n)ans = min(ans,dp[i]);
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;while(t--){
        solve();
    }
}
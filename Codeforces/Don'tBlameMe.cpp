#include <bits/stdc++.h>

using namespace std;
int mod = 1000000007;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    vector<vector<int>> dp(n, vector<int>(64,0));
    for(int i=0; i<n; i++){
        cin>>x[i];
        for(int j=0; j<64; j++){
            if(i>0)dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            if(i>0)dp[i][j&x[i]]=(dp[i][j&x[i]]+dp[i-1][j])%mod;
        }
        dp[i][x[i]]=(dp[i][x[i]]+1)%mod;
    }
    int ans=0;
    for(int i=0; i<1<<6; i++){
        if(__builtin_popcount(i)==k){
            ans+=dp.back()[i];
            ans%=mod;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
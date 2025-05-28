#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<int> dp(n+1);
    dp[n] = 0;
    for(int i=n-1; i>=0; i--){
        dp[i] = dp[i+1]+1;
        if(x[i]+i<n)dp[i] = min(dp[i], dp[i+x[i]+1]);
    }
    cout<<dp[0]<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
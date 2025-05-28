#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<int> dp(n,0), dp1(n,0);
    for(int i=1; i<n; i++){
        dp[i] = dp[i-1];
        if(x[i]<=x[i-1])dp[i]++;

        dp1[i]=dp1[i-1];
        if(x[i]>=x[i-1])dp1[i]++;
        dp[i] = min(dp[i],dp1[i-1]+1);
    }
    cout<<min(dp.back(),dp1.back()+1)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
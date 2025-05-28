#include <bits/stdc++.h>

using namespace std;

//broken

void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    vector<vector<int>>dp(n+5, vector<int>(n+5,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            dp[i+1][j]=max({a[i],dp[i+1][j], dp[i][j]});
            dp[i+1][(max(b[j],b[i])==b[j])?j:i]=max(dp[i+1][(max(b[j],b[i])==b[j])?j:i],dp[i][j]);
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i ++){
        ans=min(ans, abs(dp[n][i]-b[i]));
    }
    cout<<ans<<"\n";
}

int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}
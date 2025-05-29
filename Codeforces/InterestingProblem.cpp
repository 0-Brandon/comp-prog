#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, INT_MAX));
    for(int i=0; i<=n; i++)dp[i][i] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j+i<=n; j++){
            if(x[j]%2!=(j+1)%2)continue;
            if(x[j]>j+1)continue;
            int v = (j+1-x[j])/2;
            int u = i+j;
            for(int k = j+1; k<u; k+=2){
                if(dp[j+1][k]<=v){
                    int nv = max(v, dp[k+1][u] - (k-j+1)/2);
                    dp[j][u] = min(dp[j][u], nv);
                }
            }
        }
    }
    vector<int> dp2(n+1);
    for(int i=0; i<n; i++){
        dp2[i+1] = dp2[i];
        for(int j=0; j<i; j++){
            if(dp[j][i+1]<=dp2[j]){
                dp2[i+1]=max(dp2[i+1],dp2[j]+(i-j+1)/2);
            }
        }
    }
    cout<<dp2[n]<<"\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}
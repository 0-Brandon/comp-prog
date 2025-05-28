#include <bits/stdc++.h>

using namespace std;
//doesn't work
void solve(){
    int n, k;
    cin>>n>>k;
    int inf = INT_MIN;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    vector<long long> dp1(n+1,-inf), dp2(n+1,-inf), dp3(n+1,-inf), dp4(n+1,-inf);
    vector<vector<long long>> dp(n+1, vector<long long>(k+1,0));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=min(i,k); j++){
            int d = i-j;
            if (i != 0) dp[i][j] = dp[i - 1][j];
            if(i>0){
                dp[i][j]=max(dp[i][j], dp1[d]-a[i-1]-b[i-1]);
                dp[i][j]=max(dp[i][j], dp2[d]-a[i-1]+b[i-1]);
                dp[i][j]=max(dp[i][j], dp3[d]+a[i-1]-b[i-1]);
                dp[i][j]=max(dp[i][j], dp4[d]+a[i-1]+b[i-1]);
            }
            if(i<n){
                dp1[d]=max(dp1[d],dp[i][j]+a[i]+b[i]);
                dp2[d]=max(dp2[d],dp[i][j]+a[i]-b[i]);
                dp3[d]=max(dp3[d],dp[i][j]-a[i]+b[i]);
                dp4[d]=max(dp4[d],dp[i][j]-a[i]-b[i]);
            }
        }
    }
    cout<<dp[n][k]<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
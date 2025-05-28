#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9+7;

signed main() {
    string a, b; int n,m,k;
    cin>>n>>m>>k;
    cin>>a>>b;
    vector dp(n+1, vector(k+1, vector<int>(2,0)));
    dp[0][0][0] = 1;
    for (int i=0; i<=m; i++) {
        vector ndp(n+1, vector(k+1, vector<int>(2,0)));
        for(int j=0; j<=n; j++){
            for (int r=0; r<=k; r++) {
                for (int s=0; s<2; s++) {
                    int cur=dp[j][r][s];
                    if (cur==0) continue;
                    if(s==0&&j<n)dp[j+1][r][0] = (dp[j+1][r][0]+cur)%mod;
                    if(s==0&&i<m&&j<n&&a[j]==b[i])ndp[j+1][r][1] = (ndp[j+1][r][1]+cur)%mod;
                    if(s==1){
                        if(i<m&&j<n&&a[j]==b[i])ndp[j+1][r][1] = (ndp[j+1][r][1]+cur)%mod;
                        if(r<k)dp[j][r+1][0] = (dp[j][r+1][0]+cur)%mod;
                    }
                }
            }
        }
        if(i<m)swap(ndp,dp);
    }
    cout<<dp[n][k][0]<<"\n";
}
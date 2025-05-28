#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int n, k;
    cin>>n>>k;
    vector<int> x(n+1,0);
    int hmax = 0;
    int cumsum=0;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i=1; i<=n; i++){
        cin>>x[i];
        hmax = max(x[i],hmax);
        dp[i][0]=hmax*i;
        for(int j=1; j<=k; j++){
            dp[i][j]=1e9;
            int high = x[i];
            for(int b=i-1; b>=0; b--){
                dp[i][j]=min(dp[i][j],dp[b][j-1]+(i-b)*high);
                high = max(high,x[b]);
            }
        }
        cumsum+=x[i];
    }
    cout<<dp[n][k]-cumsum;
}
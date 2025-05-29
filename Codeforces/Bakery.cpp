#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<array<int,3>> x(n+1);
    array<bool,3> a;
    for(int i=1; i<=n ;i++){
        for(int j=0; j<3; j++){
            cin>>x[i][j];
            if(x[i][j]!=0)a[j] = true;
        }
    }
    vector dp(n+1, vector<int>(8,1e18));
    dp[0][0]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=7; j++){
            if(j&1)dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i-1][j^1])+x[i][1]+x[i][2]);
			if(j&2)dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i-1][j^2])+x[i][0]+x[i][2]);
			if(j&4)dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i-1][j^4])+x[i][0]+x[i][1]);
        }
    }
    int ans = 1e18;
    for(int i=0; i<=7; i++){
        if((i|!a[0]|(!a[1]<<1)|(!a[2]<<2))==7)ans = min(ans,dp[n][i]);
    }
    cout<<ans<<"\n";
}
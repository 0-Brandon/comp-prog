#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("feast.out", "w",stdout);
    freopen("feast.in","r",stdin);
    int t, a, b;
    cin>>t>>a>>b;
    vector<vector<bool>> dp(t+1, vector<bool>(2, false));
    int ans = 0;
    dp[0][1]=true;
    dp[0][0]=true;
    for(int k=1; k>=0; k--){
        for(int i=0; i<t+1; i++){
            if(!dp[i][k])dp[i][k]=(i-a>=0?dp[i-a][k]:false)||(i-b>=0?dp[i-b][k]:false);
            if(k>0&&dp[i][k]) dp[i/2][k-1]=true;
            if(dp[i][k])ans = max(ans, i);
        }
    }
    cout<<ans;
}
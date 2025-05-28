#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;cin>>n>>m;
    vector x(n+1,vector<int>(m+1));
    for(int i=1; i<=n; i++){
        string s;cin>>s;
        for(int j=1; j<=m; j++){
            x[i][j]=s[j-1];
        }
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1])+
            max(dp[i][j-1][0], dp[i][j-1][1])-*max_element(dp[i-1][j-1]);
            dp[i][j][0] = max(dp[i][j][0], max(dp[i-1][j][0],dp[i-1][j][2])+
                        max(dp[i][j-1][0], dp[i][j-1][2])-*max_element(dp[i-1][j-1]));
            if(x[i][j]!='W')continue;
            cout<<x[i][j]<<" ";
            if(i-2>=1&&x[i-1][j]=='G'&&x[i-2][j]=='R'){
                dp[i][j] = max(dp[i][j],dp[i-3][j]+dp[i][j-1]-dp[i-3][j-1]+1);
            }
            if(j-2>=1&&x[i][j-1]=='G'&&x[i][j-2]=='R'){
                dp[i][j] = max(dp[i][j],dp[i][j-3]+dp[i-1][j]-dp[i-1][j-3]+1);
            }

        }
    }
    for(auto& i:dp){
        for(auto& j:i)cout<<j<<" ";cout<<"\n";
    }
    cout<<dp[n][m]<<"\n";
}
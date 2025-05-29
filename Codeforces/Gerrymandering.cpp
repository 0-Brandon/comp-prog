#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int>> x(n+5,vector<int>(2,0));
    for(int i=0; i<2; i++){
        string s;cin>>s;
        for(int j=0; j<n; j++){
            x[j][i] = (s[j]=='A');
        }
    }
    vector dp(n+5,vector<int>(3,-1));
    //0 means none
    //1 means 1 down
    //2 means 1 up
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        if(dp[i][0]!=-1){
        dp[i+3][0] = max(dp[i+3][0], dp[i][0]+(x[i][0]+x[i+1][0]+x[i+2][0])/2+(x[i][1]+x[i+1][1]+x[i+2][1])/2);
        dp[i+1][1] = max(dp[i+1][1], dp[i][0]+(x[i][0]+x[i][1]+x[i+1][1])/2);
        dp[i+1][2] = max(dp[i+1][2], dp[i][0]+(x[i][0]+x[i][1]+x[i+1][0])/2);
        }
        if(dp[i][1]!=-1){
        dp[i+2][0] = max(dp[i+2][0], dp[i][1]+(x[i][0]+x[i+1][0]+x[i+1][1])/2);
        dp[i+3][1] = max(dp[i+3][1], dp[i][1]+(x[i][0]+x[i+1][0]+x[i+2][0])/2+(x[i+1][1]+x[i+2][1]+x[i+3][1])/2);
        }
        if(dp[i][2]!=-1){
        dp[i+2][0] = max(dp[i+2][0], dp[i][2]+(x[i][1]+x[i+1][0]+x[i+1][1])/2);
        dp[i+3][2] = max(dp[i+3][2], dp[i][2]+(x[i][1]+x[i+1][1]+x[i+2][1])/2+(x[i+1][0]+x[i+2][0]+x[i+3][0])/2);
        }
    }
    cout<<dp[n][0]<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
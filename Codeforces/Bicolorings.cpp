#include <bits/stdc++.h>

using namespace std;
//doesn't work
int main(){
    int mod = 998244353;
    int n, k;
    cin>>n>>k;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+5,vector<int>(8,0)));
    //dp i, j, k is num ways to have j comps in first i columns where k is the edge
    dp[0][1][0]=dp[0][1][3]=dp[0][2][1]=dp[0][2][2]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            for(int mask = 0; mask<=3; mask++){
                dp[i+1][j][mask]+=dp[i][j][mask]; //extend current edge
                dp[i+1][j][mask]%=mod;
                if(mask==0||mask==3){ //00 or 11
                    dp[i+1][j+1][~mask*-1]+=dp[i][j][mask]; //11 or 00
                    dp[i+1][j][~mask*-1]%=mod;
                    dp[i+1][j+1][2]+=dp[i][j][mask]; //10
                    dp[i+1][j+1][2]%=mod;
                    dp[i+1][j+1][1]+=dp[i][j][mask]; //01
                    dp[i+1][j+1][1]%=mod;
                }else{ //01 or 10
                    dp[i+1][j+2][~mask*-1]+=dp[i][j][mask]; //flip it to add 2 new components
                    dp[i+1][j+2][~mask*-1]%=mod;
                    dp[i+1][j][3]+=dp[i][j][mask]; //11
                    dp[i+1][j][3]%=mod;
                    dp[i+1][j][0]+=dp[i][j][mask]; //00
                    dp[i+1][j][0]%=mod;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=3; i++){
        ans+=dp[n-1][k][i];
    }
    cout<<ans;
}
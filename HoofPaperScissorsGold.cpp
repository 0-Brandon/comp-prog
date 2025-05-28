#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("hps.out","w",stdout);
    freopen("hps.in", "r",stdin);
    int n, k;
    cin>>n>>k;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1, vector<int>(3, 0))); 
    vector<int> x(n);
    for(int i=0; i<n; i++){
        char t;
        cin>>t;
        if(t=='P') x[i]=0;
        if(t=='H') x[i]=1;
        if(t=='S') x[i]=2;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=k; j++){
            for(int l=0; l<3; l++){
                switch(x[i]){
                    case 0:
                        if(l==2){
                            dp[i+1][j][l]=max(dp[i][j][l]+1, dp[i+1][j][l]);
                        }
                        else{
                            dp[i+1][j][l]=max(dp[i][j][l],dp[i+1][j][l]);
                            if(j>0)dp[i+1][j-1][2]=max(dp[i][j][l]+1, dp[i+1][j-1][2]);
                        }
                    break;
                    case 1:
                        if(l==0){
                            dp[i+1][j][l]=max(dp[i][j][l]+1, dp[i+1][j][l]);
                        }
                        else{
                            dp[i+1][j][l]=max(dp[i][j][l], dp[i+1][j][l]);
                            if(j>0)dp[i+1][j-1][0]=max(dp[i][j][l]+1,dp[i+1][j-1][0]);
                        }
                    break;
                    case 2:
                        if(l==1){
                            dp[i+1][j][l]=max(dp[i][j][l]+1, dp[i+1][j][l]);
                        }
                        else{
                            dp[i+1][j][l]=max(dp[i][j][l], dp[i+1][j][l]);
                            if(j>0)dp[i+1][j-1][1]=max(dp[i][j][l]+1, dp[i+1][j-1][1]);
                        }
                    break;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=k; i++){
        for(int j=0; j<3; j++){
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout<<ans;
}
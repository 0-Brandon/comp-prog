#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dp(m, vector<int>(1<<n,0));
    dp[0][0]=1;
    for(int i=0; i<=m; i++){
        for(int j=0; j<1<<n; j++){
            for(int k=0; k<n; k++){
                if(j&1<<k){
                }
                else{
                    dp[i+1][j|1<<k]+=dp[i][j];
                    if(k<n-1&&dp[i][1<<k+1])
                }
            }
        }
    }
}
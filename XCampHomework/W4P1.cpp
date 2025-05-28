#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("pieaters.in","r",stdin);
    freopen("pieaters.out","w",stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<vector<int>>> mx(n, vector<vector<int>>(n,vector<int>(n,0)));
    for(int i=0; i<m; i++){
        int w,l, r;
        cin>>w>>l>>r;
        l--,r--;
        for(int i=l; i<=r; i++){
            mx[i][l][r] = max(mx[i][l][r],w);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            for(int k=i; k<n; k++){
                if(j>0)mx[i][j-1][k]=max(mx[i][j-1][k],mx[i][j][k]);
                if(k<n-1)mx[i][j][k+1]=max(mx[i][j][k+1],mx[i][j][k]);
            }
        }
    }
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int i=n-1; i>=0; i--){
        for(int j=i; j<n; j++){
            for(int k=i; k<j; k++){
                dp[i][j] = max(dp[i][k]+dp[k+1][j], dp[i][j]);
            }
            for(int k=i; k<=j; k++){
                dp[i][j] = max(dp[i][j], (k>i?dp[i][k-1]:0)+(k<j?dp[k+1][j]:0)+mx[k][i][j]);
            }
        }
    }
    cout<<dp[0][n-1];
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n; 
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<vector<int>> dp(n, vector<int> (n));
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(x[i]==x[j]){
                dp[i][j]=dp[i+1][j-1]+1;
            }
            for(int k=i; k<j; k++){
                dp[i][j]=max(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    cout<<n-dp[0][n-1]<<"\n";
}

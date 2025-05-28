#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;cin>>n>>k;
    vector<string> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end(),[&](auto i, auto j){return (i+j)<(j+i);});
    vector dp(n+1,vector<string>(k+1,string(55,'z')));
    dp[n][0] = "";
    for(int i=n-1; i>=0; i--){
        dp[i][0]= "";
        for(int j=1; j<=min(k,n-i); j++){
            dp[i][j] = min(dp[i+1][j], x[i]+dp[i+1][j-1]);
        }
    }
    cout<<dp[0][k]<<"\n";
}
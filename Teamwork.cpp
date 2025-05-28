#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> dp(n,0);
    for(int i=0; i<n; i++){
        int high = x[i];
        dp[i]=x[i];
        for(int j=0; j<k&&i-j>=0; j++){
            high = max(high,x[i-j]);
            dp[i]=max(dp[i],((i-j-1)>=0?(dp[i-j-1]):(0))+(j+1)*high);
        }
    }
    cout<<dp[n-1];
}
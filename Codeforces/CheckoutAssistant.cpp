#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> t(n),c(n);
    for(int i=0; i<n; i++){
        cin>>t[i]>>c[i];
        t[i]++;
    }
    vector<long long int> dp(n+1,INT_MAX*1LL*INT_MAX);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=n; j>=0; j--){
            dp[j]=min(dp[j],dp[max(j-t[i],0)]+c[i]);
        }
    }
    cout<<dp[n];
}
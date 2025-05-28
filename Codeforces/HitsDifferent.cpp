#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> ans(2000005,0);
    long long cur = 1;
    vector<vector<long long>> dp(1500, vector<long long>(1500,0));
    for(int i=1; i<1500; i++){
        for(int j=1; j<i; j++){
            dp[i-j][j]=dp[i-j-1][j]+dp[i-j][j-1]-dp[i-j-1][j-1]+cur*cur;
            ans[cur]=dp[i-j][j];
            cur++;
        }
    }
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<"\n";
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9+7;
signed main(){
    int n;
    int mh=INT_MAX;
    cin>>n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
        mh = min(mh,h[i]);
    }
    if(n%2==0){
        //even
        vector<vector<int>> dp(n,vector<int>(1001,0));
        //dp[i][j] = num ways to put first i, given xi is j
        for(int i=0; i<=h[0]; i++)dp[0][i]=1;
        for(int i=1; i<n; i++){
            dp[i][h[i]]=dp[i-1][0];
            for(int j=h[i]-1; j>=0; j--){
                dp[i][j] = (dp[i][j+1]+dp[i-1][h[i]-j])%mod;
            }
        }
        int ans = dp[n-1][0];
        cout<<ans<<"\n";
    }
    else{
        int fans = 0;
        //odd
        for(int i=0; i<=mh; i++){
            vector<vector<int>> dp(n,vector<int>(1001,0));
            //dp[i][j] = num ways to put first i, given xi is j
            for(int i=0; i<=h[0]; i++)dp[0][i]=1;
            for(int i=1; i<n; i++){
                dp[i][h[i]]=dp[i-1][0];
                for(int j=h[i]-1; j>=0; j--){
                    dp[i][j] = (dp[i][j+1]+dp[i-1][h[i]-j])%mod;
                }
            }
            int ans = dp[n-1][0];
            fans=(fans+ans)%mod;
            for(int i=0; i<n; i++)h[i]--;
        }
        cout<<fans<<"\n";
    }
}
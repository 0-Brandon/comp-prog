#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;
int expo(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=a*a%mod){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
signed main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> dp(k+1, vector<int>(k+1,0));
    dp[0][0]=1;
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = (dp[i][j]+dp[i-1][j-1]*(n-(j-1))%mod)%mod;
            dp[i][j] = (dp[i][j]+dp[i-1][j]*j%mod)%mod;
        }
    }
    int ans = 0;
    for(int i=1; i<=k; i++){
        ans=(ans+dp[k][i]*expo(expo(m,mod-2),i)%mod)%mod;
    }
    cout<<ans<<"\n";
}
#include <bits/stdc++.h>
#define int long long
using  namespace std;

constexpr int mod = 1e9+7;
signed main(){
    int n, k;
    cin>>n>>k;
    vector<int> x(k+1);
    for(int i=1; i<=k; i++){
        cin>>x[i];
    }
    vector<int> fac(n+1);
    fac[0]=1;
    for(int i=1; i<=n; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    auto exp = [&](int a, int b){
        int ans = 1;
        for(;b;b/=2,a=a*a%mod){
            if(b&1)ans=ans*a%mod;
        }
        return ans;
    };
    vector<int> inv(n+1);
    for(int i=0; i<=n; i++){
        inv[i] = exp(fac[i],mod-2);
    }
    auto C = [&](int n, int k){
        return fac[n]*inv[k]%mod*inv[n-k]%mod;
    };
    //dp[i][j] number of ways to give j people red cookies on ith day
    vector dp (k+1, vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int m=0; m<=min(j,x[i]); m++){
                dp[i][j] = (dp[i][j]+dp[i-1][j-m] * C(n-(j-m),m)%mod * C(n-m, x[i]-m)%mod)%mod;
            }
        }
    }
    cout<<dp[k][n]<<"\n";
}
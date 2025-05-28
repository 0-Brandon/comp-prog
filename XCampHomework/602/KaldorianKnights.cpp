#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9+7;
signed main(){
    int na, ka;cin>>na>>ka;
    vector<int> fac(na+1);
    fac[0]=1;
    for(int i=1; i<=na; i++)fac[i] = 1LL*fac[i-1]*i%mod;
    vector<int> x(ka);
    vector<int> p(ka+2,0);
    for(int i=0; i<ka; i++){
        cin>>x[i];
        p[i+2] = p[i+1]+x[i];
    }
    unordered_map<int,vector<int>> dp;
    auto dfs = [&](auto&& dfs, int n, int k)->int {
        if(dp.find(n)==dp.end())dp[n] = vector<int>(ka+1,0);
        if(dp[n][k]!=0)return dp[n][k];
        int& ret = dp[n][k];
        ret = fac[n];
        for(int i=k; i>=1; i--){
            ret=(0LL+ret-fac[n-p[i+1]]*1LL*dfs(dfs,p[i+1],i-1)%mod+mod)%mod;
        }
        return ret;
    };
    int ans = dfs(dfs,na,ka);
    cout<<ans<<"\n";
}

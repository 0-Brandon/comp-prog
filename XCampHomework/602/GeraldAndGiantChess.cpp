#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> fac(200005), inv(200005);
constexpr int mod = 1e9+7;
int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1, a=a*a%mod){
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
void solve(){
    int h, w, n;cin>>h>>w>>n;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
    }
    x.push_back({1,1});
    vector<int> dp(n+1);
    auto C = [&](int n,int k){
        if(n<k)return 0LL;
        return fac[n]*inv[k]%mod*inv[n-k]%mod;
    };
    sort(x.begin(),x.end());
    for(int i=n; i>=0; i--){
        dp[i] =  C(h+w-x[i].first-x[i].second,h-x[i].first);
        for(int j=i+1; j<=n; j++){
            dp[i]= dp[i]+mod-(C(x[j].first+x[j].second-x[i].first-x[i].second,x[j].first-x[i].first)*dp[j])%mod;
            dp[i] %=mod;
        }
    }
    cout<<dp[0]<<"\n";
}
signed main(){
    fac[0]=1;
    for(int i=1; i<200005; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    for(int i=0; i<200005; i++){
        inv[i] = exp(fac[i],mod-2);
    }
    int t=1;
    while(t--)solve();
}
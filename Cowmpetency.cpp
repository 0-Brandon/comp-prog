#include <bits/stdc++.h>

#define int long long
using namespace std;
constexpr int mod = 1e9+7;
int exp(int a, int b){
    b = b%mod;
    a = a%mod;
    if(a<0)return 1;
    int ans=1;
    for(;b; b/=2,a=(a*a)%mod){
        if(b&1)ans = (ans*a)%mod;
    }
    return ans;
}
signed main(){
    int n, q, c;
    cin>>n>>q>>c;
    map<int,int> ha;
    vector<pair<int,int>> x;
    for(int i=0; i<q; i++){
        int a, h;
        cin>>a>>h;
        if(!ha.count(h))ha[h]=a;
        else ha[h]=min(a,ha[h]);
    }
    for(auto& ch:ha){
        x.push_back({ch.first,ch.second});
    }
    //h,a
    sort(x.begin(),x.end());
    vector<vector<int>> dp(x.size(),vector<int> (c+1,0));
    for(int i=0; i<x.size(); i++){
        int pref = 0;
        int h = x[i].first, a = x[i].second;
        int lh = 0;
        if(i>0)lh=x[i-1].first;
        int w = h-a-1;
        int u = a-lh;
        for(int j=1; j<=c; j++){
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            if(i>0)dp[i][j]= (dp[i][j]+(dp[i-1][j-1]*exp(j-1,u+w))%mod)%mod;
            dp[i][j]=(dp[i][j]+((pref*((exp(j-1,u)-exp(j-2,u)+mod)%mod))%mod*exp(j-1,w)%mod)%mod)%mod;
            if(i>0)pref=(pref+dp[i-1][j-1])%mod;
            else pref = 1;
        }
    }
    int ans = 0;
    for(int i=1; i<=c; i++){
        ans = (ans+dp.back()[i])%mod;
    }
    ans = (ans*exp(c,n-x.back().first)%mod)%mod;
    cout<<ans<<"\n";
}
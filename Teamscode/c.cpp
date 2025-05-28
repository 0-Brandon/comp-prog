#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
int exp(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=a*a%mod){
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
int inv(int i){
    return exp(i,mod-2);
}
void solve(){
    int n;cin>>n;
    vector<int> suf(n+1);
    suf.back() = (n-1)*inv(n)%mod;
    for(int i=n-1; i>=1; i--){
        suf[i] = (i-1)*inv(i)%mod*suf[i+1]%mod;
    }
    int ans = 1;
    for(int i=2; i<n; i++){
        ans=(ans+inv(i-1)*((i-1)*inv(i)%mod)%mod)%mod;
        ans -= suf[i];
        ans=(ans+mod)%mod;
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
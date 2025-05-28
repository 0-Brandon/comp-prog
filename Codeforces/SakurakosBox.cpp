#include <bits/stdc++.h>
#define int long long
constexpr int mod = 1e9+7;
using namespace std;

int exp(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=a*a%mod){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    vector<int> x(n);
    int su = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        su=(x[i]+su)%mod;
    }
    int tot = 0;
    for(int i=0; i<n; i++){
        tot = (tot+x[i]*((su-x[i]+mod)%mod))%mod;
        su=su-x[i]+mod;
        su%=mod;
    }
    int ans = tot*exp(n*(n-1)/2%mod,mod-2)%mod;
    cout<<ans<<"\n";
}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
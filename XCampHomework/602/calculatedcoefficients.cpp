#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 10007;
int expo(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=a*a%mod){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
signed main(){
    vector<int> fac(1001);
    fac[0]=1;
    for(int i=1; i<1001; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    vector<int> inv(1001);
    inv[1000] = expo(fac[1000],mod-2);
    for(int i=999; i>=0; i--){
        inv[i] = inv[i+1]*(i+1)%mod;
    }
    auto C = [&](int n, int k){
        return fac[n]*inv[k]%mod*inv[n-k]%mod;
    };
    int a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    cout<<(C(k,n)*expo(a,n)%mod*expo(b,m)%mod);
}
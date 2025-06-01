#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;
int expo(int a, int b){
    int ans = 1;
    for(;b;b/=2, a=a*a%mod){
        if(b&1)ans=a*ans%mod;
    }
    return ans;
}
signed main(){
    int n, k, p;
    cin>>n>>k>>p;
    vector<int> fac(n+1);
    fac[0]=1;
    for(int i=1; i<=n; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    vector<int> inv(n+1);
    inv[n]=expo(fac[n], mod-2);
    for(int i=n-1; i>=0; i--){
        inv[i] = inv[i+1]*(i+1)%mod;
    }
    auto C = [&](int n, int k){
        return fac[n]*inv[k]%mod*inv[n-k]%mod;
    };
    int num = 1;
    for(int i=0; i<k; i++){
        if (n-i*p<p) {
            cout<<"1\n";
            return 0;
        }
        num*=C(n-i*p,p);
        num%=mod;
    }
    int ans = (1-num*expo(expo(C(n,p),k),mod-2)%mod+mod)%mod;
    cout<<ans<<"\n";
}
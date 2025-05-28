#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
vector<int> fac(2e5+10), inv(2e5+10);
int exp(int a, int b){
    a = a%mod;
    int ans = 1;
    for(;b;b>>=1,a = (a*a)%mod){
        if(b&1)ans = (ans*a)%mod;
    }
    return ans;
}
int choose(int n, int k){
    if(k>n || k<0)
    return 0;
    if(k==0||n==k)return 1;
    return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    int s = 0;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        s=(s+c)%mod;
    }
    int dem = (n*(n-1)/2)%mod;
    int idem = exp(dem,mod-2);
    s = s*k%mod*idem%mod;
    int ind = 0;
    for(int i=1; i<=k; i++){
        int val = (i*(i-1)/2)%mod;
        ind= (ind + val * choose(k,i) %mod * exp(idem,i)%mod * exp((dem-1)*idem,k-i) %mod)%mod;
    }
    ind = (ind*m)%mod;
    cout<<((s+ind)%mod)<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    fac[0]=1,inv[0]=1;
    for(int i=1; i<2e5+10; i++){
        fac[i] = (fac[i-1]*i)%mod;
        inv[i] = exp(fac[i],mod-2);
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
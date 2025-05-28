#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;
int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1,a = (a*a)%mod){
        if(b&1)ans = (ans*a)%mod;
    }
    return ans;
}
vector<int> fac(4e6+10,0);
int C(int n, int k){
    return fac[n]*exp(fac[n-k],mod-2)%mod*exp(fac[k],mod-2)%mod;
}
void solve(){
    vector<int> c(5);
    cin>>c[1]>>c[2]>>c[3]>>c[4];
    if(abs(c[1]-c[2])>1){cout<<"0\n";return;}
    if(c[1]+c[2]==0){
        if(c[3]==0||c[4]==0)cout<<"1\n";
        else cout<<"0\n";
        return;
    }
    //we assume 1 has 
    int ans = 0;
    if(c[1]<=c[2])
      ans = C(c[1]+c[3],c[3])*C(c[2]+c[4]-1,c[4])%mod;
    if(c[2]<=c[1])
    ans = (ans+ C(c[1]+c[3]-1,c[3])*C(c[2]+c[4],c[4]))%mod;
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    fac[0]=1;
    fac[1]=1;
    for(int i=2; i<fac.size(); i++){
        fac[i] = i*fac[i-1]%mod;
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
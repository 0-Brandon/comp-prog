#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
int expo(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
signed main(){
    int k,n,l;
    cin>>k>>n>>l;
    vector<int> fac(n+1), inv(n+1);
    fac[0] = 1;
    for(int i=1; i<=n; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    inv[n] = expo(fac[n],mod-2);
    for(int i=n-1; i>=0; i--){ //maybe inv[0] is messy? check
        inv[i] = inv[i+1]*(i+1)%mod;
    }
    auto C = [&](int a, int b){
        return fac[a]*inv[b]%mod*inv[a-b]%mod;
    };
    string s;
    cin>>s;
    int cnt = 0;
    int ans = 1;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='M'){
            if(cnt<k){cout<<"0\n";return 0;}
            ans=ans*C(cnt,k)%mod;
            cnt-=k;
        }
        else cnt++;
    }
    if(cnt!=0)cout<<"0\n";
    else cout<<expo(ans,l)<<"\n";
}
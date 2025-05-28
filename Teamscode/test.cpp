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
    int x=(6*(n-2)+1);
    if(n<=2)cout<<1<<"\n";
    else cout<<x*inv(x-1)%mod<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod  =998244353;
int exp(int a, int b){
    int ans = 1;
    for(;b; b/=2, a=a*a%mod){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
signed main(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a;cin>>a;
        a--;
        adj[a].push_back(i+1);
    }
    int ans = 0;
    vector<int> pref(n+1);
    for(int i=1; i<=n; i++){
        pref[i] = (pref[i-1]+exp(i,mod-2))%mod;
    }
    vector<int> d(n);
    d[0]=1;
    for(int i=0; i<n; i++){
        for(auto& c:adj[i]){
            d[c]=d[i]+1;
        }
        ans+=pref[d[i]];
        ans%=mod;
    }
    cout<<ans<<"\n";
}
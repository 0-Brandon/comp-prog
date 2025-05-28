#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> nxt(n,n);
    for(int i=n-1; i-->0;){
        nxt[i] = i+1;
        while(nxt[i]<n&&x[i]<x[nxt[i]]){
            nxt[i] = nxt[nxt[i]];
        }
    }
    int ans =0;
    vector<int> dp(n+1), dpa(n+1), dpb(n+1);
    dpa[0]=1;
    for(int i=0; i<n; i++){
        dp[i] = dpa[i]+dpb[i];
        dp[i] = (dp[i]+mod)%mod;
        dpa[nxt[i]]+=dp[i];
        dpa[nxt[i]]+=dpa[i];
        dpb[nxt[i]]-=dp[i];
        dpb[i+1]+=dp[i];
        dpb[i+1]+=dpb[i];
        if(nxt[i]==n)ans+=dp[i];
        ans%=mod;
        dpb[i+1] = (dpb[i+1]+mod)%mod;
        dpa[nxt[i]] = (dpa[nxt[i]]+mod)%mod;
        dpb[nxt[i]] = (dpb[nxt[i]]+mod)%mod;
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
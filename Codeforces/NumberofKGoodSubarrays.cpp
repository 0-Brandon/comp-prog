#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
map<pair<int,int>,int> dp;
int work(int n, int k){
    if(n<0||k<0)return 0;
    if(n==0)return 0;
    if (k==0)return 1;
    if(dp.find({n,k})!=dp.end())return dp[{n,k}];
    int x = 0;
    while(1LL<<(x+1)<n)x++;
    if(x<=k){
        int ans = ((__int128) n * (__int128) (n + 1) / 2) % mod;
        if(x==k&&n==1LL<<(x+1)){
            ans = ans+mod-n%mod;
            ans%=mod;
        }
        return dp[{n,k}]=ans;
    }
    int ans = work(n-(1LL<<x), k-1)+work(1LL<<x, k)%mod;
    ans%=mod;
    return dp[{n,k}]=ans;
}
void solve(){
    int n, k;
    cin>>n>>k;
    cout<<work(n,k)<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
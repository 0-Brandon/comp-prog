#include <bits/stdc++.h>
#define int long long

using namespace std;
constexpr int mod = 998244353;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<pair<int,int>> edges(m);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; a--,b--;
        edges[i] = {a,b};
    }
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return x[edges[i].first]+x[edges[i].second]<x[edges[j].first]+x[edges[j].second];
    });
    vector<int> dp(m);
    vector<map<int,int>> sdp(n);
    for(int i=0; i<m; i++){
        int a = edges[ord[i]].first;
        int b = edges[ord[i]].second;
        dp[ord[i]]=(1+dp[ord[i]]+sdp[a][x[b]-x[a]])%mod;
        sdp[b][x[a]]=(1+sdp[b][x[a]]+sdp[a][x[b]-x[a]])%mod;
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        ans=(ans+dp[i])%mod;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
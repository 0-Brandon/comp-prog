#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<int> x(n);
    vector<set<int>> adj(n);
    map<set<int>,int> mp;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[b].insert(a);
    }
    for(int i=0; i<n; i++){
        if(!adj[i].empty())mp[adj[i]]+=x[i];
    }
    int ans = mp.begin()->second;
    for(auto& [i,j]:mp){
        ans = gcd(ans,j);
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
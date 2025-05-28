#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++){
        cin>>b[i];b[i]--;
        if(i>0)adj[i].push_back({i-1,0});
        adj[i].push_back({b[i],a[i]});
    }
    vector<int> dist(n,1e17);
    priority_queue<pair<int,int>> pq;
    dist[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [d,i] = pq.top();
        pq.pop();
        if(-d!=dist[i])continue;
        for(auto& [c,v]:adj[i]){
            if(dist[c]>dist[i]+v){
                dist[c] = dist[i]+v;
                pq.push({-dist[c],c});
            }
        }
    }
    int ans = 0;
    int pref = 0;
    for(int i=0; i<n; i++){
        pref+=a[i];
        ans = max(ans,pref-dist[i]);
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m; cin>>n>>m;
    int t0,t1,t2;
    cin>>t0>>t1>>t2;
    vector<vector<array<int,3>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, c,d;cin>>a>>b>>c>>d;a--,b--;
        adj[a].push_back({b,c,d});
        adj[b].push_back({a,c,d});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,INT_MAX);
    dist[n-1]=0;
    pq.push({0,n-1});
    while(!pq.empty()){
        auto [d, i] = pq.top();
        pq.pop();
        if(dist[i]<d)continue;
        for(auto& [c,w1,w2]:adj[i]){
            int w = w1;
            if((t0-d>t1&&t0-d<t2)||(t0-d>=t2&&t0-d-w1<t2))w = min(w2,t0-d-t1+w1);
            if(d+w<dist[c]){
                pq.push({d+w,c});
                dist[c] = d+w;
            }
        }
    }
    if(dist[0]>t0)cout<<"-1\n";
    else cout<<t0-dist[0]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    map<int,int> cid;
    int id=n;
    for(int i=0; i<m; i++){
        int u,v,c;
        cin>>u>>v>>c;
        edges.push_back({u,v,c});
        if(cid.find(c)==cid.end())cid[c]=id++;
    }
    vector<vector<int>> adj(n+id);
    for(auto& [a,b,c]:edges){
        a--,b--;
        adj[b].push_back(cid[c]);
        adj[a].push_back(cid[c]);
        adj[cid[c]].push_back(a);
        adj[cid[c]].push_back(b);
    }
    int s, t;cin>>s>>t;s--,t--;
    if(s==t){cout<<"0\n";return;}
    queue<int> q;
    vector<int> dist(n+id,-1);
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int i = q.front();q.pop();
        for(auto& c:adj[i]){
            if(dist[c]!=-1)continue;
            dist[c] = dist[i]+1;
            q.push(c);
        }
    }
    cout<<dist[t]/2<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
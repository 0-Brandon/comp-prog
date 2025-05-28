#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<array<int,3>> edge;
    map<pair<int,int>,int> x;
    vector<vector<int>> adj(n);
    vector<int> ans(m);
    for(int i=0; i<m; i++){
        int a, b, t;cin>>a>>b>>t;
        a--,b--;
        edge.push_back({a,b,t});
        adj[a].push_back(b);
        if(t==0)adj[b].push_back(a);
    }
    auto check = [&](int a, int b)->bool {
        vector<bool> vis(n);
        auto dfs = [&](auto&& dfs, int i)->void {
            if(vis[i])return;
            vis[i]=true;
            for(auto& c:adj[i]){
                dfs(dfs,c);
            }
        };
        dfs(dfs,a);
        return vis[b];
    };
    for(int i=0; i<m; i++){
        auto [a,b,t] = edge[i];
        if(t==1){cout<<"0\n";continue;}
        //a->b
        adj[b].erase(find(adj[b].begin(),adj[b].end(),a));
        if(check(b,a)){
            cout<<"0\n";
            continue;
        }
        //b->a
        adj[b].push_back(a);
        adj[a].erase(find(adj[a].begin(),adj[a].end(),b));
        cout<<"1\n";
    }
}
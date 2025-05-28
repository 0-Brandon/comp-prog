#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> queries;
vector<bool> act;
vector<int> ans;
vector<vector<int>> adj;
int timer;
void dfs(int i,int p = -1){
    if(ans[i]==-1)ans[i]=timer;
    for(auto& c:adj[i])if(c!=p&&!act[c]){
        act[c]=true;
        dfs(c,i);
    }
}
int main(){
    int n, q;
    cin>>n>>q;
    timer=q;
    queries.resize(q);
    act.resize(n,true);
    ans.resize(n,-1);
    vector<bool> rem;
    adj.resize(n);
    vector<pair<int,int>> edges;
    for(int i=0; i<q; i++){
        char t;
        cin>>t;
        if(t=='D'){
            int a;cin>>a;a--;
            act[a]=0;
            queries[i] = make_pair(-1,a);
        }
        else if(t=='R'){
            int a;cin>>a;a--;
            queries[i] = edges[a];
            rem[a]=true;
        }
        else {
            int a, b;cin>>a>>b;a--,b--;
            edges.push_back({a,b});
            queries[i]=make_pair(-2,-1);
            rem.push_back(false);
        }
    }
    reverse(queries.begin(),queries.end());
    for(int i=0; i<rem.size(); i++){
        if(!rem[i]){
            auto [a,b] = edges[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for(int i=0; i<n; i++){
        if(act[i]){
            dfs(i);
        }
    }
    timer--;
    for(int i=0; i<q; i++,timer--){
        if(queries[i].first==-2)continue;
        else if(queries[i].first==-1){
            act[queries[i].second]=true;
            dfs(queries[i].second);
        }
        else{
            auto[a,b]=queries[i];
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(act[a]&&!act[b])dfs(a);
            if(act[b]&&!act[a])dfs(b);
        }
    }
    for(auto& i:ans)cout<<i<<"\n";
}
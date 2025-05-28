#include <bits/stdc++.h>

using namespace std;
vector<int> compans;
vector<vector<int>> comps;
int compidx = 0;
void dfs(int i,vector<set<int>>& pos, vector<int>& adj, set<int>& s,vector<bool>& visited){
    if(visited[i])return;
    visited[i]=true;
    comps[compidx].push_back(i);
    for(int j:pos[i]){
        s.insert(j);
    }
    dfs(adj[i],pos,adj, s,visited);
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<set<int>> pos(n);
    vector<bool> visited(n);
    vector<int> a(k), b(k);
    for(int i=0; i<k; i++){
        cin>>a[i]>>b[i];
        a[i]--, b[i]--;
    }
    vector<int> x(n);
    vector<int> ans(n);
    vector<int> adj(n);
    for(int i=0; i<n; i++){
        pos[i].insert(i);
    }
    iota(x.begin(),x.end(),0);
    for(int i=0; i<k; i++){
        pos[x[a[i]]].insert(b[i]);
        pos[x[b[i]]].insert(a[i]);
        swap(x[a[i]], x[b[i]]);
    }
    for(int i=0; i<n; i++){
        adj[x[i]]=i;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            compans.push_back(0);
            comps.push_back(vector<int>());
            set<int> s;
            dfs(i,pos, adj, s, visited);
            compans[compidx]=s.size();
            compidx++;
        }
    }
    for(int i=0; i<compidx; i++){
        for(int j=0; j<comps[i].size(); j++){
            ans[comps[i][j]]=compans[i];
        }
    }
    for(auto& i:ans){
        cout<<i<<"\n";
    }
}
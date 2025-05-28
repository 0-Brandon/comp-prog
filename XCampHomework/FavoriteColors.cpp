#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj, rpar;
vector<int> par;
queue<int> q;
void merge(int i, int j){
    i=par[i],j=par[j];
    if(i==j)return;
    if(rpar[i].size()>rpar[j].size())swap(i,j);
    //i is smaller one, to be merged
    //j is new parent
    //rpar refers to all nodes that depend on this node for their color
    //at first, it only contains itself
    //when a node is merged, all its dependents become dependents of the other one
    //a node is merged only once, so its dependents are transferred at most once
    //we cannot use adj in place of rpar because its not that the
    //children depend on the color of j its that i depends on the color of j (and other colors in the same rank)
    //par[i] has nothing to do with directed edges, par[i] is the representative of this "rank"
    //rpar and par are basically just walmart dsu
    //adj has all the nodes that admire this node
    for(auto& k:rpar[i]){
        par[k]=j;
        rpar[j].push_back(k);
    }
    for(auto& k:adj[i]){
        adj[j].push_back(k);
    }
    if(adj[j].size()>1)q.push(j);
}
int main(){
    freopen("fcolor.in","r",stdin);
    freopen("fcolor.out","w",stdout);
    int n, m;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b,a--,b--;
        adj[a].push_back(b);
    }
    rpar.resize(n);
    par.resize(n);
    for(int i=0; i<n; i++){
        par[i]=i;
        if(adj[i].size()>1)q.push(i);
        rpar[i].push_back(i);
    }
    while(!q.empty()){
        int x = q.front();q.pop();
        while(adj[x].size()>1){
            int i=adj[x].back();adj[x].pop_back();
            merge(adj[x].back(),i);
        }
    }
    vector<int> ans(n,0);
    int co=1;
    for(int i=0; i<n; i++){
        if(!ans[par[i]])ans[par[i]]=co++;
        cout<<ans[par[i]]<<"\n";
    }
}
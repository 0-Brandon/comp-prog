#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
vector<int> comp, ord;
vector<vector<int>> adj, cadj, radj;
int compnum=0;
void dfs1(int i){
    if(visited[i])return;
    visited[i]=true;
    for(auto& c:adj[i])dfs1(c);
    ord.push_back(i);
}
void dfs2(int i){
    if(visited[i])return;
    visited[i]=true;
    comp[i]=compnum;
    for(auto& c:radj[i])dfs2(c);
}
void dfs3(int i){
    if(visited[i])return;
    visited[i]=true;
    for(auto& c:cadj[i])dfs3(c);
}
int main(){
    int n, m, s;
    cin>>n>>m>>s;
    s--;
    visited.resize(n,false);
    comp.resize(n);
    adj.resize(n);
    radj.resize(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    for(int i=0; i<n;i++)if(!visited[i])dfs1(i);
    reverse(ord.begin(),ord.end());
    visited.assign(n,0);
    for(auto& i:ord)if(!visited[i])dfs2(i),compnum++;
    cadj.resize(compnum);
    vector<int> ind(compnum,0);
    for(int i=0; i<n; i++){
        for(auto& c:adj[i]){
            if(comp[i]!=comp[c]){
                cadj[comp[i]].push_back(comp[c]);
                ind[comp[c]]++;
            }
        }
    }
    visited.assign(compnum,0);
    dfs3(comp[s]);
    int ans=0;
    for(int i=0; i<compnum; i++)if(!visited[i]&&ind[i]==0)ans++;
    cout<<ans<<"\n";
}

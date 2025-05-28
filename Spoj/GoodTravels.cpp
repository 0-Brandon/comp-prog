#include <bits/stdc++.h>

using namespace std;
vector<int> root;
vector<int> ans;
vector<int> cx;
void dfs(int i, vector<vector<int>>& adj, stack<int>& x, vector<bool>& vis){
    if(vis[i])return;
    vis[i]=true;
    for(auto& c:adj[i])dfs(c,adj,x,vis);
    x.push(i);
}
void dfs2(vector<int>& x, int& i, vector<vector<int>>& radj, vector<bool>& vis, int& r, int& cnum){
    if(vis[i])return;
    cx[cnum]+=x[i];
    vis[i]=true;
    root[i]=r;
    for(auto& c:radj[i])dfs2(x,c,radj,vis,r,cnum);
}
void dfs3(vector<int>& cx, vector<vector<int>>& cradj, vector<vector<int>>& cadj, int i){
    ans[i]=cx[i];
    for(auto& p:cradj[i]){
        ans[i]=max(ans[i], ans[p]+cx[i]);
    }
    for(auto& c:cadj[i]){
        dfs3(cx,cradj,cadj,c);
    }
}
int main(){
    int n, m, s, e;
    cin>>n>>m>>s>>e;
    s--,e--;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<vector<int>> adj(n), radj(n);
    vector<bool> vis(n,false);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    stack<int> ord;
    for(int i=0; i<n; i++){
        dfs(i,adj,ord,vis);
    }
    int cnum=0;
    root.resize(n);
    fill(vis.begin(),vis.end(),false);
    while(!ord.empty()){
        int cur = ord.top();
        ord.pop();
        if(!vis[cur]){
            cx.push_back(0);
            dfs2(x,cur,radj,vis,cur,cnum);
            cnum++;
        }
    }
    vector<vector<int>> cadj(cnum);
    vector<vector<int>> cradj(cnum);
    vector<int> ind(cnum);
    for(int i=0; i<n; i++){
        for(auto& c:adj[i]){
            int u = root[c], v=root[i];
            if(v!=u){
                cadj[v].push_back(u);
                cradj[u].push_back(v);
                ind[u]++;
            }
        }
    }
    //cx stores values of condensed nodes
    //cadj stores adjancency list of condensed nodes
    //cradj stores reverse 
    //roots stores the condensed node which each node belongs
    //roots[s]+roots[e]
    ans.resize(cnum,0);
    dfs3(cx,cradj,cadj,s);
    cout<<ans[e];
}
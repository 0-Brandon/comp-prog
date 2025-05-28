#include <bits/stdc++.h>

//IMPORANT






//THIS CODE IS VERY VERY VERY WRONG!!!!!! LOTS OF ERRORS + SEGFAULTS!!!!!! 
//USE AT OWN RISK!!!!!!!!!!!
//
using namespace std;
vector<vector<int>> up,adj;
vector<int> depth;
int l, n;
void dfs(int i, int p){
    up[i][0]=p;
    for(int k=1; k<=l; k++){
        up[i][l]=up[up[i][l-1]][l-1];
    }
    for(auto& child:adj[i]){
        if(p==child)continue;
        depth[child]=depth[i]+1;
        dfs(child,i);
    }
}
int lca(int u, int v){
    int ans = 0;
    if(depth[u]>depth[v])swap(u,v);
    for(int j=l-1; j>=0; j--){
        if(depth[up[v][j]]<depth[u]){
            v=up[v][j];
            ans+=pow(2,j);
        }
    }
    v=u[v][0];
    if(u==v) return ans;
    for(int j=l-1; j>=0; j--){
        if(up[u][j]!=up[v][j]){
            ans+=2*pow(2,j);
            u=up[u][j],v=up[v][j];
        }
    }
    return ans+2;
}
int main(){
    cin>>n;
    adj.resize(n);
    l = bit_width(n);
    up.resize(n,vector<int>(l+1));
    depth.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth[0]=0;
    dfs(0,0);
}
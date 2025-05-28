#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> entryval;
int maxdepth=0;
vector<int> depth;
int n,k;
vector<bool> visited;
vector<vector<int>> up;
void dfs(int i=0, int p=0){
    depth[i]=depth[p]+1;
    maxdepth=max(maxdepth,depth[i]);
    up[i][0]=p;
    for(int j=1; j<20; j++){
        up[i][j]=up[up[i][j-1]][j-1];
    }
    for(auto& j:adj[i])if(j!=p)dfs(j,i);
}
int lca(int a, int b){
    int d = depth[b]-depth[a];
    for(int i=0; i<20 ;i++){
        if((d>>i)&1)b=up[b][i];
    }
    if(a==b)return a;
    for(int i=19; i>=0; i--){
        if(up[a][i]!=up[b][i])a=up[a][i],b=up[b][i];
    }
    return up[a][0];
}
int ans=0;
int main(){
    freopen("maxflow.in","r", stdin);
    freopen("maxflow.out","w",stdout);
    cin>>n>>k;
    visited.resize(n,false);
    up.resize(n,vector<int>(21));
    adj.resize(n);
    depth.resize(n,-1);
    entryval.assign(n,0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    dfs();
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        if(depth[a]>depth[b])swap(a,b);
        int l=lca(a,b);
        if(l!=0)entryval[up[l][0]]--;
        entryval[l]--;
        entryval[a]++;
        entryval[b]++;
    }
    vector<int> p(n);iota(p.begin(),p.end(),0);
    vector<int> val(n,0);
    sort(p.begin(),p.end(),[&](int i, int j){return depth[i]>depth[j];});
    for(auto& i:p){
        for(auto& j:adj[i])if(j!=up[i][0]){
            val[i]+=val[j];
        }
        val[i]+=entryval[i];
        ans=max(ans,val[i]);
    }
    cout<<ans;
}
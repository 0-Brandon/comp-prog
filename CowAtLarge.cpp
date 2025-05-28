#include <bits/stdc++.h>

using namespace std;
vector<int> depth;
void dfs(int i, int p, vector<vector<int>>& adj){
    for(auto& c:adj[i])if(c!=p){
        depth[c]=depth[i]+1;
        dfs(c,i,adj);
    }
}
vector<int> mld;
vector<int> deg;
vector<int> numg;
void dfs2(int i, int p, vector<vector<int>>& adj){
    if(deg[i]==1){
        numg[i]=1;
        mld[i]=i;
    }
    else{
        int s = 0;
        bool flag= false;
        for(auto& c:adj[i])if(c!=p){
            dfs2(c,i,adj);
            s+=numg[c];
            if(numg[c]==1&&mld[c]!=1e8&&depth[mld[c]]-depth[i]<=depth[i]){
                flag = true;
                numg[i]=1;
                if(mld[i]==1e8||depth[mld[c]]<depth[mld[i]])mld[i]=mld[c];
            }
        }
        if(!flag){
            numg[i]=s;
        }
    }
}
int main(){
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    int n, k;
    cin>>n>>k;
    k--;
    vector<vector<int>> adj(n);
    depth.resize(n,0);
    mld.resize(n,1e8);
    numg.resize(n);
    deg.resize(n,0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    dfs(k,k,adj);
    dfs2(k,k,adj);
    cout<<numg[k];
}
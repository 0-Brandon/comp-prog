#include <bits/stdc++.h>

using namespace std;
//also works for 920E - "connected components?"
struct DSU{
    vector<int> e;
    DSU(int n):e(n,-1){};
    int par(int a) {return e[a]<0?a:e[a]=par(e[a]);}
    int get(int a) {return -e[par(a)];}
    bool merge(int a, int b){
        a=par(a),b=par(b);
        if(a==b) return false;
        if(e[a]>e[b]) swap(a,b);
        e[a]+=e[b];
        e[b]=a;
        return true;
    }
};
int main(){
    int n, m;
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> ind(n,n);
    DSU dsu(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
        ind[a]--,ind[b]--;
    }
    int lol=-1;
    for(int i=0; i<n; i++){
        if(ind[i]>n/2){
            if(lol<0)lol=i;
            else dsu.merge(lol,i);
            continue;
        }
        sort(adj[i].begin(),adj[i].end());
        int idx=0;
        for(int j=0; j<n; j++){
            if(idx<adj[i].size()&&adj[i][idx]==j){
                idx++;
                continue;
            }
            dsu.merge(i,j);
        }
    }
    vector<vector<int>> ans(n);
    vector<bool> vis(n);
    int nm=0;
    for(int i=0; i<n; i++){
        if(!vis[dsu.par(i)])vis[dsu.par(i)]=++nm;
        ans[dsu.par(i)].push_back(i);
    }
    cout<<nm<<"\n";
    for(auto& i:ans){
        if(i.size()){
            cout<<i.size()<<" ";
            for(auto& j:i)cout<<j+1<<" ";
            cout<<"\n";
        }
    }
}
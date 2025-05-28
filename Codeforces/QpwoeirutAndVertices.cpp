#include <bits/stdc++.h>
//first attempt with Kruskal reconstruction tree, doesn't work
using namespace std;
vector<vector<int>> adj;
int id = 0;
struct Segtree{
    int n;
    vector<int> e;
    function<bool(int a, int b)> cmb;
    Segtree(vector<int>& x, auto f):n(x.size()),e(2*n){
        cmb=[&](int a, int b){return f(e[a],e[b])?a:b;};
        for(int i=n; i<2*n; i++){
            e[i]=x[i];
        }
        for(int i=n-1; i>0; i--)e[i]=e[i*2]+e[i*2+1];
    }
    int query(int l, int r){
        int ans = e[r+=n];
        for(l+=n;l<r; l/=2,r/=2){
            if(l&1)ans = cmb(ans,l++);
            if(r&1)ans = cmb(ans,--r);
        }
        return ans;
    }
};
struct KSU{
    vector<int> e;
    KSU(int n):e(2*n){iota(e.begin(),e.end(),0);}
    int par(int a){return e[a]==a?a:e[a]=par(e[a]);}
    bool merge(int a, int b){
        a=par(a), b= par(b);
        if(a==b)return false;
        e[a] = e[b]=e[id]=id;
        adj.push_back(vector<int>{a,b});
        id++;
        return true;
    }
};
int n;
int timer = 0;
vector<int> tin(2*n), depth(2*n,-1);
vector<vector<int>> up(2*n,vector<int>(20,0));
void dfs(int i=id, int p = id){
    tin[i]=timer++;
    depth[i] = depth[p]+1;
    up[i][0]=p;
    for(int j=1; j<20 ;j++){
        up[i][j] = up[up[i][j-1]][j-1];
    }
    for(auto& c:adj[i])dfs(c,i);
}
int lca(int a, int b){
    if(depth[b]<depth[a])swap(a,b);
    int d = depth[b]-depth[a];
    for(int i=0; i<20 ;i++)if(d&(1<<i))b=up[b][i];
    if(a==b)return a;
    for(int i=19; i>=0; i--)if(up[a][i]!=up[b][i])a=up[a][i],b=up[b][i];
    return up[a][0];
}
int main(){
    int m, q;
    cin>>n>>m>>q;
    vector<pair<int,int>> edges;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        edges.push_back({a+n,b+n});
    }
    KSU ksu(n);
    for(auto& i:edges){
        ksu.merge(i.first,i.second);
    }
    id--;
    dfs();
    Segtree iseg(tin,function<bool(int,int)>([&](int a, int b){return a<b;}));
    Segtree aseg(tin,function<bool(int,int)>([&](int a, int b){return a>b;}));
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        int r = aseg.query(a+n,b+n);
        int l = iseg.query(a+n,b+n);
        cout<<lca(l,r)<<"\n";
    }
}
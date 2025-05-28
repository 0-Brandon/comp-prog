#include <bits/stdc++.h>

using namespace std;
struct edge{
    int u, v, w;
    edge(int a, int b, int c):u(a),v(b),w(c){}
    bool operator>(edge& e){
        return w>e.w;
    }
};
struct DSU{
    vector<int> e;
    DSU(int n):e(n,-1){};
    int par(int a) {return e[a]<0?a:e[a]=par(e[a]);}
    int get(int a) {return -e[par(a)]-1;}
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
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n, qu;
    cin>>n>>qu;
    vector<edge> edges;
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        edges.emplace_back(a,b,c);
    }
    sort(edges.begin(),edges.end(),[&](edge&x, edge& y){return x.w>y.w;});
    DSU dsu(n);
    vector<tuple<int,int,int>> q;
    for(int i=0; i<qu; i++){
        int a, b;
        cin>>a>>b;
        b--;
        q.emplace_back(a,b,i);
    }
    vector<int> ans(qu);
    int idx = 0;
    sort(q.begin(),q.end(),greater<tuple<int,int,int>>());
    for(auto& [cost, node, index]:q){
        while(idx<edges.size()&&edges[idx].w>=cost){
            dsu.merge(edges[idx].u, edges[idx].v);
            idx++;
        }
        ans[index] = dsu.get(node);
    }
    for(int i=0; i<qu; i++){
        cout<<ans[i]<<"\n";
    }
}
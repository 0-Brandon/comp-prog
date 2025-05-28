#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e,c;
    DSU(int n):e(n,-1),c(n,0){}
    int par(int a){
        if(e[a]<0)return a;
        int r = par(e[a]);
        c[a] ^= c[e[a]];
        e[a] = r;
        return e[a];
    }
    bool merge(int a, int b){
        int pa = par(a),pb=par(b);
        if(pa==pb)return c[a]!=c[b];
        if(e[pa]>e[pb])swap(pa,pb);
        e[pa]+=e[pb];
        e[pb] = pa;
        c[pb] = c[a]^c[b]^1;
        return true;
    }
};
int main(){
    int n, m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    DSU dsu(n);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end(),[&](auto i, auto j){return i[2]>j[2];});
    for(auto& [a,b,c]:edges){
        if(!dsu.merge(a,b)){cout<<c<<"\n";return 0;}
    }
    cout<<"0\n";
}
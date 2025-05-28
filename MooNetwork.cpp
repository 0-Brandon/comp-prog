#include <bits/stdc++.h>

using namespace std;
using namespace std;
struct edge{
    long long u, v, w;
    edge(long long a, long long b, long long c):u(a),v(b),w(c){}
    bool operator<(edge& e){
        return w<e.w;
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
    int n;
    cin>>n;
    vector<tuple<int,int,int>> x;
    vector<edge> edges;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x.emplace_back(a,b,i);
    }
    sort(x.begin(),x.end());
    vector<pair<int,int>> closey(11, {INT_MAX,INT_MAX});
    for(int i=0; i<n; i++){
        for(int j=0; j<11; j++){
            if(closey[j].second==INT_MAX) continue;
            edges.emplace_back(get<2>(x[i]),closey[j].second, 1LL*(j-get<1>(x[i]))*(j-get<1>(x[i])) +  1LL* (closey[j].first-get<0>(x[i]))*(closey[j].first-get<0>(x[i])));
        }
        closey[get<1>(x[i])]={get<0>(x[i]),get<2>(x[i])};
    }
    sort(edges.begin(),edges.end());
    DSU dsu(n);
    long long ans = 0;
    int count  = 0;
    for(auto& i:edges){
        if(dsu.merge(i.u,i.v)){
            ans+=i.w;
            count++;
        }
        if(count ==n-1) break;
    }
    cout<<ans;

}
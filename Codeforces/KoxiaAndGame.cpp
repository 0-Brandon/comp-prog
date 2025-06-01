#include <bits/stdc++.h>
#define int long long
constexpr int mod = 998244353;
using namespace std;


int t;
vector<bool> self;
struct DSU{
    vector<int> e, edge;
    DSU(int n):e(n,-1),edge(n,0){}
    int par(int i){return e[i]<0?i:e[i]=par(e[i]);}
    bool merge(int a, int b){
        a = par(a),b = par(b);
        if(a==b)return false;
        if(e[a]<e[b])swap(a,b);//size of a is smaller
        e[a]+=e[b];
        e[b] = a;
        edge[a]+=edge[b];
        self[a]=self[a]|self[b];
        return true;
    }
};
void solve(){
    int n;
    cin>>n;
    n++;
    self.assign(n,false);
    vector<int> a(n),b(n);
    DSU dsu(n);
    n--;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=n; i++)cin>>b[i];
    for(int i=1; i<=n; i++){
        dsu.merge(a[i],b[i]);
        dsu.edge[dsu.par(a[i])]++;
        if(a[i]==b[i])self[dsu.par(a[i])]=true;
    }
    int ans = 1;
    vector<bool> vis(n,false);
    for(int i=1; i<=n; i++)if(!vis[dsu.par(i)]){
        if(dsu.edge[dsu.par(i)] != -dsu.e[dsu.par(i)])ans = 0;
        else ans=ans*(self[dsu.par(i)]?n:2)%mod;
        vis[dsu.par(i)]=true;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}


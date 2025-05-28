#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, p;cin>>n>>m>>p;
    vector<bool> spec(2*n);
    for(int i=0; i<p; i++){
        int a;cin>>a;a--;
        spec[a] = true;
    }
    vector<array<int,3>> edges;
    for(int i=0; i<m; i++){
        int  a, b, c;cin>>a>>b>>c;
        a--,b--;
        edges.push_back({c,a,b});
    }
    vector<vector<int>> adj(2*n);
    vector<int> par(2*n);
    iota(par.begin(),par.end(),0);
    int id = n-1;
    sort(edges.begin(),edges.end());
    vector<int> w(2*n);
    auto f = [&](auto&& f, int i)->int {
        return i==par[i]?i:par[i]=f(f,par[i]);
    };
    auto unite = [&](int i, int j, int c){
        i=f(f,i),j=f(f,j);
        if(i==j)return false;
        id++;
        par[i]=par[j]=par[id]=id;
        w[id]=c;
        adj[id]={i,j};
        return true;
    };
    for(auto& [c,i,j]:edges){
        unite(i,j,c);
    }
    vector<int> sub(2*n);
    vector<int> val(2*n);
    vector<int> pref(2*n);
    vector<int> trace(2*n);
    vector<int> h(2*n);
    auto dfs = [&](auto&& dfs, int i, int p)->int {
        sub[i] = spec[i];
        trace[i]=i;
        for(auto& c:adj[i])if(c!=p){
            dfs(dfs,c,i);
            sub[i]+=sub[c];
            if(trace[i]==i||pref[c]<pref[i]){
                trace[i]=trace[c];
                pref[i]=pref[c];
            }
        }
        val[i] = sub[i]*(w[i]-w[p]);
        if(i==id)val[i] = sub[i]*w[i];
        pref[i]+=val[i];
        h[trace[i]]=i;
        return sub[i];
    };
    dfs(dfs,id, id);
    

    vector<int> hs;
    for(int i=0; i<n; i++){
        if(h[i]!=id)hs.push_back(pref[h[i]]);
    }
    
    sort(hs.begin(),hs.end());
    int ans = pref[id];
    for(int i=0; i<n-1; i++){
        cout<<ans<<" ";
        ans+=hs[i];
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}
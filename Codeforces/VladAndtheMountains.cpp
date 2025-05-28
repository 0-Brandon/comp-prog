#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        edges.push_back({max(h[--a],h[--b]),{a,b}});
    }
    sort(edges.begin(),edges.end());
    vector<vector<int>> s(n);
    vector<vector<pair<int,int>>> p(n);
    for(int i=0; i<n; i++){
        s[i].push_back(i);
        p[i].push_back({0,i});
    }
    for(auto& [i,pa]:edges){
        auto[u,v]=pa;
        u=p[u].back().second;
        v=p[v].back().second;
        if(u==v)continue;
        if(s[u].size()<s[v].size())swap(u,v);
        for(auto& j:s[v]){
            s[u].push_back(j);
            p[j].push_back({i,u});
        }
    }
    int q;cin>>q;
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        int ap = prev(upper_bound(p[a].begin(),p[a].end(),make_pair(c+h[a],INT_MAX)))->second;
        int bp = prev(upper_bound(p[b].begin(),p[b].end(),make_pair(c+h[a],INT_MAX)))->second;
        cout<<(ap==bp?"YES":"NO")<<"\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
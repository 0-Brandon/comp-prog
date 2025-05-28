#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n);
    vector<int> md(n);
    vector<vector<int>> rev(n+1);//rev stores deepest depth
    vector<vector<int>> rd(n+1);//rd stores normal depth
    depth[0]=0;
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        md[i]=depth[i];
        for(auto& c:adj[i])if(c!=p){
            depth[c] = depth[i]+1;
            dfs(dfs,c,i);
            md[i] = max(md[c],md[i]);
        }
        rev[md[i]].push_back(i);
        rd[depth[i]].push_back(i);
    };
    dfs(dfs,0,0);
    int cur = n;
    int ans = n;
    for(int i=n-1; i>=0; i--){
        for(auto& c:rev[i]){
            cur--;
        }
        for(auto& c:rd[i+1]){
            cur++;
        }
        ans = min(ans,cur);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
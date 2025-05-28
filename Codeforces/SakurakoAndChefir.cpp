#include <bits/stdc++.h>

using namespace std;
//sakurako and chefir
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> depth(n);
    vector<int> m(n,0),m2(n,0);
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        vector<int> ch;
        for(auto& c:adj[i]){
            if(c!=p){
                depth[c] = depth[i]+1;
                dfs(dfs,c,i);
                ch.push_back(m[c]+1);
            }
        }
        sort(ch.rbegin(),ch.rend());
        if(ch.size()>0)m[i] = ch[0];
        if(ch.size()>1)m2[i] = ch[1];
    };
    dfs(dfs,0,0);
    vector up(31,vector<int>(n));
    vector ma(31, vector<int>(n));
    auto dfs2 = [&](auto&& dfs2, int i, int p)->void {
        up[0][i] = p;
        for(int j=1;j<31;j++){
            up[j][i] = up[j-1][up[j-1][i]];
        }
        if(m[i]+1==m[p]){
            ma[0][i] = m2[p]-depth[p];
        }
        else{
            ma[0][i] = m[p]-depth[p];
        }
        for(int j=1; j<31; j++){
            ma[j][i] = max(ma[j-1][i],ma[j-1][up[j-1][i]]);
        }
        for(auto& c:adj[i]){
            if(c!=p){
                dfs2(dfs2,c,i);
            }
        }
    };
    dfs2(dfs2,0,0);
    int q;
    cin>>q;
    while(q--){
        int v, k;
        cin>>v>>k;
        v--;
        int p = v;
        k = min(k,depth[v]);
        int ans = m[v];
        for(int i=30; i>=0; i--){
            if(k&(1<<i)){
                ans = max(ans,depth[v]+ma[i][p]);
                p = up[i][p];
            }
        }
        cout<<ans<<" ";
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
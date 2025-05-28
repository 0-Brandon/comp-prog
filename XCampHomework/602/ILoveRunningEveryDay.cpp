#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj,up,a1,a2,r1,r2;
vector<int> d,c1,c2,w,ans;
constexpr int LOG = 20, OFF = 300005;
void dd(int i, int p=0){
    up[i][0] = p;
    for(int j=1; j<LOG; j++){
        up[i][j] = up[up[i][j-1]][j-1];
    }
    for(auto& c:adj[i])if(c!=p){
        d[c] = d[i]+1;
        dd(c,i);
    }
}
int lca(int a, int b){
    if(d[a]>d[b])swap(a,b);
    for(int i=LOG-1; i>=0; i--)if(d[up[b][i]]>=d[a])b = up[b][i];
    if(a==b)return a;
    for(int i=LOG-1; i>=0; i--)if(up[a][i]!=up[b][i])a=up[a][i],b = up[b][i];
    return up[a][0];
}
void dfs(int i, int p){
    int s1 = c1[w[i]+d[i]], s2 = c2[w[i]-d[i]+OFF];
    for(auto& j:a1[i])c1[j]++;
    for(auto& j:r1[i])c1[j]--;
    for(auto& j:a2[i])c2[j+OFF]++;
    for(auto& j:r2[i])c2[j+OFF]--;
    for(auto& c:adj[i])if(c!=p)dfs(c,i);
    ans[i] = c1[d[i]+w[i]]-s1+c2[w[i]-d[i]+OFF]-s2;
}
int main(){
    int n,m;
    cin>>n>>m;
    ans.resize(n);
    a1.resize(n);
    a2.resize(n);
    r1.resize(n);
    r2.resize(n);
    c1.resize(2*OFF);
    c2.resize(2*OFF);
    w.resize(n);
    adj.resize(n);
    d.resize(n);
    up.resize(n,vector<int>(LOG));
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dd(0);
    for(int i=0; i<n; i++)cin>>w[i];
    for(int i=0; i<m; i++){
        int s, t;
        cin>>s>>t; s--,t--;
        int l = lca(s,t);
        a1[s].push_back(d[s]);
        if(up[l][0]!=l)r1[up[l][0]].push_back(d[s]);
        a2[t].push_back(d[s]-2*d[l]);
        r2[l].push_back(d[s]-2*d[l]); //no overcount lca
    }
    dfs(0,0);
    for(auto& i:ans)cout<<i<<" ";
}
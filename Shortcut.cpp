#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<int> c;
int ans = 0;
vector<vector<pair<int,int>>> adj;
vector<int> par;
vector<int> sub;
vector<int> dist;
int n, m, t;
vector<vector<int>> tadj;
void dfs(int i = 0, int p=0){
    sub[i]=c[i];
    for(auto& d:tadj[i]){
        if(d==p)continue;
        dfs(d,i);
        sub[i]+=sub[d];
    }
    ans = max(ans, sub[i]*dist[i]-sub[i]*t);
}
signed main(){
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m>>t;
    dist.resize(n,INT_MAX);
    adj.resize(n);
    sub.resize(n,0);
    c.resize(n);
    tadj.resize(n);
    par.resize(n,INT_MAX);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    for(int i=0; i<m;  i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    dist[0]=0;
    par[0]=0;
    q.push({0,0});
    while(!q.empty()){
        auto [cdist,cur] = q.top();
        q.pop();
        if(cdist != dist[cur])continue;
        for(auto& [i,cost]:adj[cur]){
            if((cost+dist[cur]<dist[i])||(cost+dist[cur]==dist[i]&&cur<par[i])){
                par[i] = cur;
                q.push({dist[i]=dist[cur]+cost, i});
            }
        }
    }
    for(int i=1; i<n; i++){
        tadj[i].push_back(par[i]);
        tadj[par[i]].push_back(i);
    }
    dfs();
    cout<<ans<<"\n";
}
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> x;
vector<vector<int>> up;
vector<vector<int>> rem, add;
vector<int> depth, ans;
vector<int> query;
vector<vector<pair<int,int>>> ncur;
constexpr int LOG = 20;
void dfs(int i, int p = 0){
    up[i][0]=p;
    for(int j=1; j<LOG; j++){
        up[i][j] = up[up[i][j-1]][j-1];
    }
    for(auto& c:adj[i]){
        if(c==p)continue;
        depth[c] = depth[i]+1;
        dfs(c,i);
    }
}
int lca(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    int d = depth[b]-depth[a];
    for(int i=0; i<LOG; i++)if((d>>i)&1)b = up[b][i];
    if(a==b)return a;
    for(int i = LOG-1; i>=0; i--)if(up[a][i]!=up[b][i]){
        a = up[a][i];
        b = up[b][i];
    }
    return up[a][0];
}
void merge(vector<pair<int,int>>& a, vector<pair<int,int>>& b){
    if(a.size()<b.size())swap(a,b);
    for(auto& i:b)a.insert(lower_bound(a.begin(),a.end(),i),i);
}
void dfs2(int i, int p){
    vector<pair<int,int>>& cur=ncur[i];
    for(auto& ad:add[i])cur.insert(lower_bound(cur.begin(),cur.end(),make_pair(query[ad],ad)),make_pair(query[ad],ad));
    for(auto& c:adj[i])if(c!=p){
        dfs2(c,i);
        merge(cur,ncur[c]);
    }
    while(true){
        auto it = lower_bound(cur.begin(),cur.end(),make_pair(x[i],INT_MIN));
        if(it==cur.end()||it->first!=x[i])break;
        ans[it->second]=true;
        cur.erase(it);
    }
    for(auto& rid:rem[i]){
        for(int lol=0; lol<2; lol++){
        auto id = lower_bound(cur.begin(),cur.end(),make_pair(query[rid],rid));
        if((*id)==make_pair(query[rid],rid)){
            cur.erase(id);
        }
        }
    }
}
int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    x.resize(n);
    rem.resize(n);
    ncur.resize(n);
    add.resize(n);
    adj.resize(n);
    up.resize(n,vector<int>(LOG));
    depth.resize(n);
    ans.resize(m,0);
    query.resize(m);
    depth[0] = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
    }
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--,c--;
        query[i] = c;
        rem[lca(a,b)].push_back(i);
        add[a].push_back(i);
        add[b].push_back(i);
    }
    dfs2(0,0);
    for(auto& i:ans)cout<<i;
}
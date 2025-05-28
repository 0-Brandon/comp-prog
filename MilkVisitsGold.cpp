#include <bits/stdc++.h>

//pref requires too much memory
using namespace std;
vector<int> idx;
vector<unordered_map<int,int>> pref;
vector<int> depth;
vector<vector<int>> up;
vector<int> x;
vector<int> tour;
int timer = 0;
void dfs(int i, int p, vector < vector < int >> & adj) {
    tour.push_back(i);
    pref[i]=pref[p];
    pref[i][x[i]]++;
    idx[i]=timer++;
    for (auto & c: adj[i]) {
        if (c == p) continue;
        depth[c]=depth[i]+1;
        dfs(c, i, adj);
        tour.push_back(i);
        idx[i]=timer++;
    }
}
int lca(int a, int b){
    a = idx[a],b=idx[b];
    if(b<a)swap(a,b);
    int w = 31-__builtin_clz(b-a+1);
    return (depth[up[w][a]]<depth[up[w][b-(1<<w)+1]])
    ?(up[w][a])
    :(up[w][b-(1<<w)+1]);
}
string query(int a, int b, int choice){
    if(x[a]==choice||x[b]==choice)return "1";
    int la = lca(a,b);
    if(x[la]==choice)return "1";
    if(pref[a][choice]-pref[la][choice]>0||
    pref[b][choice]-pref[la][choice]>0)return "1";
    return "0";
}
int main() {
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    pref.resize(n+5);
    idx.resize(n+5);
    depth.resize(n+5,0);
    x.resize(n+5);
    vector < vector < int >> adj(n+5);
    for(int i=0; i<n; i++)cin>>x[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0, adj);
    up={vector<int>(timer,0)};
    for(int i=0; i<timer; i++){
        up[0][i]=tour[i];
    }
    for(int j=1; 1<<j<=timer; j++){
        up.push_back(vector<int>(timer-(1<<j)+1));
        for(int i=0; i<up[j].size(); i++){
            if(depth[up[j-1][i]]<=depth[up[j-1][i+(1<<(j-1))]]){
                up[j][i]=up[j-1][i];
            }
            else{
                up[j][i]=up[j-1][i+(1<<(j-1))];
            }
        }
    }
    string ans = "";
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        ans+=query(--a,--b,c);
    }
    cout<<ans;
}

/*
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> up,adj;
vector<int> depth, x;
int l, n;
void dfs(int i, int p){
    pref[i]=pref[p];
    pref[i][x[i]]++;
    up[i][0]=p;
    for(int k=1; k<l; k++){
        up[i][j]=up[up[i][j-1]][j-1];
    }
    for(auto& child:adj[i]){
        if(p==child)continue;
        depth[child]=depth[i]+1;
        dfs(child,i);
    }
}
int lca(int u, int v){
    if(depth[u]>depth[v])swap(u,v);
    for(int j=l-1; j>=0; j--){
        if(depth[up[v][j]]>depth[u]){
            v=up[v][j];
        }
    }
    if(u==v)return u;
    v=up[v][0];
    if(u==v) return v;
    for(int j=l-1; j>=0; j--){
        if(up[u][j]!=up[v][j]){
            u=up[u][j],v=up[v][j];
        }
    }
    u=up[u][0];
    return u;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   freopen("milkvisits.in","r",stdin);
   freopen("milkvisits.out","w",stdout);
    int n, m;
    cin >> n >> m;
    x.resize(n,0); // max index is n
    adj.resize(n); // max index is n
    depth.resize(n,0); // 
    
    up.resize(n, vector<int>(l+1));// n nodes, max ancestor is l 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,0);
    string ans = "";
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        ans+=query(--a,--b,c);
    }
    cout<<ans;
}
*/

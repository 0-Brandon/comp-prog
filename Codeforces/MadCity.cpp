#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> depth;
int eld = -1;
int el = -1;
void dfs(int i, int p){
    if(visited[i])return;
    visited[i]=true;
    depth[i]=depth[p]+1;
    for(auto& c:adj[i]){
        if(c!=p&&visited[c]){
            el = c;
            eld = depth[el];
        }
        if(!visited[c])dfs(c,i);
        if(el!=-1)return;
    }
}
void solve(){
    el = eld = -1;
    int n, a, b;
    cin>>n>>b>>a;
    a--,b--;
    visited.assign(n,0);
    adj.assign(n,vector<int>());
    depth.assign(n,0);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b; a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    depth[a]=-1;
    dfs(a,a);
    visited.assign(n,0);
    vector<int> bdepth(n,INT_MAX);
    queue<int> q;
    q.push(b);
    bdepth[b]=0;
    while(!q.empty()){
        int cur = q.front();
        visited[cur] = true;
        q.pop();
        for(auto& c:adj[cur]){
            if(!visited[c]){
                q.push(c);
                bdepth[c] = min(bdepth[c],bdepth[cur]+1);
                if(c==el)break;
            }
        }
    }
    if(bdepth[el]<=eld)cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> c(n),s(n), f(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
        c[i]--;
    }
    for(int i=0; i<n; i++){
        cin>>s[i];
        s[i]--;
    }
    for(int i=0; i<n; i++){
        cin>>f[i];
        f[i]--;
    }
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    vector<bool> visited(n,false), bn(n,false);
    vector<int> h(n,0);
    vector<int> l(n,-1);
    vector<int> pt(n,-1);
    q.push(0);
    while(!q.empty()){
        int i = q.front();q.pop();
        h[s[i]]=true;
        bn[i]=true;
        for(auto& ch:adj[i]){
            if(visited[ch])continue;
            visited[ch]=true;
            if(h[c[ch]]){
                q.push(ch);
            }
            else{
                pt[ch] = l[c[ch]];
                l[c[ch]]=ch;
            }
        }
        int cur = l[s[i]];
        while(cur!=-1){
            q.push(cur);
            cur = pt[cur];
        }
        l[s[i]]=-1;
    }
    for(int i=0; i<n; i++)if(!bn[i]&&s[i]!=f[i]){cout<<"NO\n";return;}
    visited.assign(n,0);
    h.assign(n,0);
    l.assign(n,-1);
    pt.assign(n,-1);
    vector<bool> obn(n,false);
    q.push(0);
    while(!q.empty()){
        int i = q.front();q.pop();
        h[f[i]]=true;
        obn[i]=true;
        for(auto& ch:adj[i]){
            if(visited[ch]||!bn[i])continue;
            visited[ch]=true;
            if(h[c[ch]]||c[ch]==f[ch]){
                q.push(ch);
            }
            else{
                pt[ch] = l[c[ch]];
                l[c[ch]]=ch;
            }
        }
        int cur = l[f[i]];
        while(cur!=-1){
            q.push(cur);
            cur = pt[cur];
        }
        l[f[i]]=-1;
    }
    for(int i=0; i<n; i++)if(bn[i]&&!obn[i]){cout<<"NO\n";return;}
    cout<<"YES\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
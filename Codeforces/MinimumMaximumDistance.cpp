#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> m(n,0);
    vector<vector<int>> adj(n);
    vector<int> dist(n,-1);
    for(int i=0; i<k; i++){
        int a;
        cin>>a;
        a--;
        m[a] = true;
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int node=0;
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(auto& c:adj[i]){
            if(dist[c]==-1){
                q.push(c);
                dist[c] = dist[i]+1;
                if(dist[c]>dist[node]&&m[c])node = c;
            }
        }
    }
    vector<int> ndist(n,-1);
    q.push(node);
    ndist[node] = 0;
    int nnode= node;
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(auto& c:adj[i]){
            if(ndist[c]==-1){
                q.push(c);
                ndist[c] = ndist[i]+1;
                if(ndist[c]>ndist[nnode]&&m[c])nnode = c;
            }
        }
    }
    cout<<(ndist[nnode]+1)/2<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

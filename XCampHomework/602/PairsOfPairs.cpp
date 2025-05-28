#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<vector<int>> aadj(n),adj(n);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;a--,b--;
        aadj[a].push_back(b);
        aadj[b].push_back(a);
    }

    vector<bool> vis(n);
    vector<int> depth(n);
    vis[0]=true;
    depth[0]=0;
    vector<vector<int>> depths(n);
    auto dfs = [&](auto&& dfs, int i)->void {
        depths[depth[i]].push_back(i);
        for(auto& c:aadj[i]){
            if(!vis[c]){
                depth[c] = depth[i]+1;
                adj[i].push_back(c);
                adj[c].push_back(i);
                vis[c]=true;
                dfs(dfs, c);
            }
        }
    };
    dfs(dfs,0);
    //find longest path, if its long enough, we are done
    //else pair nodes of the same level
    vector<int> dist(n,-1);
    dist[0]=0;
    queue<int> q;
    int start = 0;
    q.push(0);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(auto& c:adj[i]){
            if(dist[c]==-1){
                dist[c]=dist[i]+1;
                if(dist[c]>dist[start])start=c;
                q.push(c);
            }
        }
    }
    q.push(start);
    dist.assign(n,-1);
    dist[start]=0;
    int end = 0;
    vector<int> par(n,-1);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        for(auto& c:adj[i]){
            if(dist[c]==-1){
                dist[c] = dist[i]+1;
                par[c]=i;q.push(c);
                if(dist[c]>dist[end])end = c;
            }
        }
    }
    if(dist[end]>=(n+1)/2){
        cout<<"PATH\n";
        vector<int> ans;
        while(end!=-1){
            ans.push_back(end);
            end = par[end];
        }
        cout<<ans.size()<<"\n";
        for(auto& i:ans)cout<<i+1<<" ";cout<<"\n";
    }else{
        cout<<"PAIRING\n";
        vector<pair<int,int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<depths[i].size(); j+=2){
                if(j+1<depths[i].size())ans.push_back({depths[i][j],depths[i][j+1]});
            }
        }
        cout<<ans.size()<<"\n";
        for(auto& i:ans)cout<<i.first+1<<" "<<i.second+1<<"\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
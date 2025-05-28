#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> x(n);
    for(int i=0; i<n-1; i++)cin>>x[i+1];
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //possible b, c pairs
    vector<vector<bool>> pos(n,vector<bool>(n,false));
    //maybe need 3 edges if a==c or a==d
    vector<vector<int>> edge(n);
    auto bfs = [&](int s){
        queue<int> q;
        q.push(s);
        vector<int> dist(n,-1);
        dist[s]=0;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(i!=s){
                pos[s][i]=true;
                if(i!=0&&pos[0][i]){
                    //potential a/d
                    edge[s].push_back(i);
                    sort(edge[s].begin(),edge[s].end(),[&](int i, int j){return x[i]>x[j];});
                    if(edge[s].size()>3)edge[s].pop_back();
                }
            }
            if(dist[i]>k)continue;
            for(auto& c:adj[i])if(dist[c]==-1){
                dist[c] = dist[i]+1;
                q.push(c);
            }
        }
    };
    int ans = 0;
    for(int i=0; i<n; i++)bfs(i);
    for(int b=1; b<n; b++){
        for(int c=1; c<n; c++){
            if(pos[b][c]){
                for(auto& a:edge[b]){
                    for(auto& d:edge[c]){
                        if(a!=c&&a!=d&&d!=b)ans = max(ans,x[a]+x[b]+x[c]+x[d]);
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}

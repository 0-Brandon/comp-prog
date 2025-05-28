#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<tuple<int,int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        a--,c--;
        adj[a].emplace_back(b,c,d);
    }
    //start, end, time
    for(auto& i:adj){
        sort(i.rbegin(),i.rend());
    }
    vector<int> layovers;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        layovers.emplace_back(a);
    }
    vector<int> dist(n, INT_MAX);
    dist[0]=0;
    queue<tuple<int,int,int>> q;
    for(auto& i:adj[0]){
        q.push(i);
    }
    vector<int> idx(n,0);
    while(!q.empty()){
        auto[st,cur,et]=q.front();
        q.pop();
        dist[cur]=min(dist[cur],et);
        for(int i = idx[cur];i<adj[cur].size()&&get<0>(adj[cur][i])>=et+layovers[cur]; i++){
            q.push(adj[cur][i]);
            idx[cur]++;
        }
    }
    for(auto i:dist){
        if(i==INT_MAX) cout<<-1<<"\n";
        else cout<<i<<"\n";
    }
}
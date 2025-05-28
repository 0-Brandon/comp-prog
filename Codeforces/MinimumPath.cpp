#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m;cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<array<int,4>> pq;
    vector dist(n, vector (2,vector<int>(2,LLONG_MAX)));
    dist[0][0][0]=0;
    pq.push({0,0,0,0});
    //node, add, delete
    while(!pq.empty()){
        auto[d, i, add, del] = pq.top();
        pq.pop();
        if(-dist[i][add][del]!=d)continue;
        d = -d;
        for(auto& [c,v]:adj[i]){
            if(del==0&&d<dist[c][add][1]){
                dist[c][add][1] =d;
                pq.push({-d,c,add,1});
            }
            if(add==0&&d+2*v<dist[c][1][del]){
                dist[c][1][del] =d+2*v;
                pq.push({-(d+2*v),c,1,del});
            }
            if(add==0&&del==0&&d+v<dist[c][1][1]){
                dist[c][1][1] = d+v;
                pq.push({-(d+v),c,1,1});
            }
            if(d+v<dist[c][add][del]){
                dist[c][add][del] = d+v;
                pq.push({-(d+v),c,add,del});
            }
        }
    }
    for(int i=1; i<n; i++){
        cout<<dist[i][1][1]<<" ";
    }
}
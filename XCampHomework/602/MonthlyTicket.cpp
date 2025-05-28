#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[100000];
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m;cin>>n>>m;
    int s, t;
    int u, v;
    cin>>s>>t>>u>>v;s--,t--,u--,v--;
    for(int i=0; i<m; i++){
        int a, b,c;cin>>a>>b>>c;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    auto work = [&](int s, vector<long long>& dist){
        dist[s] = 0;
        priority_queue<pair<long long,int>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto[d,i] = pq.top();
            pq.pop();
            if(-d!=dist[i])continue;
            for(auto& [c,v]:adj[i]){
                if(dist[c]>dist[i]+v){
                    dist[c] = dist[i]+v;
                    pq.push({-dist[c],c});
                }
            }
        }
    };
    vector<long long> dist(n,1e17),adist(n,1e17),udist(n,1e17),bdist(n,1e17);
    work(v,dist);
    work(u,udist);
    work(s,adist);
    work(t,bdist);
    long long ans = udist[v];

    vector<long long> best(n,1e17);
    queue<int> q;
    q.push(t);
    vector<bool> vis(n);
    vector<int> nodes;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(vis[i])continue;
        nodes.push_back(i);
        vis[i]=true;
        for(auto& [c,v]:adj[i]){
            if(adist[i] == adist[c]+v){
                q.push(c);
            }
        }
    }
    sort(nodes.begin(),nodes.end(),[&](int i, int j){return adist[i]<adist[j];});
    for(auto& i:nodes){
        best[i] = udist[i];
        for(auto& [c,v]:adj[i]){
            if(adist[c]<adist[i]){
                best[i] = min(best[i],best[c]);
            }
        }
        ans = min(ans, dist[i]+best[i]);
    }
    nodes.clear();
    best.assign(n,1e17);
    best[s] = dist[s];
    q.push(s);
    vis.assign(n,false);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(vis[i])continue;
        nodes.push_back(i);
        vis[i]=true;
        for(auto& [c,v]:adj[i]){
            if(bdist[i] == bdist[c]+v){
                q.push(c);
            }
        }
    }
    sort(nodes.begin(),nodes.end(),[&](int i, int j){return bdist[i]<bdist[j];});
    for(auto& i:nodes){
        best[i] = udist[i];
        for(auto& [c,v]:adj[i]){
            if(bdist[c]<bdist[i]){
                best[i] = min(best[i],best[c]);
            }
        }
        ans = min(ans, dist[i]+best[i]);
    }
    cout<<ans<<"\n";
}
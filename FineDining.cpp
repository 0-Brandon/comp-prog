#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> yum, dist;
signed main(){
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    int n, m, k;
    cin>>n>>m>>k;
    adj.resize(n);
    yum.resize(n,-1);
    vector<int> left(n,INT_MAX);
    vector<int> yidx(n,-1);
    dist.resize(n,INT_MAX);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[--a].emplace_back(--b,c);
        adj[b].push_back({a,c});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> x2;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> x;
    x.push({0,n-1});
    dist[n-1]=0;
    while(!x.empty()){
        auto [di, cur] = x.top();
        x.pop();
        if(di>dist[cur])continue;
        for(auto& [c,ds]:adj[cur]){
            if(dist[c]>dist[cur]+ds){
                dist[c] = dist[cur]+ds;
                x.push(make_pair(dist[c],c));
            }
        }
    }
    for(int i=0; i<k; i++){
        int id, c;
        cin>>id>>c;
        yum[--id]=c;
        yidx[id] = id;
        left[id] = -yum[id]+dist[id];
        x2.push({left[id],id});
    }
    //sort x2 by greatest value of left
    //yidx is index of haybale we go to
    //dis is distance we travel extra to go to it
    //dis + dist[yidx] is final trvel distance
    //yum>dis + dist[yidx]-dist[i] to be worth
    //0 > dis+dist[yidx] - dist [i] - yum
    // minimize disfromitoyidx + dist[yidx] - dist[i] - yum
    //left is 
    while(!x2.empty()){
        auto[lef, i] = x2.top();
        x2.pop();
        if(lef>left[i])continue;
        for(auto& [c,ds]:adj[i]){
            if(left[i] + ds < left[c]){
                left[c] = left[i] + ds;
                yidx[c] = yidx[i];
                x2.push(make_pair(left[c], c));
            }
        }
    }
    for(int i=0; i<n-1; i++){
        cout<<(left[i]<=dist[i])<<"\n";
    }
}
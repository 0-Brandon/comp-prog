#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;
signed main(){
    int n, m, s, t;
    cin>>n>>m>>s>>t;
    s--,t--;
    vector<array<int,3>> edges;
    vector<vector<pair<int,int>>> adj(n),radj(n);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        edges.push_back({a,b,c});
        adj[a].push_back(make_pair(b,c));
        radj[b].push_back(make_pair(a,c));
    }
    vector<int> inds(n,0),indt(n,0);
    vector<int> dists(n,1e17);
    vector<int> distt(n,1e17);
    auto work = [&](int s,vector<int>& dist,vector<int>&ind, vector<vector<pair<int,int>>> & adj){
        ind[s]=1;
        dist[s] = 0;
        priority_queue<pair<int,int>> q;
        q.push(make_pair(dist[s],s));
        while(!q.empty()){
            auto[d,cur] = q.top();
            q.pop();
            if(-d!=dist[cur])continue;
            for(auto& [c,cost]:adj[cur]){
                if(dist[c]>dist[cur]+cost){
                    ind[c]=ind[cur];
                    dist[c] = dist[cur]+cost;
                    q.push(make_pair(-dist[c],c));
                }
                else if(dist[c]==dist[cur]+cost)ind[c]=(ind[c]+ind[cur])%mod;
            }
        }
    };
    work(s,dists,inds,adj);
    work(t,distt,indt,radj);
    for(auto& i:edges){
        int out = dists[i[0]]+distt[i[1]];
        if(out+i[2]==dists[t]&&(inds[i[0]]*indt[i[1]])%mod==inds[t])cout<<"YES\n";
        else if(out+i[2]-dists[t]+1>=i[2]){
            cout<<"NO\n";
            continue;
        }
        else cout<<"CAN "<<(out+i[2]-dists[t]+1)<<"\n";
    }

}
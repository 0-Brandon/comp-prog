#include <bits/stdc++.h>
#define int long long

using namespace std;
constexpr int mod = 1e9+7;
signed main(){
    int n, m;
    cin>>n>>m;
    vector<vector<array<int,3>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b,c;
        cin>>a>>b>>c;a--,b--;
        adj[a].push_back({b,c,i});
    }
    vector<int> ans(m);
    for(int s=0; s<n; s++){
        vector<int> dist(n,INT_MAX);
        dist[s] = 0;
        map<array<int,2>,bool> vis;
        priority_queue<array<int,4>> pq;
        vector<vector<pair<int,int>>> radj(n);
        vector<vector<int>> rradj(n);
        map<array<int,2>,int> num;
        pq.push({0,s,0,-1});
        while(!pq.empty()){
            auto[d,i,p,e] = pq.top();
            d=-d;
            pq.pop();
            if(d==dist[i]&&!vis[{i,e}]){
                vis[{i,e}] = true;
                radj[p].push_back({i,e});
                rradj[i].push_back(p);
            }
            else{
                continue;
            }
            for(auto& [c,w,l]:adj[i]){
                if(dist[i]+w<=dist[c]){
                    dist[c] = dist[i]+w;
                    pq.push({-dist[c],c,i,l});
                }
            }
        }
        vector<int> ord(n);
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](int i, int j){return dist[i]<dist[j];});
        vector<int> cnt(n);//number of paths that start here and go forward
        vector<int> back(n,0);
        for(auto& i:ord){
            for(auto& p:rradj[i]){
                back[i]+=back[p];
                back[i]%=mod;
            }
            back[i] = max(back[i],1LL);
        }
        reverse(ord.begin(),ord.end());
        for(auto& i:ord){
            for(auto& [c,l]:radj[i]){
                if(l==-1)continue;
                cnt[i]+=cnt[c];
                cnt[i]%=mod;
                ans[l]+=cnt[c]*max(1LL,back[i])%mod;
                ans[l]%=mod;
            }
            cnt[i]++;
        }
    }
    for(auto& i:ans)cout<<i<<"\n";
}
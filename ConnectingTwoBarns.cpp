#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> components;
vector<int> comp;
int compidx=0;
void dfs(int i, vector<vector<int>>& adj,vector<bool>& visited){
    if(visited[i]) return;
    visited[i]=true;
    components[compidx].push_back(i);
    comp[i]=compidx;
    for(auto& j:adj[i]){
        dfs(j,adj,visited);
    }
}
void solve(){
        cin>>n>>m;
        vector<vector<int>> adj(n);
        comp.resize(n,0);
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                components.push_back(vector<int>());
                dfs(i,adj,visited);
                compidx++;
            }
        }
        if(comp[0]==comp[n-1]){
            cout<<0<<"\n";
            return;
        }
        for(int i=0; i<compidx; i++){
            sort(components[i].begin(),components[i].end());
        }
        vector<long long> distto1(compidx,INT_MAX), distton(compidx,INT_MAX);
        int sidx=0,didx=0;
        for(int i=0; i<n; i++){
            while(sidx<components[comp[0]].size()){
                distto1[comp[i]]=min(distto1[comp[i]],abs(1LL*(i-components[comp[0]][sidx])));
                if(components[comp[0]][sidx]<i)sidx++;
                else break;
            }
            if(sidx)sidx--;
            while(didx<components[comp[n-1]].size()){
                distton[comp[i]]=min(distton[comp[i]],abs(1LL*(i-components[comp[n-1]][didx])));
                if(components[comp[n-1]][didx]<i)didx++;
                else break;
            }
            if(didx)didx--;
        }
        long long ans = distton[comp[0]]*distton[comp[0]];
        for(int i=0; i<compidx; i++){
            long long to1, ton;
            to1=distto1[i]*distto1[i];
            ton=distton[i]*distton[i];
            ans=min(ans, to1+ton);
        }
        cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
        components.clear();
        compidx=0;
    }
}
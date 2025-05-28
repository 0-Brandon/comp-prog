#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    for(int i=0; i<k; i++){
        int a;
        cin>>a;
        c[--a]=0;
    }
    vector<int> ind(n,0);
    vector<vector<int>> adj(n), radj(n);
    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        for(int j=0; j<m; j++){
            int a;
            cin>>a;
            a--;
            adj[a].push_back(i);
            radj[i].push_back(a);
            ind[i]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for(int i=0; i<n; i++)if(ind[i]==0)q.push(i);
    while(!q.empty()){
        int cur = q.front();q.pop();
        topo.push_back(cur);
        for(auto& c:adj[cur])if(--ind[c]==0)q.push(c);
    }
    vector<long long> ans(n,LLONG_MAX);
    for(auto& i:topo){
        ans[i]=c[i];
        long long t=0;
        for(auto& j:radj[i])t+=ans[j];
        if(radj[i].size()==0)t=LLONG_MAX;
        ans[i]=min(ans[i],t);
    }
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
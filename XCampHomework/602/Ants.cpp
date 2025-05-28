#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, g, k;
    cin>>n>>g>>k;
    vector<int> x(g);
    for(int i=0; i<g; i++)cin>>x[i];
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    int a, b;
    cin>>a>>b;a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    ind[a]++,ind[b]++;
    for(int i=0; i<n-2; i++){
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ind[a]++;
        ind[b]++;
    }
    vector<pair<int,int>> inv(n);
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        int d = adj[i].size()-1;
        for(auto& c:adj[i])if(c!=p){
            inv[c] = {d*inv[i].first, d*inv[i].second+d-1};
            dfs(dfs,c,i);
        }
    };
    inv[a] = {k,k};
    inv[b] = {k,k};
    dfs(dfs,a,b);
    dfs(dfs,b,a);
    vector<int> l,r;
    for(int i=0; i<n; i++)if(ind[i]==1){
        l.push_back(inv[i].first);
        r.push_back(inv[i].second);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int ans = 0;
    for(int i=0; i<g; i++){
        int id = upper_bound(l.begin(),l.end(),x[i])-l.begin();
        int rd = lower_bound(r.begin(),r.end(),x[i])-r.begin();
        int cnt = id-rd;
        if(cnt<0)cnt==0;
        ans+=k*(cnt);
    }
    cout<<ans<<"\n";
}
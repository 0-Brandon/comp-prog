#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> def(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        def[i]=x[i];
    }
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int t; cin>>t;t--;
        adj[i].push_back(t);
        adj[t].push_back(i);
    }
    int ans = 0;
    auto dd = [&](auto dd, int i, int p)-> void {
        for(auto& c:adj[i])if(c!=p){
            dd(dd,c,i);
     //       cout<<x[c]<<" "<<def[c]<<" "<<c<<"\n";
            def[i]-=def[c]+x[c];
        }
        if(adj[i].size()<=1&&i!=0)def[i]=0;
    };
    dd(dd,0,0);
    for(auto& i:def)cout<<i<<" ";
    auto dfs = [&](auto dfs, int i, int p)-> void {
        sort(adj[i].begin(),adj[i].end(),[&](int i, int j){return def[i]<def[j];}); //most free to most needed
        def[i] = max(0,def[i]);
        cout<<i<<"\n";
    for(auto& i:def)cout<<i<<" ";cout<<"\n";
        for(auto& c:adj[i])if(c!=p){
            if(def[c]<0){
                int ad = min(abs(def[c]),abs(def[i]));
                def[c]+=ad;
                x[c]+=ad;
                def[i]-=ad;
                ans+=ad;
            }
            else{
                def[c]+=def[i];
                x[c]+=def[i];
                ans+=def[i];
                def[i]=0;
            }
        }
        //1 0 0
        for(auto& c:adj[i])if(c!=p)dfs(dfs,c,i);
    };
    dfs(dfs,0,0);
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cur = 0;
    vector<int> sub(n);
    vector<int> ans(n);
    auto dfs = [&] (auto& dfs, int i, int p) ->void {
        sub[i] = a[i];
        ans[i] = 0;
        for(auto& c:adj[i]){
            if(c==p)continue;
            dfs(dfs,c,i);
            sub[i]+=sub[c];
            ans[i]+=ans[c]+sub[c];
        }
    };
    dfs(dfs,0,0);
    int aans = 0;
    auto dfs2 = [&] (auto& dfs2, int i, int p) ->void {
        aans = max(aans, ans[i]);
        for(auto& c:adj[i]){
            if(c==p)continue;
            ans[i]-=ans[c]+sub[c];
            sub[i]-=sub[c];
            ans[c]+=ans[i]+sub[i];
            sub[c]+=sub[i];
            dfs2(dfs2,c,i);
            sub[c]-=sub[i];
            ans[c]-=ans[i]+sub[i];
            ans[i]+=ans[c]+sub[c];
            sub[i]+=sub[c];
        }
    };
    dfs2(dfs2,0,0);
    cout<<aans<<" ";
}
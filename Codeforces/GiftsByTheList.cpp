#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> ind(n,0);
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        ind[b]++;
    }
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];x[i]--;
    }
    bool b =true;
    vector<int> ans;
    auto dfs = [&](auto dfs, int i, int p) -> void {
        if(x[i]!=x[p]&&x[i]!=i)b=false;
        for(auto& c:adj[i])if(c!=p){
            dfs(dfs,c,i);
        }
        if(x[i]==i)ans.push_back(i);
    };
    for(int i=0; i<n; i++){
        if(ind[i]==0)dfs(dfs,i,i);
    }
    if(!b)cout<<"-1\n";
    else{
        cout<<ans.size()<<"\n";
        for(auto& i:ans)cout<<i+1<<"\n";
    }
}
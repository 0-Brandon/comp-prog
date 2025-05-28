#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, c;char ch;
        cin>>a>>b>>ch;
        if(ch=='R')c=1;
        else c=0;
        adj[--a].push_back({--b,c});
        adj[b].push_back({a,c});
    }
    int ans=INT_MAX;
    int ccans = 0;
    vector<int> aans;
    vector<bool> visited(n,false);
    vector<int> vvis;
    vector<int> color(n,0);
    vector<int> cans;
    auto dfs = [&](auto dfs, int i, int p, int w)-> void {
        vvis.push_back(i);
        visited[i]= true;
        if(color[i])cans.push_back(i);
        for(auto& [child,cc]:adj[i]){
            if(visited[child]){
                if(color[child]^color[i]!=(cc^w))ccans=-1;
            }
            else{
                color[child] = color[i]^(cc^w);
                dfs(dfs,child,i,w);
            }
        }
    };
    vector<int> aaans;
    for(int t=0; t<=1; t++){
        vector<int> aans;
        ccans = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(dfs,i,i,t);
                vector<int> caans = cans;
                cans.clear();
                for(auto& ele:vvis)visited[ele]=false;
                color[i]=1;
                dfs(dfs,i,i,t);
                if(cans.size()<caans.size())swap(cans,caans);
                cans.clear();
                if(ccans == -1){
                    ccans = INT_MAX;break;
                }
                ccans +=caans.size();
                for(auto& ele:caans)aans.push_back(ele);
                vvis.clear();
            }
        }
        if(ccans<ans){
            ans = ccans;
            aaans = aans;
        }
        visited.assign(n,0);
        color.assign(n,0);
    }
    if(ans>n)cout<<"-1\n";
    else{
        cout<<ans<<"\n";
        for(auto& i:aaans)cout<<i+1<<" ";
    }
}
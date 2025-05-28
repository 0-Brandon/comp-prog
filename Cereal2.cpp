#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    vector<tuple<int,int,int>> edges;
    for(int i=1; i<=n; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        edges.emplace_back(a,b,i);
    }
    sort(edges.begin(),edges.end());
    vector<int> ans;
    vector<bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,visited,)
        }
    }
}
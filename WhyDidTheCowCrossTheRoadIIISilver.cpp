#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<vector<int>> components, vector<vector<bool>> visited, set<vector<int>> roads){
    
}
int main(){
    int n, k ,r; cin>>n>>k>>r;
    set<vector<int>> roads;
    for(int i=0; i<r; i++){
        int a, b, c,  d;
        cin>>a>>b>>c>>d;
        roads.insert({a,b,c,d});
    }
    vector<vector<bool>> visited(n,vector<bool>(n));
    vector<vector<int>> components(n,vector<int>(n));
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,components, visited, roads);
        }
    }
}
#include <bits/stdc++.h>

using namespace std;
void dfs(bool& found, vector<bool>& visited, int s, int t, int& path, int count,vector<vector<int>>& x){
    visited[s] = true;
    if(found) return;
    if(s==t){
        path = count;
        found = true;
        return;
    }
    for(int i=0; i<x[s].size(); i++){
        if(!visited[i]&&x[s][i]!=-1){
            dfs(found, visited, i, t, path, count+x[s][i], x);
        }
    }
}
int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> x(n+1, vector<int>(n+1,-1));
    for(int i=0; i<n-1; i++){
        int a, b, l;
        cin>>a;
        cin>>b;
        cin>>l;
        x[a][b]=l;
        x[b][a]=l;
    }
    while(q--){
        int p1, p2;
        cin>>p1>>p2;
        vector<bool> visited(n, false);
        bool found = false;
        int path = 0;
        dfs(found, visited, p1, p2, path, 0, x);
        cout<<path<<"\n";
    }
}
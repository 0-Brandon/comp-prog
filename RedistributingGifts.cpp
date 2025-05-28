#include <bits/stdc++.h>

using namespace std;

vector<int> component;
void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited,stack<int>& x){
    if(visited[i]) return;
    visited[i]=true;
    x.push(i);
    for(auto& child: adj[i]){
        dfs(child, adj, visited, x);
    }
}
void sccdfs(int i, int num, vector<vector<int>>& adj, vector<bool>& visited){
    if(visited[i]) return;
    visited[i]=true;
    component[i]=num;
    for(auto& child: adj[i]){
        dfs(child, num, adj, visited, x);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    component.resize(n);
    vector<vector<int>> adj(n);
    vector<vector<int>> radj(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            if(a==j+1) break;
            adj[i].push_back(a);
            radj[a].push_back(i);
        }
    }
    stack<int> ord;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i, adj, visited, ord);
    }
    int compnum = 0;
    x.resize(n,false);
    while(!ord.empty()){
        cur = ord.top();
        ord.pop();
        if(!visited[cur])sccdfs(cur, compnum, adj, visited);
        compnum++;
    }
    
}
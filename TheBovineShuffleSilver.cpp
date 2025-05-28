#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
void dfs(int i, vector<int>& adj){
    int a=adj[i], b=adj[adj[i]];
    while(a!=b){
        if(ans[a]!=-1) return;
        a=adj[a];
        b=adj[adj[b]];
    }
    a=i;
    while(a!=b){
        a=adj[a];
        b=adj[b];
    }
    ans[a]=1;
    b=adj[b];
    while(a!=b){
        ans[b]=1;
        b=adj[b];
    }
}
int main(){
    freopen("shuffle.out","w",stdout);
    freopen("shuffle.in","r",stdin);
    int n;
    cin>>n;
    ans.resize(n,-1);
    vector<int> adj(n);
    for(int i=0; i<n; i++){
        cin>>adj[i];
        adj[i]--;
    }
    for(int i=0; i<n; i++){
        if(ans[i]==-1){
            dfs(i,adj);
        }
    }
    int c = 0;
    for(int i=0; i<n; i++){
        if(ans[i]!=-1) c++;
    }
    cout<<c;
}
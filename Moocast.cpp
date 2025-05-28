#include <bits/stdc++.h>

using namespace std;
int dfs(vector<vector<bool>>& adj, int i, vector<bool>& visited){
    if(visited[i]) return 0;
    visited[i]=true;
    int count=1;
    for(int x=0; x<adj[i].size(); x++){
        if(adj[i][x]&&!visited[x]){
            count+=dfs(adj, x, visited);
        }
    }
    return count;
}
int main(){
    freopen("moocast.out","w",stdout);
    freopen("moocast.in","r",stdin);
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> s(n);
    vector<vector<bool>> adj(n,vector<bool>(n,false));
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i]>>s[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            double dist = (y[j]-y[i])*(y[j]-y[i])+(x[j]-x[i])*(x[j]-x[i]);
            if(dist<=s[i]*s[i]){
                adj[i][j] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        vector<bool> visited(n,false);
        int j = dfs(adj, i, visited);
        ans = max(ans, j);
    }
    cout<<ans;
}
#include <bits/stdc++.h>

using namespace std;

    int n, m, comp;
    void dfs(int i, int j, vector<vector<int>>& x, vector<vector<int>>& vis){
        if(i<0||i>=n||j<0||j>=m||x[i][j]==0||vis[i][j])return;
        vis[i][j]=true;
        comp+=x[i][j];
        dfs(i+1,j,x,vis);
        dfs(i-1,j,x,vis);
        dfs(i,j+1,x,vis);
        dfs(i,j-1,x,vis);
    }
void solve(){
    cin>>n>>m;
    vector<vector<int>> x(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>x[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(x[i][j]>0&&!vis[i][j]){
                comp=0;
                dfs(i,j,x,vis);
                ans=max(ans,comp);
            }
        }
    }
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
#include <bits/stdc++.h>

using namespace std;

int ans = 0;
vector<vector<pair<int,int>>> adj;
void dfs(int i, int p=-1, int step=1, int time=-1){
    ans=max(ans,step);
    for(auto& [c,t]:adj[i])if(c!=p){
        if(t<time){
            dfs(c,i,step+1,t);
        }else{
            dfs(c,i,step, t);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    ans=0;
    adj.clear();
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    dfs(0);
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
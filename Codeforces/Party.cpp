#include <bits/stdc++.h>

using namespace std;
int t;
void solve(){
    int n, m;cin>>n>>m;
    vector<int> x(n);
    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> sz(n);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        sz[a]++,sz[b]++;
    }
    if(!(m%2)){cout<<"0\n";return;}
    //we have odd
    //we must remove odd number of pairs
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        if(sz[i]%2==0){
            for(auto& c:adj[i]){
                if(sz[c]%2==0)ans = min(ans,x[i]+x[c]);
            }
        }
        else{
            //odd, we can just remove this
            ans = min(ans,x[i]);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}
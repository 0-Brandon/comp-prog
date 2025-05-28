#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> x(n+1);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x[a].push_back(b);
    }
    int ans=0;
    for(int i=0; i<=n; i++){
        if(x[i].empty())continue;
        sort(x[i].begin(),x[i].end());
        for(int j=max((int)x[i].size()-i,0LL); j<x[i].size(); j++){
            ans+=x[i][j];
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
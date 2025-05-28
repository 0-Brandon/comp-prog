#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<vector<int>> x(n,vector<int>(m));
    vector ans(n,vector<int>(m));
    int cur = 0;
    for(int i=0; i<n; i++){
        for(int j=0, k=cur; j<m; j++){
            cin>>x[i][j];
            if(x[i][j]%2!=k)ans[i][j] = x[i][j]+1;
            else ans[i][j] = x[i][j];
            k^=1;
        }
        cur^=1;
    }
    for(auto& i:ans){
        for(auto& j:i)cout<<j<<" ";
        cout<<"\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
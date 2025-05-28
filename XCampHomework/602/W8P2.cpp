#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n+1);
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }
    vector<int> dp(n);
    vector<map<int,int>> id(n);
    for(int i=1; i<n; i++){
        int dif  = x[i+1] - x[i];
        id[i][dif] = i-1;
        dp[i] = dp[i-1]+1;
        while(id[id[i][dif]].find(dif)!=id[id[i][dif]].end()){
            id[i][dif*2] = id[id[i][dif]][dif];
            dp[i] = min(dp[id[i][dif*2]]+1,dp[i]);
            dif*=2;
        }
    }
    cout<<dp.back()+1<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
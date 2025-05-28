#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> x(n+1);
    for(int i=1; i<n+1; i++){
        cin>>x[i];
    }
    vector<int> dp(n+1,0); //max num balls we can delete
    vector<int> mx(n+1,-10000000); // for each k holds -x where x is the least letfoever we can have
    for(int i=1; i<=n; i++){
        dp[i]=max(dp[i-1], mx[x[i]]+i);
        mx[x[i]]=max(dp[i-1]-(i-1), mx[x[i]]);
    }
    cout<<dp.back()<<"\n";
}
int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}
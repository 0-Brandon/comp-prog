/*we have ai and the number of ai


dp[i] is the minimum cost (for first i elements) if i is the mex (i.e. we remove it before the ones in front of it)
we do not include the (count(i)-1)*i that must be added)
dp[i] is sum j=0 to i of count(j)*i+dp[i]
answer is min across all dp[i]+count(i)*mex;

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> x;
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        int a;cin>>a;cnt[a]++;
    }
    int mex = -1;
    for(int i=0; i<5001; i++){
        if(!cnt.count(i)){
            mex = i;
            break;
        }
    }
    for(auto& [i,j]:cnt){
        x.push_back({i,j});
    }
    vector<int> dp(x.size(),INT_MAX);
    dp[0] = 0;
    for(int i=0; i<x.size(); i++){
        for(int j=0; j<i; j++){
            dp[i] = min(dp[i],dp[j]+(x[j].second)*x[i].first);
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<x.size(); i++){
        ans = min(ans, dp[i]+(x[i].second-1)*mex);
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

// 0 0 0 1 2 3 4 5
// 0 2
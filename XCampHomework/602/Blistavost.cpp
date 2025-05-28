#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> x;
    for(int i=0; i<n; i++){
        int a, b, t;cin>>a>>b>>t;
        x.emplace_back(a,t);
        x.emplace_back(b,t);
    }
    sort(x.begin(),x.end());
    vector<int> v,t;
    n = -1;
    for(auto& i:x)v.push_back(i.first), t.push_back(i.second), n++;
    vector dp(n+1,vector<int> (2));
    dp[1][0] = max(v[1],t[1]);
    dp[1][1] = max(v[n],t[n]);
    int ans = 4e18;
    for(int len = n-1; len>=1; len--){
        vector ndp(n+1,vector<int>(2, 4e18));
        for(int l=1; l<=n-len+1; l++){
            int r = l+len-1;
            int &a = ndp[l][0],&b = ndp[l][1];
            if(l>1){
                a = min(a,dp[l-1][0]+v[l]-v[l-1]);
                b = min(b,dp[l-1][0]+v[r]-v[l-1]);
            }
            if(r<n){
                a = min(a,dp[l][1]+v[r+1]-v[l]);
                b = min(b,dp[l][1]+v[r+1]-v[r]);
            }
            a = max(a,t[l]);
            b = max(b,t[r]);
            if(len == 1)ans = min(ans,a);
        }
        swap(dp,ndp);
    }
    cout<<ans<<"\n";
}
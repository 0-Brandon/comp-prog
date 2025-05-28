#pragma GCC optmize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
using namespace std;
array<int,500005> dp,x;
void solve(){
    int n, k;cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>x[i];
        dp[i]=0;
    }
    int re = (n-1)%k+1;
    int l=0, h=1e9+1;
    while(l<h){
        int mid = (l+h+1)/2;
        for(int i=0; i<n; i++){
            int id =  i%k, val  = x[i]>mid;
            if(id==0)dp[id] = max(dp[id],val);
            else dp[id] = max(dp[id],dp[id-1]+val);
        }
        if(dp[re-1]>=re/2+1){
            l = mid;
        }else{
            h = mid-1;
        }
        for(int i=0; i<n; i++)dp[i]=0;
    }
    cout<<l+1<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n,0);
    vector<int> cnt(n+1,0);
    for(int i=0; i<n; i++){
        cin>>x[i];
        cnt[x[i]]++;
    }
    vector<int> dp(n+1,0);
    for(int i=n; i>=1; i--){
        int dps = 0;
        int cnts = 0;
        for(int j=i; j<=n; j+=i){
            cnts+=cnt[j];
            dps+=dp[j];
        }
        dp[i] = cnts*(cnts-1)/2;
        dp[i]-=dps;
    }
    for(int i=0; i<=n;i++){
        if(cnt[i]!=0)
        for(int j = i; j<=n; j+=i)dp[j]=0;
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans+=dp[i];
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
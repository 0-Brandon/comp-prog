#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> x(n), cnt(100005,0);
    int ans = 0;
    int m = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        cnt[x[i]]++;
        m = max(m,x[i]);
    }
    sort(x.begin(),x.end());
    vector<int> dp(m+1,0);
    vector<int> suf(m+1,0);
    for(int i=m; i>=0; i--){
        suf[i] = cnt[i];
        if(i<m)suf[i]+=suf[i+1];
    }
    for(int i=m;i>=1;i--){
        int dps = 0,c=0;
        for(int j=i; j<=m; j+=i){
            dps +=dp[j];
            dp[i]+= (c)*cnt[j]*(suf[j]-cnt[j]); //one less, one, one greater
            if(cnt[j]>=2)dp[i]+=c*cnt[j]*(cnt[j]-1)/2;//one below, two
            if(cnt[j]>=2) dp[i]+=cnt[j]*(cnt[j]-1)/2*(suf[j]-cnt[j]); //two, one greater;
            if(cnt[j]>=3)dp[i]+=cnt[j]*(cnt[j]-1)*(cnt[j]-2)/6; //three
            c+=cnt[j];
        }
        dp[i]-=dps;
        ans+=i*dp[i];
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
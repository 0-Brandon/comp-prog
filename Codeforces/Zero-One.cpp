#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
    int n, x, y;
    cin>>n>>x>>y;
    string a, b;
    cin>>a>>b;
    vector<int> mis;
    for(int i=0; i<n; i++){
        if(a[i]!=b[i])mis.push_back(i);
    }
    int sz=mis.size();
    if(sz%2==1){cout<<"-1\n";return;}
    if(x>=y){
        if(sz==2&&mis[0]+1==mis[1]){cout<<min(x,2*y)<<"\n";return;}
        cout<<((mis.size()/2)*y)<<"\n";return;
    }
    vector<int> dp(sz+1,0);
    for(int i=1; i<=sz; i++){
        dp[i]=dp[i-1];
        if(i>=2){
            int dist=mis[i-1]-mis[i-2];
            if(i%2==0){//even
                dp[i]=min(dp[i-2]+dist*x, dp[i-1]+y);
            }
            else{//odd
                dp[i]=min(dp[i-1], dp[i-2]+dist*x);
            }
        }
    }
    cout<<dp[sz]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
#define int long long
constexpr int mod = 998244353;
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int ans = 0;
    vector<int> dp(5001);
    dp[0]=1;
    for(int i=0; i<n; i++){
        for(int j=5000; j>=0; j--){
            if(j<=x[i]){
                //we take x[i] as bigger than half element
                //then for all dp[j] subsets with sum j, we add x[i];
                ans=(ans+x[i]*dp[j])%mod;
            }
            else{
                //we take x[i], but its not as big, then its sum/2
                ans=(ans+dp[j]*((j+x[i]+1)/2))%mod;
            }
            if(j+x[i]<5001){
                dp[j+x[i]]=(dp[j+x[i]]+dp[j])%mod;
            }
        }
    }
    cout<<ans<<"\n";
}
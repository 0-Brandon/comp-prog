#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 998244353;

signed main(){
	int n, x, m;
    cin>>n>>x>>m;
    vector<int> f = {0,1};
	for(int i=2; i<=25; i++)f.push_back(f[i-1]+f[i-2]);
	int ma=f[x]*n;
    vector dp(ma+1, vector(n+1, 0));
    dp[0][0]=1;
    for(int i=1; i<=x; i++){
        for(int j=0; j<ma; j++){
            for(int k=0; k<n; k++){
                if(j+f[i]<=ma){
                    dp[j+f[i]][k+1] += (dp[j+f[i]][k+1] + dp[j][k])%mod;
                }
            }
        }
    }
    vector<int> ans(ma+1,INT_MAX);
    ans[0] = 0;
    for(int i=1; i<=ma; i++){
        for(int j=1; j<=25; j++){
            if(i>=f[j]){
                ans[i] = min(ans[i],ans[i-f[j]]+1);
            }
        }
    }
    int res = 0;
    for(int i=0; i<=ma; i++){
        if(ans[i] == m){
            res=(res+dp[i][n])%mod;
        }
    }
    cout<<res<<"\n";
}
 
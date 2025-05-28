#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
int expo(int a,int b){
	int ans=1;
    for(;b;b/=2,a=a*a%mod)if(b&1)ans = ans*a%mod;
	return ans;
}
int dp[55][55][20005];
signed fac[10005], inv[10005];
signed main(){
	fac[0]=1;
	for(int i=1;i<=10000;i++) fac[i]=fac[i-1]*1LL*i%mod;
	inv[10000]=expo(fac[10000],mod-2);
	for(int i=9999;i>=0;i--) inv[i]=inv[i+1]*1LL*(i+1)%mod;
    auto C = [&](int i,int j){
        if(i<0||j<0||i<j) return 0LL;
        return fac[i]*1LL*inv[i-j]%mod*1LL*inv[j]%mod;
    };
	int n,l;
	cin>>n>>l;
    vector<int> a(n);
	for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    sort(a.begin(),a.end());
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=l;k++){
				if(j>0){
                    dp[i][j-1][k+2*a[i-1]]+=dp[i-1][j][k]*j%mod*(j-1)%mod;
                    dp[i][j-1][k+2*a[i-1]]%=mod;
				}
				dp[i][j][k+a[i-1]]+=dp[i-1][j][k]*2%mod*j%mod;
                dp[i][j][k+a[i-1]]%=mod;
				dp[i][j+1][k]+=dp[i-1][j][k];
                dp[i][j+1][k]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=l;i++){
		ans+=(dp[n][1][i]*C(l-i,n)%mod);
        ans%=mod;
	}
	cout<<ans;
}
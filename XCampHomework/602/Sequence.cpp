#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod=998244353;
int expo(int a, int b){
	int ans = 1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans = ans*a%mod;
	return ans;
}
signed main() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> v(m+1);
	for(int i=0; i<=m; i++)cin>>v[i];
	vector c(n+1,vector<int>(n+1));
	for(int i=0; i<=n; i++)c[i][0] = c[i][i] = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<i; j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
    vector dp(vector(m+1,vector(n+1,vector(2*n+1,vector<int>(n+1,0)))));
	for(int i=0; i<=n; i++) dp[0][i][i][i&1] = expo(v[0],i)*c[n][i]%mod;
	for(int i=0;i<m;i++)
	for(int j=0;j<=n;j++)
	for(int o=0;o<=n*2;o++)
	for(int l=0;l<=k;l++)
	for(int p=0;j+p<=n;p++) {
        if(l+((o>>1+p)&1)>k) continue;
        dp[i+1][j+p][(o>>1)+p][l+(((o>>1)+p)&1)]+=dp[i][j][o][l]*expo(v[i+1],p)%mod*c[n-j][p]%mod;
        dp[i+1][j+p][(o>>1)+p][l+(((o>>1)+p)&1)]%=mod;
    }
    int ans = 0;
	for(int i=0;i<=n*2;i++){
		for(int j=0;j<=k-__builtin_popcount(i>>1);j++){
			ans=(ans+dp[m][n][i][j])%mod;
        }
    }
    cout<<ans<<"\n";
}
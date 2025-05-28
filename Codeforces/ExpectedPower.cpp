#include <bits/stdc++.h>

#define int long long
using namespace std;
constexpr int  LOG = 22;
constexpr int mod = 1e9+7;
int exp(int a, int b){
    int ans = 1;
    for(;b;a=a*a%mod,b/=2){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
int dp[LOG][LOG][2][2];
void solve(){
    int n;cin>>n;
    vector<int> x(n),p(n);
    vector<vector<int>> b(n,vector<int>(LOG));
    for(int i=0; i<n; i++){
        cin>>x[i];
        for(int j=0; j<LOG; j++){
            b[i][j] = (x[i]>>j)&1;
        }
    }
    int inv = exp(10000,mod-2);
    for(int i=0; i<LOG; i++)for(int j=0; j<LOG; j++)dp[i][j][0][0]=1;
    for(int i=0; i<n; i++){
        cin>>p[i];
        p[i] = p[i] * inv%mod;
        for(int j=0; j<LOG; j++){
            for(int k=0; k<LOG; k++){
                int temp[2][2];
                for(int jb=0; jb<=1; jb++){
                    for(int kb=0; kb<=1; kb++){
                        temp[jb][kb] = dp[j][k][jb][kb]*((1-p[i]+mod)%mod)%mod+
                                    dp[j][k][jb^b[i][j]][kb^b[i][k]]*p[i]%mod;
                        temp[jb][kb]%=mod;
                    }
                }
                for(int jb=0; jb<=1; jb++){
                    for(int kb=0; kb<=1; kb++){
                        dp[j][k][jb][kb] = temp[jb][kb];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<LOG; i++){
        for(int j=0; j<LOG; j++){
            ans+=((1LL<<(i+j))%mod)*dp[i][j][1][1]%mod;
            ans%=mod;
            for(int k:{0,1})for(int l:{0,1})dp[i][j][k][l]=0;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
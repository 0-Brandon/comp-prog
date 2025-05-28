#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
vector dp(5001,vector<int>(5001));
void solve(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1; i<=n; i++){
        //we take subset of size n
        //answer is size of set+k+1 by default
        //if we skip x elements from the front, 
        //ans is now max_element+(max_element-size of set)
        for(int j=i; j<=n; j++){
            //we take i elements, max element is j
            //number of ways to choose i elements under j
            //if you skip more than i elements, the answer is just i
            //else it is
            if(j>2*i){
                for(int k=0; k<=i; k++){
                    ans+=dp[i-1][];
                }
            }
            else ans+=dp[j-1][i-1]*(2*i+1)%mod;
            ans%=mod;
        }
    }
    cout<<ans+1<<"\n"; //add one for mex of empty set
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    for(int i=0; i<5001; i++){
        for(int j=0; j<=i; j++){
            if(i==0&&j==0)dp[i][j] = 1;
            else if (i==0||j==0)dp[i][j] = 0;
            else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k;cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector dp(n, vector<int>(k+1,INT_MAX));
    vector<int> m(n,INT_MAX);
    for(int i=0; i<n; i++){
        //length of suffix
        int cur = 0;
        for(int j=i; i-j<=k&&j>=0; j--){
            dp[i][i-j] = min(dp[i][i-j], m[j]+cur);
            cur^=x[j];
        }
        m[i] = *min_element(dp[i].begin(),dp[i].end());
        cout<<m[i]<<"\n";
    }
}
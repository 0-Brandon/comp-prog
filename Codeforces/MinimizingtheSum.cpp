#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 9e18;
void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<vector<int>> dp(n, vector<int>(k+1,inf));
    //i is index, j is number of things we use
    for(int i=0; i<n; i++){
        int m=INT_MAX;//minimum element
        int c=0; //changes we need to make
        for(int j=i; i-j<=k&&j>=0; j--){
            if(x[j]<m)m=x[j],c = i-j;
            else{
                if(x[j]!=m)c++;
            }
            for(int l=0; l+c<=k; l++){
                dp[i][l+c] = min(dp[i][l+c],(j>0?dp[j-1][l]:0)+(i-j+1)*m);
            }
        }
    }
    cout<<*min_element(dp.back().begin(),dp.back().end())<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
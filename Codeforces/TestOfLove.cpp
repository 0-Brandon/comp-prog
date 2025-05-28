#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> dp(n+2,INT_MAX);
    dp[0]=0;
    string x;
    cin>>x;
    x = "a"+x+"a";
    for(int i=0; i<x.size(); i++){
        if(x[i]=='C')dp[i]=INT_MAX;
        if(x[i]=='W'){
            dp[i+1]=min(dp[i+1],dp[i]+1);
        }
        else{
            for(int j=0; j<=m&&j+i<x.size(); j++){
                dp[i+j]=min(dp[i+j],dp[i]);
            }
        }
    }
    cout<<((dp.back()<=k)?"YES":"NO")<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
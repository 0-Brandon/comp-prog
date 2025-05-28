#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    int su = 0;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        su+=x[i];
    }
    sort(x.begin(),x.end());
    su-=x.back();x.back()=0;
    vector<bitset<505*55>> dp(505);
    dp[0][0] = 1;
    for(int i=1; i<n; i++){
        if(x[i-1]==x[i])continue;
        for(int j=1; j<=i; j++)dp[j]|=dp[j-1]<<x[i-1];
    }
    vector<bool> pos(505*55);
    for(int i=su; i<=n*50; i++){
        if(dp[n-1][i])pos[i-su] = true;
    }
    for(int i=0; i<=n*50; i++){
        if(pos[i])cout<<i<<" ";
    }
}
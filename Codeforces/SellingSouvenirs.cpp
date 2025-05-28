#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, m;
    cin>>n>>m;
    vector<int> ones, twos, threes;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(a==1)ones.push_back(b);
        if(a==2)twos.push_back(b);
        if(a==3)threes.push_back(b);
    }
    sort(ones.begin(),ones.end(),greater<int>());
    sort(twos.begin(),twos.end(),greater<int>());
    sort(threes.begin(),threes.end(),greater<int>());
    ones.push_back(0);
    ones.push_back(0);
    twos.push_back(0);
    ones.push_back(0);
    twos.push_back(0);
    twos.push_back(0);
    vector<array<long long,3>> dp(m+1);
    dp[0] = {0,0,0};
    dp[1] = {ones[0],1,0};
    for(int i=2; i<=m; i++){
        if(dp[i-1][0]+ones[dp[i-1][1]]>dp[i-2][0]+twos[dp[i-2][2]]){
            dp[i][0] = dp[i-1][0]+ones[dp[i-1][1]];
            dp[i][1] = min(dp[i-1][1]+1,(long long)ones.size()-2);
            dp[i][2] = dp[i-1][2];
        }
        else{
            dp[i][0] = dp[i-2][0]+twos[dp[i-2][2]];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = min(dp[i-2][2]+1,(long long)twos.size()-2);
        }
    }
    long long ans = dp.back()[0];
    long long pref = 0;
    for(int i=0; i<threes.size(); i++){
        if(m-3*(i+1)<0)break;
        pref+=threes[i];
        ans = max(ans,pref+dp[m-3*(i+1)][0]);
    }
    cout<<ans<<"\n";
}
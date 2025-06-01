#include <bits/stdc++.h>
#define int long long
constexpr int mod = 9302023;
using namespace std;

signed main(){
    set<string> st{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string s;
    cin>>s;
    int n = s.size();
    vector<pair<int,int>> dp(n+1,{INT_MAX,0});
    dp[0] = {0,1};
    for(int i=1; i<=n; i++){
        dp[i] = {i,1};
        for(int j=1; j<8&&i-j>=0; j++){
            if(st.count(s.substr(i-j,j))){
                if(dp[i-j].first+1<dp[i].first){
                    dp[i] = {dp[i-j].first+1,dp[i-j].second};
                }
                else if(dp[i-j].first+1==dp[i].first){
                    dp[i].second+=dp[i-j].second;
                    dp[i].second%=mod;
                }
            }
            if(dp[i-j].first+j<dp[i].first){
                    dp[i] = {dp[i-j].first+j,dp[i-j].second};
            }
        }
    }
    cout<<dp[n].first<<" "<<dp[n].second<<"\n";
}
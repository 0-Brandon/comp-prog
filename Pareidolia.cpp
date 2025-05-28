#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s;
    cin>>s;
    int n = s.size();
    int ans = 0;
    string b = "bessie";
    vector<int> dp(7,0); 
    for(int i=0; i<n; i++){
        dp[0]++;
        for(int j=5; j>=0; j--){
            if(s[i]==b[j]){
                dp[j+1]+=dp[j];
                dp[j] = 0;
            }
        }
        ans+=dp.back()*(n-i);
        dp[0]+=dp[6];
        dp[6] = 0;
    }
    cout<<ans<<"\n";
}
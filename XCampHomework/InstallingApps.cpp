#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, c;
    cin>>n>>c;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
    }
    vector<int> s(n);
    iota(s.begin(),s.end(),0);
    sort(s.begin(),s.end(),[&](auto i, auto j){return x[i].first-x[i].second>x[j].first-x[j].second;});
    vector<vector<int>> dp(1,vector<int> (c+1,0));
    for(auto& i:s){
        vector<int> ne(c+1,0);
        for(int j=c; j>=0; j--){
            ne[j] = max(ne[j],dp.back()[j]);
            if(j-x[i].second>=0&&
            c-(j-x[i].second)>=x[i].first){
                ne[j] = max(ne[j],dp.back()[j-x[i].second]+1);
            }
        }
        dp.push_back(ne);
    }
    int ma = 0,d = 0;
    vector<int> ans;
    for(int i=c; i>=0; i--){
        if(dp[n][i]>=ma){
            ma = dp[n][i],d = i;
        }
    }
    for(int i=n; i>=1; i--){
        if(dp[i][d]==dp[i-1][d-x[s[i-1]].second]+1){
            ans.push_back(s[i-1]);
            d-=x[s[i-1]].second;
        }
    }
    cout<<ans.size()<<"\n";
    reverse(ans.begin(),ans.end());
    for(auto& i:ans)cout<<i+1<<" ";
}
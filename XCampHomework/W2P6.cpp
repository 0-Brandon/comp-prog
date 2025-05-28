/*dp[r] is max number to end up with i rating
we first go up
for(auto& i:posbprojects)
for(int r=max;r>=0; r--)
if(r>=a[i])dp[r+b[i]] = max(dp[r+b[i]],dp[i]+1)
then, we go down

for(auto& i:negbprojects)
for(int r=0; r<=max; r++)
if(r>a[i])dp[r-b[i]] = max(dp[r-b[i]],dp[i]+1);
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, base;cin>>n>>base;
    vector<pair<int,int>> pos, neg;
    for(int i=0; i<n; i++){
        int a,b;cin>>a>>b;
        if(b>=0)pos.push_back({a,b});
        else neg.push_back({a,b});
    }
    sort(pos.begin(),pos.end());
    vector<int> dp(2*30000+10,-1);
    dp[base] = 0;
    for(auto& i:pos){
        for(int r=dp.size()-1;r>=0; r--){
            if(r>=i.first&&r+i.second<dp.size()&&dp[r]!=-1){
                dp[r+i.second] = max(dp[r+i.second],dp[r]+1);
            }
        }
    }
    sort(neg.begin(),neg.end(),[&](auto i, auto j){return i.first+i.second>j.first+j.second;});
    for(auto& i:neg){
        for(int r=0;r<dp.size(); r++){
            if(r>=i.first&&r+i.second<dp.size()&&dp[r]!=-1){
                dp[r+i.second] = max(dp[r+i.second],dp[r]+1);
            }
        }
    }
    int ma = 0;
    for(int i=0; i<dp.size(); i++){
        ma = max(ma,dp[i]);
    }
    cout<<ma<<"\n";
}
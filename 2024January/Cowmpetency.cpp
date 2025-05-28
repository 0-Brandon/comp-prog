#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9+7;
int exp(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=(a*a)%mod){
        if(b&1){
            ans = (ans*a)%mod;
        }
    }
    return ans;
}
signed main(){
    int ans = 0;
    int n, q, c;
    cin>>n>>q>>c;
    vector<array<int,3>> timeline;
    for(int i=0; i<q; i++){
        int a, h;
        cin>>a>>h;
        timeline.push_back({a,h,0LL});
        timeline.push_back({a,h,1LL});
    }
    sort(timeline.begin(),timeline.end(),[&](array<int,3> i, array<int,3> j){
        int a = (i[2]==1)?i[1]:i[0];
        int b = (i[2]==1)?i[1]:i[0];
        return a<b;
        });
    int l = 0;
    map<int,vector<int>> dp;
    for(auto& i:timeline){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
        if(i[2]==1){
            dp[i[1]].resize(c+1);
            for(int j=1; j<=c; j++){
                //hi
                dp[i[1]][j+1] = (dp[l][j]+exp(j,i[1]-l))%mod;
                //number of ways hi can be j+1 if ai is j
            }
            l = i[1];
        }
        else{
            //ai
            dp[i[0]].resize(c+1);
            for(int j=1; j<=c; j++){
                dp[i[0]][j] = exp(j,i[0]-l);
            }
            l = i[0];
        }
    }
    for(auto& i:timeline){
        if(i[2]==1){
            for(int j=2; j<=c; j++){
                dp[i[1]][j] = (dp[i[1]][j]+dp[i[1]][j-1])%mod;
            }
        }
    }
    for(int i=1; i<=c; i++){
        ans=(ans+dp[l][i])%mod;
    }
    for(auto& [l,i]:dp){
        cout<<l<<": \n";
        for(auto& j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<ans*exp(c,(n-l))%mod;
}
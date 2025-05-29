#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> fac(3e5+10,0);
    fac[0] = 1;
    for(int i=1; i<3e5+10; i++)fac[i] = fac[i-1]*i%mod;
    vector<pair<int,int>> x(n);
    map<int,int> c1,c2;
    map<pair<int,int>,int>c3;
    int res = fac[n];
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
        c1[x[i].first]++;
        c2[x[i].second]++;
        c3[x[i]]++;
    }
    int ans = 1;
    for(auto& [i,cnt]:c1){
        ans=ans*fac[cnt]%mod;
    }
    int ans1 = 1;
    for(auto& [i,cnt]:c2){
        ans1=ans1*fac[cnt]%mod;
    }
    res=(res+mod-ans)%mod;
    int ans2=1;
    vector<pair<int,int>> ac = x;
    sort(x.begin(),x.end());
    for(int i=1; i<n; i++)if(x[i].second<x[i-1].second)ans2 = 0;
    res = (res+mod-ans1)%mod;
    if(ans2!=0)for(auto& [i,cnt]:c3){
        ans2=ans2*fac[cnt]%mod;
    }
    res = (res+ans2)%mod;
    cout<<res<<"\n";
}
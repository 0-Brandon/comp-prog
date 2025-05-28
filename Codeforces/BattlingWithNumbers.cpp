#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;
decltype(cout<<0) solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++)cin>>x[i].first;
    for(int i=0; i<n; i++)cin>>x[i].second;
    int m;
    cin>>m;
    vector<pair<int,int>> y(m);
    for(int i=0; i<m; i++)cin>>y[i].first;
    for(int i=0; i<m; i++)cin>>y[i].second;
    if(m>n)return cout<<0;
    int i=0;
    int ans = 1;
    for(int j=0; j<m; j++,i++){
        if(y[j].first<x[i].first)return cout<<0;
        while(x[i].first<y[j].first)i++,ans=(ans*2)%mod;
        if(y[j].first<x[i].first)return cout<<0;
        if(x[i].second<y[j].second)return cout<<0;
        if(x[i].second!=y[j].second)ans = (ans*2)%mod;
    }
    while(i<n)ans = (ans*2)%mod,i++;
    return cout<<ans;
}
signed main(){
    solve();
}
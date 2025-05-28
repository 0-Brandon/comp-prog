#include <bits/stdc++.h>
#define int long long
using namespace std;

//we only add more and more restrictions
//at index b, we can assume that we are following everything above b
//if b is 0, we satisfy it and move on
//else, we try to satisfy b=0 and update ans
//how to satisfy given b
//for each group
//is it only splitting??

void solve(){
    int n, x;
    cin>>n>>x;
    x++;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans = -1;
    for(int b=0; b<=30; b++){
        if(!((x>>b)&1))continue;
        int mask = (x>>b)-1;
        int pref = 0;
        int cur = 0;
        for(int i=0; i<n; i++){
            pref^=(a[i]>>b);
            if((pref|mask)==mask){
                cur++;
                pref=0;
            }
        }
        if(pref==0){
            ans = max(ans,cur);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
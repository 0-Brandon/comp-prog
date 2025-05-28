#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int a;cin>>a;
    vector<int> x;
    while(a>0){
        x.push_back(a%10);a/=10;
    }
    reverse(x.begin(),x.end());
    int su = 0;
    int n = x.size();
    int acc = 0;
    for(int i=n-1; i>=0; i--){
        if(acc+8<x[i]){cout<<"NO\n";return;}
        if(acc>x[i]){cout<<"NO\n";return;}
        acc=1;
    }
    if(x[0]!=1)cout<<"NO\n";
    else cout<<"YES\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
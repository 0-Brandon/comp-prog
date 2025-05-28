#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int x, y, k;
    cin>>x>>y>>k;
    int ans = 0;
    while(x!=1){
        int ad = ((x+y)/y)*y-x;
        if(ad>k){
            cout<<x+k<<"\n";return;
        }
        x+=ad;
        while(x%y==0)x/=y;
        k-=ad;
    }
    cout<<1+(k%(y-1))<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    vector<int> pref(n+1,0);
    for(int i=0; i<n; i++){
        cin>>x[i];
        pref[i+1] = pref[i]+x[i];
    }
    int l = 4e18, r = -1;
    for(int i=0; i<n; i++){
        l = min(l,(pref[i+1])/(i+1));
    }
    for(int i=0; i<n; i++){
        r = max(r,(pref.back()-pref[i]+n-i-1)/(n-i));
    }
    cout<<max(0LL,r-l)<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
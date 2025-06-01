#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n, q;cin>>n>>q;
    vector<int> x(n);
    int tot = 0;
    vector<int> pref(n+1);
    for(int i=0; i<n; i++){
        cin>>x[i];
        tot+=x[i];
        pref[i+1] = pref[i]+x[i];
    }
    auto query = [&](int l, int r){
        if(l>r){
            return pref.back()-pref[l]+pref[r+1]-pref[0];
        }else{
            return pref[r+1]-pref[l];
        }
    };
    while(q--){
        int l, r;cin>>l>>r;
        l--,r--;
        if((r-l+1)<n&&l/n==r/n){
            cout<<query((l/n+l%n)%n,(r/n+r%n)%n)<<"\n";
            continue;
        }
        int ans = (r/n-l/n-1)*tot;
        int cl = l/n;
        int ml = l%n;
        /* 19 21
        cl = 3, ml = 4
        cr = 4, m4 = 1
        4 9 10 10 1 9 10 10 1 4 10 10 1 4 9 10 1 4 9 10 1 4 9 10 10
        */
        int cr = r/n;
        int mr = r%n;
        ans+=query((cl+ml)%n,(cl-1+n)%n);
        ans+=query(cr,(cr+mr)%n);
        cout<<ans<<"\n";
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
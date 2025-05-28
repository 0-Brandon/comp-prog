#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> x(n);
    vector<int> pref(n+1,0),pref2(n+1,0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    map<int,int> rev;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(rev.find(x[i])==rev.end()){
            rev[x[i]]=rng();
        }
        pref[i+1] = pref[i]^rev[x[i]];
        pref2[i+1] = pref2[i]^x[i];
    }
    while(q--){
        int l, r;cin>>l>>r;
        if(((pref[r]^pref[l-1])==0)&&((pref2[r]^pref2[l-1])==0)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
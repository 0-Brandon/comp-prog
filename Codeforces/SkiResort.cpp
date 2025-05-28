#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    
    int n, k, q;
    cin>>n>>k>>q;
    int c=1, kc=0, ans=0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(a>q){
            c=1;
            kc=0;
            continue;
        }
        kc++;
        if(kc>=k){
            ans+=c;
            c++;
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
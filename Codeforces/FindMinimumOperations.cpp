#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;cin>>n>>k;
    int ans =0;
    if(k==1){cout<<n<<"\n";return;}
    while(n){
        ans+=n%k;
        n/=k;
    }
    cout<<ans<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
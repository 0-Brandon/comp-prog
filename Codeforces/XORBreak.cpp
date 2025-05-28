#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    if(n<m){cout<<"-1\n";return;}
    int b = n^m;
    if(b<n){cout<<"1\n"<<n<<" "<<m<<"\n";return;}
    int ca = -1,te=b;
    while(te)ca++,te>>=1;
    ca = 1LL<<ca;
    int cb=b^ca;
    swap(ca,cb);
    if((ca^n)<m||(ca^n)>n){cout<<"-1\n";return;}
    cout<<2<<"\n";
    cout<<n<<" "<<(n^ca)<<" "<<(n^ca^cb)<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
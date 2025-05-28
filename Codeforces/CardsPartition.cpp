#include <bits/stdc++.h>
#define int long long
using namespace std;
//wrong
void solve(){
    int n, k;cin>>n>>k;
    vector<int> x(n);
    int m=0;
    int tot= 0 ;
    for(int i=0; i<n; i++){
        cin>>x[i];
        tot+=x[i];
        m = max(x[i],m);
    }
    auto ok = [&](int t)->bool {
        //t is height of stack
        //we need at least m stacks
        int s = max(m, (tot+t-1)/t);
        //if t*m is less than tot,
        return t*s-tot<=k;
    };
    int l=0, h = n;
    while(l<h){
        int mid = l+(h-l+1)/2;
        if(ok(mid)){
            l = mid;
        }else{
            h=mid-1;
        }
    }
    cout<<l<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    int l = max(n-m,0LL);
    if(m==0){cout<<n<<"\n";return;}
    int r = n+m;
    int ans = 0;
    while(true){
        int ls = 31-__builtin_clz(l|1);
        int rs = 31-__builtin_clz(r|1);
        if(ls!=rs){
            ans|=((1<<(max(ls,rs)+1))-1);
            break;
        }
        ans|=(1<<ls);
        l-=(1<<ls);
        r-=(1<<rs);
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
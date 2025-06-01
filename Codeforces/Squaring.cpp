#include <bits/stdc++.h>
#define int long long
using namespace std;


//find min y such that a^(2^x)<=b^(2^y)

/*2^x*log(a)<=2^y*log(b)
x+log2(log(a))<=y+log2(log(b))
x+log2(log(a)/log(b))<=y;*/
int calc(double x, double a, double b){
    return max(0.0,ceil(x+ceil(log2(log(a)/log(b)))));
}
void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<int> cnt(n);
    cnt[0]=0;
    int ans = 0;
    for(int i=1; i<n; i++){
        if(x[i]==1&&x[i-1]!=1){cout<<"-1\n";return;}
        cnt[i] = calc(cnt[i-1], x[i-1],x[i]);
        ans+=cnt[i];
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
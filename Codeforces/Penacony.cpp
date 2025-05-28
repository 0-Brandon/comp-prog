#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    mt19937_64 rr(chrono::steady_clock::now().time_since_epoch().count());
    int n, m;cin>>n>>m;
    vector<int> x(n);
    map<int,int> cnt;
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        a--,b--;
        int c = rr();
        x[a] ^= c;
        x[b] ^= c;
    }
    int ma = 0,a=0;
    for(int i=0; i<n; i++){
        ma = max(ma,cnt[a^=x[i]]++);
    }
    cout<<n-ma-1<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
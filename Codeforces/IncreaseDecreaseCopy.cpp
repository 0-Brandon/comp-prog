#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n),b(n+1);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<=n; i++){
        cin>>b[i];
    }
    int ans = 0;
    int m = INT_MAX;
    for(int i=0; i<n; i++){
        ans+=abs(b[i]-a[i]);
        if(min(b[i],a[i])<=b.back()&&max(b[i],a[i])>=b.back())m=0;
        else m = min({m,abs(b[i]-b.back()),abs(a[i]-b.back())});
    }
    cout<<ans+m+1<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
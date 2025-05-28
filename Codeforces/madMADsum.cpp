#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    int ans = 0;
    for(int i=0; i<n;i++){
        cin>>x[i];
        ans+=x[i];
    }
    auto act = [&](){
        int m=0;
        map<int,bool> cnt;
        for(int i=0; i<n; i++){
            if(cnt[x[i]])m = max(m,x[i]);
            cnt[x[i]]=true;
            x[i]=m;
        }
    };
    act();
    for(auto& i:x)ans+=i;
    act();
    for(int i=0; i<n; i++){
        ans+=x[i]*(n-1-i+1);
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
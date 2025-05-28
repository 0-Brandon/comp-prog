#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> x(n), y(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n; i++){
        cin>>y[i];
    }
    sort(x.begin(),x.end());
    sort(y.rbegin(),y.rend());
    int ans=0;
    for(int i=0; i<n; i++){
        ans+=x[i]*y[i];
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
}
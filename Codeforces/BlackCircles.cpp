#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n),y(n);int sx,sy,tx,ty;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    cin>>sx>>sy>>tx>>ty;
    auto dist = [&](int x, int y, int i,int j){
        return (i-x)*(i-x)+(j-y)*(j-y); 
    };
    int d = dist(sx,sy,tx,ty);
    for(int i=0; i<n; i++){
        if(dist(x[i],y[i],tx,ty)<=d){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
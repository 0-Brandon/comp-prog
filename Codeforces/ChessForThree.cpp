#include <bits/stdc++.h>

using namespace std;


void solve(){
    vector<int> x(3);
    cin>>x[0]>>x[1]>>x[2];
    if((x[0]+x[1]+x[2])%2!=0)cout<<"-1\n";
    else cout<<min(x[0]+x[1],(x[0]+x[1]+x[2])/2)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
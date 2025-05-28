#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, c;
    cin>>n>>c;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> p(n);
    iota(p.begin(),p.end(),1);
    sort(p.begin(),p.end(),[&](int i, int j){return (x[i-1]-c*i)>(x[j-1]-c*j);});
    int su = x[0];
    for(auto& idx:p){
        if(idx==1)continue;
        su+=x[idx-1];
        if(su<c*idx){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
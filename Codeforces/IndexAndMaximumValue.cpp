#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<int> x(n);
    int id = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(x[i]>x[id])id=i;
    }
    for(int i=0; i<m; i++){
        char c;
        int l, r;
        cin>>c>>l>>r;
        if(l<=x[id]&&x[id]<=r)x[id]+=((c=='+')?1:-1);
        cout<<x[id]<<" ";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
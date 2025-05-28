#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,q;cin>>n>>q;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    map<int,int> mp;
    for(int i=1; i<=n;i++){
        mp[i*(n-i+1)-1]++;
        mp[(n-i)*(i)]+=x[i]-x[i-1]-1;
    }
    while(q--){
        int k;cin>>k;
        cout<<mp[k]<<" ";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
   int t;cin>>t;
   while(t--)solve();
}
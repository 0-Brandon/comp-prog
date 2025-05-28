#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int b=1;
    for(int i=0; i<n; i++){
        if(x[i]%x[0]!=0){b=i;break;}
    }
    for(int i=0; i<n; i++){
        if(((x[i]%x[0])!=0)&&((x[i]%x[b])!=0)){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
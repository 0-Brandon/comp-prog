#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, l, r;
    cin>>n>>l>>r;
    int cur = 0;
    int ans = 0;
    vector<int> x(n);
    int s = 0;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        x[i]=a;
        if(l<=a&&a<=r){
            cur=0;
            ans++;
            s=i+1;
        }
        else{
            cur+=a;
        }
        while(cur>r){
            cur-=x[s],s++;
        }
        if(cur<=r&&cur>=l){
            ans++;
            cur=0;
            s=i+1;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
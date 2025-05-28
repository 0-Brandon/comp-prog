#include <bits/stdc++.h>
//doesn't take into account that all the values in a must be 1 or -1
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    for(int i=0; i<n; i++)cin>>c[i];
    for(int i=0; i<n; i++){
        x[abs(a[i])-1]+=a[i]/abs(a[i]);
        x[abs(b[i])-1]+=b[i]/abs(b[i]);
        x[abs(c[i])-1]+=c[i]/abs(c[i]);
    }
    for(int i=0; i<n; i++)x[i] = abs(x[i]);
    if(accumulate(x.begin(),x.end(),0)>=n)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
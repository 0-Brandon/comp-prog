#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int ans =x[0] ;
    for(int i=1; i<n; i++){
        ans = (ans+x[i])/2;
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int k;
    int n;cin>>n>>k;
    int ans = 0;vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    sort(x.rbegin(),x.rend());
    for(int i=0; i<n; i++){
        if(i%2==0){
            ans+=x[i];
        }else{
            ans-=x[i];
            int dif = x[i-1]-x[i];
            int m = min(dif,k);
            k-=m;
            ans-=m;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n),y(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n; i++)cin>>y[i];
    int ans = 0;
    for(int i=0; i<n; i++){
        if(x[i]>y[i]){
            int id=distance(y.begin(),lower_bound(y.begin(),y.end(),x[i]));
            ans+=max(0,id-i-ans);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
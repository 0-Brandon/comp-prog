#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        auto it = lower_bound(x.begin(),x.end(),x[i]+x[i+1]);
        int id = x.end()-it;
        ans = min(ans,id+i);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}


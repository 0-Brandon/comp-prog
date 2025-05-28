#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> ans;
    int id = 0;
    for(int i=63; i>=0; i--)if((n>>i)&1){
        ans = vector<int>(i);
        id=i;break;
    }
    iota(ans.begin(),ans.end(),1e9-ans.size());
    for(int i = id-1; i>=0; i--){
        if((n>>i)&1){
            ans.insert(ans.end()-i,-1e9);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
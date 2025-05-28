#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>, null_type, greater<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    ordered_multiset e;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = INT_MAX;
    for(int i=n-1; i>=0; i--){
        ans = min(ans,(int)(i+e.order_of_key({x[i],INT_MAX})));
        e.insert({x[i],i});
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
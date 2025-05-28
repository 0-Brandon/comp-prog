#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n+2), b(2*n+2);
    vector<vector<int>> occ(2*n+2);
    for(int i=0; i<n; i++){
        cin>>a[i];
        occ[a[i]].push_back(i);
    }
    for(int i=0; i<n; i++)cin>>b[i];
    vector<int> x(2*n+2,0);
    int ans=0;
    for(int i=1; i*i<=2*n; i++){
        if(occ[i].empty())continue;
        for(auto& j:occ[i])x[b[j]]++;
        for(int j=i; j*i<=2*n; j++){
            if(occ[j].empty())continue;
            int s=i*j;
            int cnt=0;
            for(auto& k:occ[j]){
               if(s-b[k]>=1&&s-b[k]<=n)cnt+=x[s-b[k]]-(i==j&&b[k]*2==s);
            }
            if(i==j)cnt/=2;
            ans+=cnt;
        }
        for(auto& j:occ[i])x[b[j]]--;
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}
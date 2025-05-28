#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, a, b;cin>>n>>a>>b;
    int g = gcd(a,b);
    vector<int> x(n),y(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i] = x[i]%g;
    }
    int ans=INT_MAX;
    set<int> s(x.begin(),x.end());
    int cur = *s.rbegin()-*s.begin();
    for(int i=0; i<s.size(); i++){
        s.insert(*s.begin()+g);
        s.erase(s.begin());
        cur = min(cur,*s.rbegin()-*s.begin());
    }
    ans= min(ans,cur);
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
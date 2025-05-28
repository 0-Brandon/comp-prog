#include <bits/stdc++.h>
#define int long long
using namespace std;
 
void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    set<int> exi;
    int m = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>x[i];
        exi.insert(x[i]);
        m = max(x[i],m);
    }
    if(n==1){
        cout<<"1\n";return;
    }
    int g = 0;
    for(int i=0; i<n; i++){
      g = gcd(g,m-x[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++)ans+= (m-x[i])/g;
    int i = m;
    while(exi.count(i))i-=g,ans++;
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
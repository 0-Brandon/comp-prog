#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> x;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        x.push_back({t,0});
    }
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        x.push_back({t,1});
    }
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    sort(x.begin(),x.end());
    stack<int> s;
    vector<int> ninv;
    for(int i=0; i<2*n; i++){
        if(x[i].second==1){
            ninv.push_back(x[i].first-s.top());
            s.pop();
        }else{
            s.push(x[i].first);
        }
    }
    sort(ninv.begin(),ninv.end());
    int ans = 0;
    sort(c.rbegin(),c.rend());
    for(int i=0; i<n; i++){
        ans+=ninv[i]*c[i];
    }
    cout<<ans<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

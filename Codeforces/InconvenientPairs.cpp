#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> v(n),h(m);
    for(int i=0; i<n; i++)cin>>v[i];
    sort(v.begin(),v.end());
    for(int i=0; i<m; i++)cin>>h[i];
    sort(h.begin(),h.end());
    vector<pair<int,int>> x;
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;
        x.push_back({a,b});
    }
    //sorted by x value
    long long int ans = 0;
    sort(x.begin(),x.end());
    for(int i=0; i<n-1; i++){
        int l = upper_bound(x.begin(),x.end(), v[i],[&](int a, pair<int,int>& b){return b.first>a;})-x.begin();
        int r = lower_bound(x.begin(),x.end(),v[i+1],[&](pair<int,int>& b, int a){return b.first<a;})-x.begin();
        map<int,int> he;
        for(int j=l; j<r; j++){
            he[x[j].second]++;
        }
        ans+=(r-l)*1LL*(r-l-1)/2;
        for(auto& [po,lo]:he){
            ans-=1LL*lo*(lo-1)/2;
        }
    }
    sort(x.begin(),x.end(),[&](pair<int,int>& a, pair<int,int>& b){return a.second<b.second;});
    for(int i=0; i<m-1; i++){
        int b = upper_bound(x.begin(),x.end(), h[i],[&](int a, pair<int,int>& b){return b.second>a;})-x.begin();
        int t = lower_bound(x.begin(),x.end(),h[i+1],[&](pair<int,int>& b, int a){return b.second<a;})-x.begin();
        map<int,int> he;
        for(int j=b; j<t; j++){
            he[x[j].first]++;
        }
        ans+=(t-b)*1LL*(t-b-1)/2;
        for(auto& [po,lo]:he){
            ans-=1LL*lo*(lo-1)/2;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    sort(b.rbegin(),b.rend());
    vector<int> ans;
    int i=0,j=0;
    while(i<n&&j<m){
        if(b[j]>a[i])ans.push_back(b[j++]);
        else ans.push_back(a[i++]);
    }
    while(j<m)ans.push_back(b[j++]);
    while(i<n)ans.push_back(a[i++]);
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
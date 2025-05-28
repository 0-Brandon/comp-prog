#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<(a.back()-a[0])+(a[a.size()-2]-a[0])+((a[a.size()-2]-a[1]))+(a.back()-a[1])<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
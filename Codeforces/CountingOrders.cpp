#include <bits/stdc++.h>

using namespace std;
int mod = 1e9+7;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end(), greater<int>());
    int idx = 0;
    sort(b.begin(),b.end(), greater<int>());
    long long int  ans = 1;
    for(int i=0; i<n; i++){
        while(idx<n&&a[idx]>b[i])idx++;
        ans*=max((idx)-i,0);
        ans%=mod;
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
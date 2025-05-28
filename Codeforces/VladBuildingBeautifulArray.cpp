#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    int m = INT_MAX;
    for(int i=0; i<n; i++){
        cin>>x[i];
        m=min(x[i],m);
    }
    //odd
    if(m&1){
        cout<<"Yes\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(x[i]&1){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1; i<n; i++){
        cout<<i<<" "<<i+1<<"\n";
    }
    int l = n-1;
    for(int i=0; i<q; i++){
        int d;
        cin>>d;
        cout<<n<<" "<<l<<" "<<d<<"\n";
        l=d;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
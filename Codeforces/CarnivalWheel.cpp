#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l,a,b;
    cin>>l>>a>>b;
    b%=l;
    int c = (a+b)%l;
    int ans = a;
    while(c!=a){
        ans = max(ans,c);
        c = (c+b)%l;
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r;cin>>l>>r;
    cout<<(31-__builtin_clz(r))<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}
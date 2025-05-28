#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r;cin>>l>>r;
    if(l%2==0)l++;
    cout<<(r-l+2)/4<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
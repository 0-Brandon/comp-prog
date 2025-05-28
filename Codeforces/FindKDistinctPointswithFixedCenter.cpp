#include <bits/stdc++.h>

using namespace std;

void solve(){
    int x, y, k;cin>>x>>y>>k;
    for(int i=1; (i)*2<=k; i++){
        cout<<x+i<<" "<<y<<"\n";
        cout<<x-i<<" "<<y<<"\n";
    }
    if(k&1){cout<<x<<" "<<y<<"\n";}
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;while(t--)solve();
}
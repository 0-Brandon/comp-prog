#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;cin>>n>>m>>k;
    cout<<min(n,k)*min(k,m)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
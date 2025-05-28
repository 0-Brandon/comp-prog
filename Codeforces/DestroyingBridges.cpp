#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;cin>>n>>k;
    if(k>=n-1)cout<<1<<"\n";
    else cout<<n<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){solve();}
}
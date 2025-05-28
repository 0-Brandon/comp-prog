#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int  n, m, r, c;
    cin>>n>>m>>r>>c;
    cout<<n*m-((r-1)*(m)+c)+(n-r)*(m-1)<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
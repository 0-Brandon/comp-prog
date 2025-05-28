#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    cout<<(((n&1)==(m&1)&&n>=m)?"YES":"NO")<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}
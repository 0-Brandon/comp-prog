#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int c = 0;
    for(int i=0; i<n; i++){
        c+=(s[i]=='U');
    }
    if(c&1)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}
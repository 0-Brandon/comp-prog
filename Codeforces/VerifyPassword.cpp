#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string b;
    string s;cin>>s;
    b=s;
    sort(s.begin(),s.end());
    if(b==s)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
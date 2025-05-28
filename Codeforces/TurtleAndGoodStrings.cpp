#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    bool b=false;
    for(int i=0; i<n; i++){
        if(s[i]!=s[i-1])b=true;
    }
    if(b&&s.back()!=s[0])cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
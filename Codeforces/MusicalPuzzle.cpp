#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    int n;
    cin>>n>>s;
    set<string> x;
    for(int i=0; i<n-1; i++){
        x.insert(to_string(s[i])+to_string(s[i+1]));
    }
    cout<<x.size()<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
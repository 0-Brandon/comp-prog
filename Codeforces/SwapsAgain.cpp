#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    map<int,map<int,int>> p;
    for(int i=0; i<n; i++){
        p[a[i]][a[n-i-1]]++;
    }
    bool f = true;
    for(int i=0; i<n; i++){
        if(p[b[i]][b[n-i-1]]<=0)f=false;
        p[b[i]][b[n-i-1]]--;
    }
    if(f)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
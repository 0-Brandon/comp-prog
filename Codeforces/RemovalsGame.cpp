#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++)cin>>b[i];
    if(n==2){cout<<"Bob\n";return;}
    bool b1= true;
    for(int i=0; i<n; i++)if(a[i]!=b[i]){b1=false;}
    bool b2=true;
    for(int i=0; i<n; i++)if(a[i]!=b[n-1-i])b2=false;
    if(!b2&&!b1)cout<<"Alice\n";
    else cout<<"Bob\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
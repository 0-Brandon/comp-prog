#include <bits/stdc++.h>

using namespace std;

void solve(){
    string x, y;
    cin>>x>>y;
    string a="", b="";
    int n = x.size();
    int i=0;
    while(i<n&&x[i]==y[i])a+=x[i],b+=x[i],i++;
    if(i==n){cout<<a<<"\n"<<b<<"\n";return;}
    a+=min(x[i],y[i]);
    b+=max(x[i],y[i]);
    i++;
    //minimize x, maximise y
    for(; i<n; i++){
        a+=max(x[i],y[i]);
        b+=min(x[i],y[i]);
    }
    cout<<a<<"\n"<<b<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
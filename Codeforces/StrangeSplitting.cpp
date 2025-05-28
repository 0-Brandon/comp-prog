#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    int n;cin>>n;
    bool b = true;
    bool b1 = true;
    int l=0;
    for(int i=0; i<n; i++){
        int t;cin>>t;
        if(l!=0&&t!=l)b=false;
        if(l!=0&&t!=l&&i<n-1)b1=false;
        l=t;
    }
    if(b)cout<<"NO\n";
    else{
        cout<<"YES\n";
        if(!b1)cout<<string(n-1,'R')<<"B\n";
        else cout<<"B"<<string(n-1,'R')<<"\n";
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
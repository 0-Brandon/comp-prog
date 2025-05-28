#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> a(n);
    bool nd=false,ni=false;
    for(int i=0; i<n; i++){
        cin>>x[i];
        a[i]=x[i];
    }
    //This section is probably not needed
    for(int i=n-2; i>=1; i--){
        if(x[i+1]<x[i]){
            x[i-1]-=x[i]-x[i+1];
            x[i]=x[i+1];
        }
    }
    
    if(x[1]>=x[0])nd=true;
    //
    for(int i=1; i<n-1; i++){
        if(x[i]<x[i-1]){
            x[i+1]+=x[i-1]-x[i];
            x[i]=x[i-1];
        }
    }
    // you can make every number except one equal to each other
    // 5 5 5 5 3
    // 5 5 5 5 5 3
    if(a[n-1]>=a[n-2]||a.size()%2==1)ni=true;
    if(ni||nd)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    if(n>2)cout<<"NO\n";
    else if(x[0]==x[1]-1)cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}
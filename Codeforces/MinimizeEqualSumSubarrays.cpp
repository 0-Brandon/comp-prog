#include <bits/stdc++.h>

using namespace std;

void solve(){
    
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=1; i<n; i++){
        cout<<x[i]<<" ";
    }
    cout<<x[0]<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}
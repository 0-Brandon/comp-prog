#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    for(int i=1; i<n; i++)if(x[i]%2!=x[i-1]%2){cout<<"-1\n";return;}
    cout<<30+(x[0]%2==0)<<"\n";
    for(int i=29; i>=0; i--){
        cout<<(1<<i)<<" ";
    }
    if(x[0]%2==0)cout<<"1 ";
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n-1; i++)if(min(x[i],x[i+1])*2>max(x[i],x[i+1])){cout<<"YES\n";return;}
    cout<<"NO\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
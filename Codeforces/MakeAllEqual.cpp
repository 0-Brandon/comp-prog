#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;vector<int> x(n+1);
    for(int i=0; i<n; i++){
        int a;cin>>a;x[a]++;
    }
    sort(x.begin(),x.end());
    cout<<n-x.back()<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
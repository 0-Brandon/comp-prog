#include <bits/stdc++.h>

using namespace std;

void solve(){
    
    int n;cin>>n;
    vector<pair<int,int>> x(n);
    int m = 0;
    int m1 = 0;
    for(int i=0; i<n; i++){
        cin>>x[i].second>>x[i].first;
        m = max(m,x[i].second);
        m1 = max(m1,x[i].first);
    }
    cout<<2*(m+m1)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, q;cin>>n>>m>>q;
    vector<int> x(m);
    for(int i=0; i<m; i++)cin>>x[i];
    sort(x.begin(),x.end());
    for(int i=0; i<q; i++){
        int a;cin>>a;
        if(lower_bound(x.begin(),x.end(),a)==x.begin())cout<<*x.begin()-1<<"\n";
        else if(lower_bound(x.begin(),x.end(),a)==x.end())cout<<n-x.back()<<"\n";
        else{
            int l = *--lower_bound(x.begin(),x.end(),a);
            int r = *lower_bound(x.begin(),x.end(),a);
            cout<<(r-l)/2<<"\n";
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int m = INT_MAX;
    vector<int> p(n);iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),[&](int i, int j){return x[i]<x[j];});
    int a=0, b=0;
    for(int i=1; i<n; i++){
        if((x[p[i]]^x[p[i-1]])<m){
            a=p[i-1],b=p[i];
            m=(x[p[i]]^x[p[i-1]]);
        }
    }
    int c = ((~x[a])&((1<<k)-1));
    cout<<(a+1)<<" "<<(b+1)<<" "<<c<<"\n";
}
int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}
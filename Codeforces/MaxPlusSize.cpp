#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    int m=0;
    int mi  = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(i%2==0)mi = max(mi,x[i]);
        m = max(m,x[i]);
    }
    cout<<max(m+n/2,mi+(n+1)/2)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
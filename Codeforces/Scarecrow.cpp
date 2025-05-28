#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    double k, l;
    cin>>n>>k>>l;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    vector<double> b(n);
    double t=a[0];
    b[0] = 0;
    for(int i=1; i<n; i++){
        b[i] = min(l,min(a[i]+t,max((a[i]-t+b[i-1]+k)/2.0, b[i-1]+k)));
        t+=max(0.0,b[i]-b[i-1]-k);
    }
    double ans = 0;
    for(int i=1; i<n; i++)ans+=min(b[i]-b[i-1],k);
    ans+=min(k,l-b.back());
    cout<<(int)(round(2*(a[0]+l-ans)))<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
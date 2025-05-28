#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = x[0];
    for(int i=0; i<n; i++){
        ans+=max(0LL,x[i]-x[i-1]);
    }
    cout<<ans<<"\n";
}
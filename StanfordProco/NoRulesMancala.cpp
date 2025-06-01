#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int m, n;
    cin>>m>>n;
    vector<int> x(n+1,0);
    for(int i=0; i<m; i++){
        int l, r,k;
        cin>>l>>r>>k;
        x[l]+=k,x[r+1]-=k;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(i>0)x[i] += x[i-1];
        ans = max(ans,x[i]);
    }
    cout<<ans<<"\n";
}
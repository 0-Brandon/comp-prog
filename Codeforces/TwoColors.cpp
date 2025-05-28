#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> x(m);
    for(int i=0; i<m; i++)cin>>x[i];
    sort(x.begin(),x.end());
    int id = m;
    int su =0;
    int ans = 0;
    int nc = 0;
    for(int i=0; i<m; i++){
        if(x[i]==n)nc++;
        while(id>0&&x[id-1]+x[i]>=n)su+=x[id-1],id--;
        if(x[i]*2>=n)su-=x[i],id++;
        ans+=(m-id)*x[i]+su-(m-id)*(n-1);
        if(x[i]*2>=n)su+=x[i],id--;
    }
    cout<<ans-2*nc*(m-1)<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
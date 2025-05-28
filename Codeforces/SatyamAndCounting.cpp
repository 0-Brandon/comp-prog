#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int>> x(n+1,vector<int>(2,0));
    int ans = 0;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        x[a][b]++;
    }
    for(int i=0; i<=n; i++){
        if(x[i][0]&&x[i][1]){
            ans+=n-2;
        }
        if(i<=n-2&&x[i][0]&&x[i+1][1]&&x[i+2][0])ans++;
        if(i<=n-2&&x[i][1]&&x[i+1][0]&&x[i+2][1])ans++;
    }
    cout<<ans<<"\n";
    //cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("threesum.out","w",stdout);
    freopen("threesum.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    vector<int> x(n);
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> occ(2e6+2,0);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(j-i>=2){
                if(1e6-x[i]-x[j]>=0&&1e6-x[i]-x[j]<=2e6)ans[i][j]+=occ[1e6-x[i]-x[j]];
            }
            occ[x[j]+1e6]++;
        }
        for(int j=i+1; j<n; j++){
            occ[x[j]+1e6]--;
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            ans[i][j]+=ans[i+1][j]+ans[i][j-1]-ans[i+1][j-1];
        }
    }
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        cout<<ans[--a][--b]<<"\n";
    }
}
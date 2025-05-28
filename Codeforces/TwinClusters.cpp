#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int k;
    cin>>k;
    vector<int> pr((1<<(k+1)+1),0);
    vector<int> hi((1<<k)+1,-1);
    hi[0]=0;
    vector<pair<int,int>> low((1<<k)+1,{-1,-1});
    vector<int> ans;
    int mask = (1<<k)-1;
    for(int i=0; i<1<<(k+1); i++){
        int a;
        cin>>a;
        pr[i+1]=pr[i]^a;
        if(hi[pr[i+1]>>k]!=-1){
            int z = (pr[hi[pr[i+1]>>k]]^pr[i+1])&mask;
            if(low[z].first!=-1){
                ans = {low[z].first,low[z].second,hi[pr[i+1]>>k],i+1};
            }
            low[z]={hi[pr[i+1]>>k],i+1};
        }
        hi[pr[i+1]>>k]=i+1;
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0]+1<<" "<<ans[1]<<" "<<ans[2]+1<<" "<<ans[3]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
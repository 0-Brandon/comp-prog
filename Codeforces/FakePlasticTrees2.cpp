#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k, L, R;
    cin>>n>>k>>L>>R;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> sub(n,0);
    vector dp(n,vector<vector<int>>(k+1));
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        sub[i] = 1;
        dp[i][0].push_back(x[i]);
        for(auto& c:adj[i])if(c^p){
            dfs(dfs, c,i);
            vector<vector<int>> tmp(k+1);
            //dp[c][cuts] : sums
            for(int j=0; j<=k&&j<sub[i]; j++){
                for(int l=0; l+j<=k&&l<sub[c]; l++){
                    for(auto& ii:dp[i][j]){ 
                        bool b = false;
                        for(auto& kk:dp[c][l]){
                            if(ii+kk<=R)tmp[j+l].push_back(ii+kk); //no cut
                            if(kk>=L&&kk<=R)b=true;
                        }
                        if(b&&l+j+1<=k)tmp[l+j+1].push_back(ii); //cut
                    }
                }
            }
            sub[i]+=sub[c];
            for(int j=0; j<=k&&j<sub[i]; j++){
                sort(tmp[j].begin(),tmp[j].end());
                dp[i][j].clear();
                int sz = 0;
                for(auto& l:tmp[j]){
                    while(sz>1&&l-dp[i][j][sz-2]<R-L) sz--,dp[i][j].pop_back();
                    dp[i][j].push_back(l);
                    sz++;
                }
            }
        }
    };
    dfs(dfs,0,0);
    vector<int> ans(n);
    for(int i=0; i<=k; i++){
        for(auto& j:dp[0][i]){
            if(j>=L&&j<=R)ans[i] = true;
        }
    }
    for(int i=0; i<=k; i++){
        if(ans[i])cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
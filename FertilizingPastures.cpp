#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n, t;
    cin>>n>>t;
    vector<int> subr(n);
    vector<int> par(n);
    vector<vector<int>> child(n);
    for(int i=0; i<n-1; i++){
        cin>>par[i+1]>>subr[i+1];
        par[i+1]--;
        child[par[i+1]].push_back(i+1);
    }
    vector<int> sub(n,1);
    vector<vector<int>> dp(2,vector<int>(n,0));
    vector<int> mdist(n,0);
    for(int i=n; i-->0;){
        for(auto& c:child[i]){
            subr[i]+=subr[c];
            sub[i]+=sub[c];
            mdist[i] = max(mdist[i],mdist[c]+1);
        }
        sort(child[i].begin(),child[i].end(),[&](int i, int j){return sub[i]*subr[j]<sub[j]*subr[i];});
        int accsub = 0;
        for(auto& c:child[i]){
            dp[0][i]+=dp[0][c] + subr[c] + subr[c]*2*accsub;
            accsub+=sub[c];
        }
        int accsum=0;
        accsub=0;
        if(child[i].size()!=0)dp[1][i] = LLONG_MAX;
        for(int c = child[i].size(); c-->0;){
            if(mdist[child[i][c]]+1 == mdist[i]){
                dp[1][i] = min(dp[1][i], 
                dp[0][i] -
                2*accsum*sub[child[i][c]] + 
                2*accsub*subr[child[i][c]] + 
                dp[1][child[i][c]]-dp[0][child[i][c]]);
            }
            accsub+=sub[child[i][c]];
            accsum+=subr[child[i][c]];
        }
    }
    if(t==1){
        cout<<2*(n-1)-mdist[0]<<" "<<dp[1][0];
    }else{
        cout<<2*(n-1)<<" "<<dp[0][0];
    }
}
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//maximum
//we want to eliminate continuous segments... just eliminate entire loops. leftover can we removed from one loop, n-leftover
//minimum
//if its even sized, we can eliminate entire loop in n/2
//if its odd sized, we can end up with a->b in n/2, add one for eliminate
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){cin>>x[i];x[i]--;}
    vector<int> comps;
    vector<bool> vis(n);
    auto dfs = [&](auto& dfs, int i)->void {
        vis[i]=true;
        comps.back()++;
        int c = x[i];
        if(!vis[c])dfs(dfs,c);
    };
    for(int i=0; i<n; i++){
        if(!vis[i]){
            comps.push_back(0);
            dfs(dfs,i);
        }
    }
    int ma = 0,mi=0;
    map<int,int> mp;
    bitset<(signed)(1e6+10)>dp(1);
    for(int i=0; i<comps.size(); i++){
        mp[comps[i]]++;
    }
    for(auto& [i,cnt]:mp){
        for(int j=1; j<=cnt; j*=2){
            cnt-=j;
            dp|=dp<<(j*i);
        }
        if(cnt)dp|=dp<<cnt*i;
    }
    if(dp[k])mi = k;
    else{
        mi=k+1;
    }
    int pairs = 0;
    // 2 3
    int c1 = 0;
    for(auto& c:comps){
        pairs+=c%2;
        c1+=c/2;
    }
    ma+=2*min(k,c1);
    k-=min(k,c1);
    ma+=min(k,pairs);
    cout<<mi<<" "<<ma<<"\n";
}
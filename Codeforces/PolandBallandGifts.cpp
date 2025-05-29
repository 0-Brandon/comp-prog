#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//maximum
//we want to eliminate continuous segments... just eliminate entire loops. leftover can we removed from one loop, n-leftover
//minimum
//if its even sized, we can eliminate entire loop in n/2
//if its odd sized, we can end up with a->b in n/2, add one for eliminate
#include <bits/stdc++.h>

using namespace std;

int main(){
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
    int mi = 0, ma = 0;
    map<int,int> mp;
    vector<bitset<(int)(1e5+10)>> dp(k+1,1);
    for(auto& c:comps)mp[c]++;
    vector<pair<int,int>> items;
    for(auto& [i,cnt]:mp){
        for(int j=1; j<cnt; j*=2){
            items.push_back(make_pair(j*i,j));
            cnt-=j;
        }
        if(cnt)items.push_back(make_pair(i*cnt,cnt));
    }
    //  for(int i=10;i>=0;i--)cout<<dp[i]<<" ";
    //number of weights is
    //dp[i][j] is whether you can make j with i weight
    for(auto& [c,w]:items){
        for(int i=0; i<=k; i++){
            if(i+w<=k)dp[i+w]|=dp[i]<<c;
        }
    }
    bool b = false;
    for(int i=0; i<=k; i++)if(dp[i][k])b = true;
    if(b)mi = k;
    else{
        mi=k+1;
    }
    int pairs = 0;
    partition(comps.begin(),comps.end(),[&](int i){return i%2==1;});
    // 2 3
    for(auto& c:comps){
        if(k-c/2>=0){
            ma+=c;
            k-=c/2;
            if(k%2==1)pairs++;
            if(k%2==1)ma--;
        }
        else{
            ma+=k*2;
            k=0;
        }
    }
    if(k>0)ma+=min(k,pairs);
    cout<<mi<<" "<<ma<<"\n";
}
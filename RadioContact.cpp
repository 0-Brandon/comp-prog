#include <bits/stdc++.h>

using namespace std;

pair<int,int> step(pair<int,int> x,char i){
    if(i=='N')x.second++;
    if(i=='W')x.first--;
    if(i=='S')x.second--;
    if(i=='E')x.first++;
    return x;
}
int dist(pair<int,int> x, pair<int,int> y){
    return (y.second-x.second)*(y.second-x.second) + (x.first-y.first)*(x.first-y.first);
}
int main(){
    freopen("radio.in","r",stdin);
    freopen("radio.out","w",stdout);
    int n, m;
    int sfx, sfy, sbx, sby;
    cin>>n>>m>>sfx>>sfy>>sbx>>sby;
    string fj, be;
    cin>>fj>>be;
    vector<pair<int,int>> posf, posb;
    posf.push_back({sfx,sfy});
    posb.push_back({sbx,sby});
    for(int i=1; i<=n; i++)posf.push_back(step(posf[i-1],fj[i-1]));    
    for(int i=1; i<=m; i++)posb.push_back(step(posb[i-1],be[i-1]));
    vector<vector<int>> dp(n+1, vector<int> (m+1, INT_MAX));
    //base cases xdxdxd
    dp[0][0]=0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i>0)dp[i][j]=min(dp[i][j], dp[i-1][j]);
            if(j>0)dp[i][j]=min(dp[i][j], dp[i][j-1]); 
            if(i>0&&j>0)dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
            if(!(i==0&&j==0))dp[i][j]+=dist(posf[i],posb[j]);
        }
    }
    cout<<dp.back().back();
}
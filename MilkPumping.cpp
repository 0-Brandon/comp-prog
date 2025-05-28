#include <bits/stdc++.h>

using namespace std;
//for some ereason in sample case adj[0] iterates to node 2?
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,pair<int,int>>>> adj(n); // node, cost, flow
    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        a--,b--;
        adj[a].push_back({b,{c,d}});
        adj[b].push_back({a,{c,d}});
    }
    vector<vector<int>> dp(n,vector<int>(1001,1e9));//node, flow represents min cost
    priority_queue<pair<int,pair<int,int>>> pq; //cost, node,  flow
    pq.push({0,{0,1000}});
    dp[0][1000]=0;
    int ret = -1;
    while(!pq.empty()){
        auto& cur = pq.top(); pq.pop();
        if(cur.second.first==n-1){
            ret=max(ret,(int)(1000000*((cur.second.second)/(double)dp[n-1][cur.second.second])));
            continue;
        }
        for(auto& i:adj[cur.second.first]){
            int nf = min(i.second.second, cur.second.second);
            int nc = dp[cur.second.first][cur.second.second]+i.second.first;
            int nd = i.first;
            if(cur.second.first==0&&i.first==2)cout<<nf<<" "<<nc<<"asdf";
            if(nc<dp[nd][nf]){
                dp[nd][nf]=nc;
                pq.push({-nc,{nd,nf}});
            }
        }
    }
    cout<<ret;
}
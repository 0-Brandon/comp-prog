#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<vector<int>> radj(n);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    priority_queue<int> pq;
    for(int i=0;i<n-1; i++){
        //calculate answer
        while(!pq.empty()&&pq.top()>=-i)pq.pop();
        cout<<pq.empty();
        //calculate dp[i]
        if(i>0)dp[i] = dp[i-1]+1;
        for(auto& j:radj[i]){
            dp[i] =min(dp[i],dp[j]+1);
        }
        //add edges that start from i and pass over
        for(auto& c:adj[i]){
            pq.push(dp[i]+1-c);//elsie time, node
        }
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}


//iterate on bessie position
//we maintain dp[i] up to bessie position
//it is minimum tiume for elsie to get to i
//edges that go from before bessie to after bessie we keep track of
//we add the edges to some sort of structure (poriority_queue sorted by elsie time)
//for every cross bessie destination, we track the time elsie can get there
//if bessie gets there first, we remove it from stucutre
//ans is yes if strucutre is non zero, no otherwise



#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 1e15;
signed main(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n,vector<int>(3));
    vector<int> x(n);
    string s;cin>>s;
    for(int i=0; i<n; i++)cin>>x[i];
    //min to activate subtree of n
    //0 is parent updates it
    //1 is alr on
    //2 means it will update parent
    auto dfs = [&](auto dfs, int i, int p)->void {
        int s0 = 0, s1 = 0;
        for(auto& c:adj[i]){
            if(c==p)continue;
            dfs(dfs,c,i);
            s0+=dp[c][0];
            s1+=dp[c][1];
            s0 = min(s0,inf);
            s1 = min(s1,inf);
        }
        //we are on and update parent, all neighboring people become 0
        if(s[i]=='Y'){
            dp[i][2] = x[i]+s0;
        }
        else{
            //we update parent, not on initially
            //x[i]+min dp[c][2] +rest dp[c][0]
            dp[i][2]=inf;
            for(auto& c:adj[i]){
                if(c==p)continue;
                if(dp[c][2]>=inf)continue;
                dp[i][2] = min(dp[i][2],x[i]+s0-dp[c][0]+dp[c][2]);
            }
        }
        //parent updates us, we may update children
        dp[i][0] = min(x[i]+s0,s1);
        if(adj[i].size()==1&&i!=0){
            //leaf
            if(s[i]=='N')dp[i][2]=inf, dp[i][1]=inf, dp[i][0]=0;
            else dp[i][2] = x[i], dp[i][1]=0,dp[i][0]=0;
        }
        dp[i][1]=inf;
        if(s[i]=='Y')dp[i][1]=min(s1,x[i]+s0);
        else if(s1<inf) for(auto& c:adj[i]){
                if(c==p)continue;
                if(dp[c][2]>=inf)continue;
                dp[i][1] = min(dp[i][1],s1-dp[c][1]+dp[c][2]);
            }
        dp[i][1]=min(dp[i][1],dp[i][2]);
    };
    dfs(dfs,0,-1);
    cout<<dp[0][1]<<"\n";
}
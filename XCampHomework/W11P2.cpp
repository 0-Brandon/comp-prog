#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> p1(n,-1);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;a--,b--;adj[a].push_back(b);adj[b].push_back(a);
        p1[a]=b;
    }
    int r1= 0;
    for(int i=0; i<n; i++)if(p1[i]==-1)r1=i;
    vector<int> e(n,false);
    int m;cin>>m;
    vector<vector<int>> adj1(n);
    vector<int> p2(n);
    for(int i=0; i<m-1; i++){
        int a, b;cin>>a>>b;a--,b--;adj1[a].push_back(b);
        adj1[b].push_back(a);
        p2[a]=b;
        e[a]=true;
    }
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    vector<int> depth(n);depth[r1]=0;
    for(int de =0; de<n; de++)for(int i=0; i<n; i++)if(i!=r1)depth[i] = depth[p1[i]]+1;
    for(int d=n-1; d>=0; d--){
        for(int c=0; c<n; c++){ //c
            if(depth[c]!=d)continue;
            if(e[c]){dp[c][c]=true;continue;}
            for(int c1=c; c1<n; c1++){ //c1
                if(!e[c1])continue;
                dp[c][c1]=true;
                for(auto& ca:adj[c])if(ca!=p1[c]){//ca
                    bool catocb = false;
                    for(auto& cb:adj1[c1])if(cb!=p2[c1]){//cb
                        if(dp[ca][cb])catocb=true;
                    }
                    dp[c][c1]=dp[c][c1]&catocb;
                }
            }
        }
    }
    vector<pair<int,int>> ans;
    vector<int> me(n,-1);
    me[r1]=r1;
    for(int d=0; d<n; d++){
        for(int i=0; i<n; i++){
            if(depth[i]!=d)continue;
            for(int c=0; c<n; c++){
                if(p2[c]==me[p1[i]]&&dp[i][c]){
                    me[i]=c;
                    if(i!=me[i])ans.push_back({i,me[i]});
                    break;
                }
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto&[i,j]:ans){
        cout<<i+1<<" "<<j+1<<"\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
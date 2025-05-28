#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int,int> depth;
map<int,vector<int>> adj;
int ans= INT_MAX;
//doesn't work
int dfs(int num, int d=0, int par = -1){
    depth[num]=d;
    cout<<num<<" "<<par<<"\n";
    int ret = INT_MAX;
    for(int i=0; i<64; i++){
        if(num& (1<<i)){
            for(auto& j:adj[i]){
                if(j==par||j==i)continue;
                if(depth[j]!=-1){
                    ret = min(ret, d-depth[j]+1);
                }
                else{
                    ret=min(ret,dfs(j,d+1, num));
                }
            }
        }
    }
    return ret;
}
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        depth[x[i]]=-1;
        for(int j=0; j<64; j++){
            if(x[i]&(1<<j))adj[j].push_back(x[i]);
        }
    }
    for(int i=0; i<n; i++){
        if(depth[x[i]]==-1)ans=min(ans,dfs(x[i]));
    }
    cout<<ans;
}
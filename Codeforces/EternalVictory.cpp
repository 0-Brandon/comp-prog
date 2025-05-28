#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<pair<int,int>>> adj;
vector<int> ans;
void dfs(int i=0, int p=0){
    for(auto& [c,d]:adj[i])if(c!=p){
        ans[c]=ans[i]+d;
        dfs(c,i);
    }
}
signed main(){
    int n;
    cin>>n;
    int tot = 0;
    adj.resize(n);
    ans.resize(n);
    ans[0]=0;
    int m=0;
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        tot+=c;
    }
    dfs(0);
    for(auto& i:ans)m=max(i,m);
    cout<<(tot*2-m);
}
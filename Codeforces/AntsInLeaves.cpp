#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> ca;
void dfs(int i, int p, int d){
    int f=true;
    for(auto& c:adj[i]){
        if(c==p)continue;
        f=false;
        if(p==-1)ca.push_back(vector<int>());
        dfs(c,i,d+1);
    }
    if(f)ca.back().push_back(d);
}
int main(){
    int n;
    cin>>n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    dfs(0,-1,0);
    for(auto& i:ca){
        sort(i.begin(),i.end());
        for(int j=1; j<i.size(); j++){
            i[j]=max(i[j],i[j-1]+1);
        }
        ans=max(ans,i.back());
    }
    cout<<ans<<"\n";
}
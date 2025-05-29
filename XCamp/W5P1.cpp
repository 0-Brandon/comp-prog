#include <bits/stdc++.h>

using namespace std;
double ans=0;
vector<vector<int>> adj;
void dfs(int i, int  p, int d){
    ans=ans+1.0/d;
    for(auto& c:adj[i]){
        if(c!=p){
            dfs(c,i,d+1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    adj.resize(n);
    for(int i=0; i<n-1; i++){
        int a, b; cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);adj[b].push_back(a);
    }
    dfs(0,0,1);
    cout<<setprecision(15)<<ans<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int a;cin>>a;a--;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    auto dfs = [&](auto dfs, int i,int p)->int {
        int m=-1;
        for(auto& c:adj[i]){
            if(c==p)continue;
            dfs(dfs,c,i);
            if(m==-1||x[c]<x[m])m=c;
        }
        if(m==-1)return 0;
        if(i==0){
            return x[i]+x[m];
        }
        if(x[m]>x[i]){
            return x[i]+=(x[m]-x[i])/2;
        }
        return x[i]=x[m];
    };
    cout<<dfs(dfs,0,0)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){solve();}
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> sub(n);
    int count = 0;
    auto dfs = [&](auto dfs, int i, int p, int l)-> int {
        sub[i]=1;
        for(auto& c:adj[i]){
            if(c==p)continue;
            sub[i]+=dfs(dfs,c,i,l);
        }
        if(sub[i]>=l&&count<k){
            count++;
            sub[i]=0;
        }
        return sub[i];
    };
    auto ok = [&](int limit){
        count = 0;
        dfs(dfs,0,0,limit);
        if(sub[0]<limit||count<k)return false;
        return true;
    };
    int l = -1, h = n;
    while(l<h){
        int mid = l+(h-l+1)/2;
        if(ok(mid)){
            l=mid;
        }
        else{
            h=mid-1;
        }
    }
    cout<<l<<"\n";
} 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
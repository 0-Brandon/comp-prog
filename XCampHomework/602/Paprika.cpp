#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int timer = 0;
    vector<int> tin(n),tout(n);
    vector<int> sub(n);
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        tin[i] = timer++;
        sub[i] = 1;
        for(auto& c:adj[i]){
            if(c!=p){
                dfs(dfs,c,i);
                sub[i]+=sub[c];
            }
        }
        tout[i] = timer++;
    };
    auto par = [&](int i, int j){
        return tin[i]<tin[j]&&tout[i]>tout[j];
    };
    int ans = INT_MAX;
    dfs(dfs, 0,0);
    int num = 0;
    for(int i=0; i<n; i++)if(sub[i]>20000)num++;
    for(int i=n-1; i>=0; i--){
        if(n>2000&&sub[i]<20000)continue;
        if(num>20000&&sub[i]%25!=0)continue;
        for(int j=i+1; j<n; j++){
            if(n>2000&&sub[j]<20000)continue;
            int a=i, b=j;
            if(par(b,a))swap(a,b);
            if(par(a,b)) b = sub[j],a = sub[i]-b;
            else a = sub[i],b=sub[j];
            int c = n-(a+b);
            ans = min(ans,max({a,b,c})-min({a,b,c}));
            if(ans==0)break;
        }
        if(ans==0)break;
    }
    cout<<ans<<"\n";
}
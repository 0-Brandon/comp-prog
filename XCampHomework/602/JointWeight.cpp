#include <bits/stdc++.h>
#define int long long
constexpr int mod = 10007;
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    int ans1=0, ans2=0;
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        vector<int> ch;
        for(auto& c:adj[i]){
            ch.push_back(x[c]);
        }
        sort(ch.rbegin(),ch.rend());
        if(ch.size()>=2)ans1 = max(ch[0]*ch[1],ans1);
        int cur = 0;
        for(auto& i:ch){
            ans2+=cur*i%mod;
            ans2%=mod;
            cur=(cur+i)%mod;
        }
        for(auto& c:adj[i])if(c!=p)dfs(dfs,c,i);
    };
    dfs(dfs,0,0);
    cout<<ans1<<" "<<ans2*2%mod<<"\n";
}
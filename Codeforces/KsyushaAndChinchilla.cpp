#include <bits/stdc++.h>

using namespace std;

bool f=false;
vector<vector<pair<int,int>>> adj;
vector<int> sub;
vector<int> ans;
int dfs(int i, int p=-1){
    for(auto& [c,id]:adj[i])if(c!=p){
        int l = dfs(c,i);
        if(l>3){f=true;return 0;}
        if(l==3)ans.push_back(id);
        else sub[i]+=l;
    }
    if(sub[i]!=2&&sub[i]!=0&&sub[i]!=1)f=true;
    return sub[i]+1;
}
void solve(){
    int n;
    f=false;
    cin>>n;
    adj.assign(n,vector<pair<int,int>>());
    sub.assign(n,0);
    ans.clear();
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    dfs(0);
    if(f){cout<<"-1\n";return;}
    if(sub[0]!=2){cout<<"-1\n";return;}
    cout<<ans.size()<<"\n";
    for(auto& i:ans)cout<<i+1<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
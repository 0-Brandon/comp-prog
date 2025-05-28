
#include <bits/stdc++.h>

using namespace std;

struct shesh{
    vector<int> a;
    int idx=0;
    void add(int i, int d){
        a[i]+=d;
        if(a[i]>a[idx])idx=i;
        if(a[i]==a[idx])idx=max(i,idx);
    }
};
shesh& merge(shesh& c, shesh& b){
    if(c.a.size()>b.a.size())swap(c,b);
    for(int i=0; i<c.a.size(); i++){
        b.add(b.a.size()-i-1,c.a[c.a.size()-i-1]);
    }
    return b;
}
vector<int> ans;
vector<vector<int>> adj;
vector<shesh> x;
void dfs(int i, int p=-1){
    x[i].a=vector<int>(0);
    for(auto& c:adj[i])if(c!=p){
        dfs(c,i);
        x[i]=std::move(merge(x[c],x[i]));
    }
    x[i].a.push_back(0);
    x[i].add(x[i].a.size()-1,1);
    ans[i]=x[i].a.size()-x[i].idx-1;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    x.resize(n);
    adj.assign(n,vector<int>());
    ans.assign(n,0);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    for(auto& i:ans)cout<<i<<"\n";
}

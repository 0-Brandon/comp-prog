#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> child, bounds;
vector<vector<int>> adj;
int ansnum=0;
vector<int> ans;
pair<int,int> merge(pair<int,int>& x, pair<int,int> y){
    int l = max(x.first,y.first);
    int r = min(x.second,y.second);
    return {l,r};
}
int calc(pair<int,int> b, pair<int,int> x){
    if(x.second<x.first){
        int ans = INT_MAX;
        int m = (x.first+x.second)/2;
        if(b.first<=m&&b.second>=m)ans = max(abs(m-x.first),abs(m-x.second));
        else{
            m=b.first;
            ans = min(ans,max(abs(m-x.first),abs(m-x.second)));
            m=b.second;
            ans = min(ans,max(abs(m-x.first),abs(m-x.second)));
        }
        return ans;
    }
    pair<int,int> t = merge(b,x);
    return t.first-t.second;
}
pair<int,int> dfs(int i, int p){
    pair<int,int> children = {-1,INT_MAX};
    for(auto&c:adj[i])if(c!=p){
        children = merge(children,dfs(c,i));
    }
    child[i] = children;
    pair<int,int> temp = merge(bounds[i],children);
    ansnum = max(ansnum,calc(bounds[i],child[i]));
    return temp;
}
void close(int p, pair<int,int> b, int i){
    if(b.first<=ans[p]&&b.second>=ans[p])ans[i]=ans[p];
    else{
        if(b.second<=ans[p])ans[i] = b.second;
        else ans[i] = b.first;
    }
}
void dfs2(int i, int p){
    for(auto& c:adj[i]){
        if(c!=p){
            close(i,bounds[c],c);
            dfs2(c,i);
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
int t, b;
cin>>t>>b;
while(t--){
    int n;
    cin>>n;
    ansnum=0;
    child.assign(n,{-1,INT_MAX});
    ans.assign(n,0);
    adj.assign(n,vector<int>());
    bounds.clear();
    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        a--;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    for(int i=0; i<n; i++){
        int l, r;
        cin>>l>>r;
        bounds.push_back({l,r});
    }
    dfs(0,-1);
    int l = child[0].first,r=child[0].second;
    int m = (l+r)/2;
    if(bounds[0].first<=m&&m<=bounds[0].second)ans[0]=m;
    else{
        if(bounds[0].second<m)ans[0] = bounds[0].second;
        else ans[0] = bounds[0].first;
    }
    dfs2(0,-1);
    cout<<ansnum<<"\n";
    if(b==1){
        for(int i=0; i<n; i++){
            cout<<ans[i];
            if(i!=n-1)cout<<" ";
        }
        cout<<"\n";
    }
}
}
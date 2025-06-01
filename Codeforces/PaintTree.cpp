#include <bits/stdc++.h>

using namespace std;

bool up(pair<int,int> i){
    return i.second>0 or (i.second==0 and i.first>=0);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pair<int,int>> points;
    map<pair<int,int>,int> idx;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        points.push_back({a,b});
        idx[make_pair(a,b)] = i;
    }
    map<pair<int,int>,bool> used;
    vector<int> ans(n);
    auto dfs = [&](auto& dfs, int i, int pa)->void {
        vector<pair<int,int>>& pts = points;
        sort(pts.begin(),pts.end(),[&](auto i, auto j){return up(i)==up(j)?i.first*j.second>i.second*j.first:up(i)<up(j);});
        int p = 0;
        for(auto& c:adj[i]){
            if(i==pa)continue;
            while(used[pts[p]])p++;
            ans[c] = idx[pts[p]];
            used[pts[p]]=true;
            dfs(dfs,c,i);
        }
    };
    dfs(dfs,0,0);
    for(auto& i:ans)cout<<i<<" ";
}
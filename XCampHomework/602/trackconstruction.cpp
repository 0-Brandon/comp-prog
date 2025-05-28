#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, m;
vector<vector<pair<int,int>>> adj;
int mid;
pair<int, int> dfs(int i, int p) {
    int done = 0;
    vector<int> left;
    for (auto &[c,w]: adj[i]) {
        if(c == p)continue;
        auto ret = dfs(c, i);
        done += ret.first;
        int d = ret.second + w;
        if(d >= mid) { 
            done++;
        } else {
            left.push_back(d);
        }
    }
    sort(left.begin(), left.end());
    int po = 0;
    int best = 0;
    while(po+1<left.size()) {
        if(left[po] + left.back() >= mid) {
            done++;
            po++;
            left.pop_back();
        } else {
            best = max(best,left[po]);
            po++;
        }
    }
    if(po<left.size())best = max(best,left.back());
    return {done, best};
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    adj.resize(n);
    int l=-1,h=1;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w; u--,v--;
        h+=w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    while(l<h){
        mid = l+(h-l+1)/2;
        if(dfs(0,0).first>=m)l= mid;
        else h = mid-1;
    }
    cout<<l;
}

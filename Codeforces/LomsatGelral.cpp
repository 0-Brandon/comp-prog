#include <bits/stdc++.h>
#define int long long 

using namespace std;
vector<int> col;
vector<vector<int>> adj;
vector<int> ans;
vector<map<int,int>> cnt;
vector<map<int,int>> sm;
void merge(int a, int b){
    if(cnt[a].size()<cnt[b].size()){
        swap(cnt[a],cnt[b]);
        swap(sm[a],sm[b]);
    }
    for(auto& [colo,occ]:cnt[b]){
        sm[a][cnt[a][colo]]-=colo;
        cnt[a][colo]+=occ;
        sm[a][cnt[a][colo]]+=colo;
    }
}
void dfs(int i=0, int p=-1){
    cnt[i][col[i]]++;sm[i][1]+=col[i];
    for(auto& c:adj[i])if(c!=p){
        dfs(c,i);
        merge(i,c);
    }
    ans[i]=sm[i].rbegin()->second;
}
signed main(){
    int n;
    cin>>n;
    col.resize(n);
    ans.resize(n);
    adj.resize(n);
    cnt.resize(n);
    sm.resize(n);
    for(int i=0; i<n; i++){
        cin>>col[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for(auto& i:ans){
        cout<<i<<" ";
    }
}
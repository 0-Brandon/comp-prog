#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
vector<vector<int>> adj;
vector<set<int>> s;
void merge(set<int>& a, set<int>& b){
    if(a.size()<b.size())swap(a,b);
    for(auto& i:b)a.insert(i);
}
void dfs(int i=0,int p=0){
    for(auto& c:adj[i])if(c!=p){
        dfs(c,i);
        merge(s[i],s[c]);
    }
    ans[i] = s[i].size();
}
int main(){
    int n;
    cin>>n;
    s.resize(n);ans.resize(n);
    adj.resize(n);
    for(int i=0; i<n; i++){
        int c;cin>>c;s[i].insert(c);
    }
    for(int i=0; i<n-1; i++){
        int a, b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    for(auto& i:ans)cout<<i<<" ";
}
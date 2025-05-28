#include <bits/stdc++.h>

using namespace std;
vector<int> x;
vector<vector<int>> adj;
vector<int> ans;
vector<vector<int>> d;
void merge(vector<int>& i, vector<int>& j){
    if(i.size()<j.size())i.swap(j);
    for(int& k:j){
        i.insert(lower_bound(i.begin(),i.end(),k),k);
    }
}
void dfs(int i=0, int p=0){
    d[i].push_back(x[i]);
    for(auto& c:adj[i])if(c!=p){
        dfs(c,i);
        merge(d[i],d[c]);
    }
    ans[i]=distance(lower_bound(d[i].begin(),d[i].end(),x[i]),d[i].end())-1; 
}
int main(){
    int n;
    cin>>n;
    x.assign(n,0);
    d.resize(n);
    ans.resize(n);
    adj.resize(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=1; i<n; i++){
        int a;
        cin>>a;
        a--;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }
    dfs();
    for(auto& i:ans)cout<<i<<"\n";
}
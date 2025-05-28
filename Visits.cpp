/*
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> components;
vector<bool> visited;
stack<int> stackx;
int compnum = 0;
void dfs(int& i, vector<vector<int>>& adj){
    if(visited[i]) return;
    visited[i]=true;
    for(auto&j: adj[i])if(!visited[j])dfs(j,adj);
    stackx.push(i);
}
void sccdfs(int& i, vector<vector<int>>& radj){
    if(visited[i]) return;
    visited[i]=true;
    components[compnum].push_back(i);
    for(auto&j: radj[i])if(!visited[j])sccdfs(j,radj);
}

long long solve(vector<int>& component, vector<long long int>& x){
    long long int  s=0, m=1e9;
    for(auto& i: component){
        s+=x[i];
        m = min(m,1LL*x[i]);
    }
    if(s==m) return m;
    else return s-m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> adj(n), radj(n);
    vector<long long int> x(n, 0);
    components.resize(n);
    visited.resize(n, false);
    for(int i=0; i<n; i++){
        int a;
        long long int b;
        cin>>a>>b;
        a--;
        adj[i].push_back(a);
        radj[a].push_back(i);
        x[i]=b;
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, adj);
        }
    }
    fill(visited.begin(),visited.end(),false);
    while(!stackx.empty()){
        int cur = stackx.top();
        stackx.pop();
        if(visited[cur])continue;
        sccdfs(cur, radj);
        compnum++;
    }
    long long int ans = 0;
    for(int i=0; i<compnum; i++){
        ans+=solve(components[i], x);
    }
    cout<<ans<<"\n";
}
*/
#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n):e(n,-1){}
    int p(int i){
         return e[i]<0?i:e[i]=p(e[i]);
    }
    bool merge(int a, int b){
        a=p(a), b=p(b);
        if(a==b) return false;
        if(e[a]>e[b])swap(a,b);
        e[a]+=e[b];
        e[b]=a;
        return true;
    }
};
int main(){
    int n;
    cin>>n;
    vector<tuple<int,int,int>> edges;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        a--;
        edges.push_back({b,i,a});
    }
    sort(edges.rbegin(),edges.rend());
    DSU dsu(n);
    long long ans = 0;
    int count = 0;
    for(auto& [i,j,k]:edges){
        if(dsu.merge(j,k)){
            ans+=i;
            count++;
        }
    }
    cout<<ans<<"\n";
}

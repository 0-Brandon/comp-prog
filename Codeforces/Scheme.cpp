#include <bits/stdc++.h>

using namespace std;
int idx=0;
vector<int> c;
vector<int> visited;
bool g=false;
vector<int> ind;
    int n;
set<pair<int,int>> ans;
vector<int> o;
void dfs(int i){
    //find node to connect
    int slow=c[i], fast=c[c[i]];
    while(slow!=fast)slow=c[slow],fast=c[c[fast]];
    ans.insert({slow,o[idx++]});
    if(idx>=o.size())return;
    dfs(o[idx-1]);
}
void paint(int i){
    if(visited[i])return;
    int cnt = 1;
    visited[i]=1;
    int x=c[i];
    while(visited[x]!=1){
        if(ind[x]>1)cnt=-500;
        cnt++;
        visited[x]=1,x=c[x];
    }
    if(cnt==n)g=true;
}
int main(){
    cin>>n;
    visited.resize(n);
    ind.resize(n,0);
    c.resize(n);
    for(int i=0; i<n; i++){
        cin>>c[i];
        c[i]--;
        ind[c[i]]++;
    }
    for(int i=0; i<n; i++)if(ind[i]==0)paint(i);
    for(int i=0; i<n; i++)if(!visited[i]){
        o.push_back(i);
        paint(i);
    }
    if(g){cout<<0<<"\n";return 0;}
    for(int i=0; i<n; i++)if(ind[i]==0)o.push_back(i);
    if(o.size())dfs(o.back());
    cout<<ans.size()<<"\n";
    for(auto& i:ans){
        cout<<i.first+1<<" "<<i.second+1<<"\n";
    }
}
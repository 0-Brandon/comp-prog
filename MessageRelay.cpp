#include <bits/stdc++.h>

using namespace std;

int cnt=0;
vector<int> a, visited;
void dfs(int i){
    visited[i]=1;
    if(a[i]==-1){visited[i]=3;return;}
    if(visited[a[i]]==1){visited[i]=2,cnt++;return;}
    if(visited[a[i]]==0){
        dfs(a[i]);
    }
    visited[i]=visited[a[i]];
    if(visited[i]==2)cnt++;
}
int main(){
    freopen("relay.in","r",stdin);
    freopen("relay.out","w",stdout);
    int n;
    cin>>n;
    a.resize(n,0),visited.resize(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i=0; i<n; i++){
        if(visited[i]==0)dfs(i);
    }
    cout<<n-cnt<<'\n';
}
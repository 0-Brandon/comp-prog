#include <bits/stdc++.h>

using namespace std;
vector<bool> visited;
vector<int> ord, cur, c, a;
vector<vector<int>> radj;
void bdfs(int i){
    if(visited[i])return;
    visited[i]=true;
    cur.push_back(i);
    for(auto& c:radj[i]){
        bdfs(c);
    }
}
void find(int i){
    int s = a[i], f = a[a[i]];
    while(s!=f)s=a[s],f=a[a[f]];
    s=i;
    while(s!=f)s=a[s],f=a[f];
    int m = s;
    f=a[s];
    while(s!=f)m = (c[f]<c[m])?(f):(m), f = a[f];
    bdfs(m);
}
void solve(){
    int n;
    cin>>n;
    visited.assign(n,false);
    ord.clear();
    radj.assign(n,vector<int>());
    a.assign(n,-1);
    c.resize(n);
    for(int i=0; i<n; i++){
        int b;cin>>b;b--;
        a[i]=b;
        radj[b].push_back(i);
    }
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            cur.clear();
            find(i);
            reverse(cur.begin(),cur.end());
            for(auto& j:cur)ord.push_back(j);
        }
    }
    for(auto& i:ord)cout<<i+1<<" ";
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)
    solve();
}
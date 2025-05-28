#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m, k;
vector<vector<int>> adj,radj;
vector<int> num;
bool f= false;
void dfs(int i, vector<int>& ord, vector<int>& visited, int t){
    if(visited[i]==2)return;
    visited[i]=1;
    for(auto& c:adj[i]){
        if(num[c]<=t){
            if(visited[c]==1){
                f=true;
                return;
            }
            dfs(c, ord,visited,t);
        }
    }
    visited[i]=2;
    ord.push_back(i);
}
bool ok(int t){
    vector<int> ord;
    vector<int> visited(n,0);
    for(int i=0; i<n; i++)if(num[i]<=t){
        dfs(i,ord,visited,t);
    }
    if(f){f=false;return true;}
    reverse(ord.begin(),ord.end());
    vector<int> dist(n);
    int m=-1;
    for(auto& i:ord){
        dist[i]=0;
        for(auto& c:radj[i]){
            if(num[c]<=t)dist[i]=max(dist[i],dist[c]+1);
        }
        m=max(m,dist[i]);
    }
    return m>=k-1;
}
signed main(){
    cin>>n>>m>>k;
    adj.resize(n);
    radj.resize(n);
    num.resize(n);
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    int l=0, h=1e9+5;
    while(l<h){
        int mid = l+(h-l)/2;
        if(ok(mid)){
            h = mid;
        }else{
            l=mid+1;
        }
    }
    if(l==1e9+5)l=-1;
    cout<<l<<"\n";
}
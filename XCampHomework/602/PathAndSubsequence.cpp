#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> a(n), b(n+1);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=k; i++)cin>>b[i];
    for(int i=k+1; i<=n; i++)b[i]=-1;
    vector<int> d(n,INT_MAX);
    if(a[0]==b[1])d[0]=1;
    else d[0]=0;
    deque<pair<int,int>> pq;
    pq.push_front({d[0],0});
    while(pq.size()){
        auto [dist, i] = pq.front();
        pq.pop_front();
        if(dist!=d[i])continue;
        for(auto& c:adj[i]){
            if(a[c] == b[d[i]+1]&&d[i]+1<d[c]){
                d[c] = d[i]+1;
                pq.push_back({d[c],c});
            }
            if(d[i]<d[c]&&a[c]!=b[d[i]+1]){
                d[c] = d[i];
                pq.push_front({d[c],c});
            }
        }
    }
    cout<<((d[n-1]==k)?("Yes"):("No"))<<"\n";
}
#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    for(int s=0; s<n; s++){
        vector<int> d(n,INT_MAX);
        vector<bool> r(n,false);
        for(auto& c:adj[s])d[c.first] = c.second;
        while(true){
            int v = -1;
            for(int j=0; j<n; j++){
                if(!r[j]&&(v==-1||d[j]<d[v]))v=j;
            }
            if(v==-1)break;
            r[v]=true;
            d[(v+1)%n]=min(d[(v+1)%n],d[v]+1);
            for(auto& [c,dist]:adj[v]){
                d[(c+d[v])%n] = min(d[(c+d[v])%n],d[v]+dist);
            }
         //   cout<<v<<" ";
          //  for(auto& i:d)cout<<i<<" ";cout<<"\n";
        }
        for(int i=0; i<n; i++){
            if(i==s)cout<<"0 ";
            else cout<<d[i]<<" ";
        }
        cout<<"\n";
    }
}
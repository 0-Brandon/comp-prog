#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, C, R, k;
    cin>>n>>m>>C>>R>>k;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
    for(int i=0; i<C; i++){
        q.push({0,i,i});
    }
    vector<int> vc(n);
    int ans = 0;
    map<pair<int,int>,bool> visited;
    while(!q.empty()){
        auto[d,i,r] = q.top();
        q.pop();
        if(vc[i]>=k)continue;
        if(visited[make_pair(i,r)]==true)continue;
        visited[make_pair(i,r)]=true;
        vc[i]++;
        if(i>=C&&vc[i]==k)ans++;
        for(auto& [c,di]:adj[i]){
            if(di+d>R)continue;
            q.push({di+d,c,r});
        }
    }
    cout<<ans<<"\n";
    for(int i=C; i<n; i++){
        if(vc[i]>=k)cout<<i+1<<"\n";
    }
}
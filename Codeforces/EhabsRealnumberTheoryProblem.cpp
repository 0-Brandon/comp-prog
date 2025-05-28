#include <bits/stdc++.h>

using namespace std;

int main(){
    const int N = 1000001;
    vector<int> lp(N+1);
    vector<int> pr;
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    lp[1]=1;
    pr.insert(pr.begin(),1);
    int n;
    cin>>n;
    vector<int> x(n);
    vector<pair<int,int>> edges;
    int m = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        m = max(m,x[i]);
        for(auto& j:pr){
            if(j==1)continue;
            while(x[i]%(j*j)==0){
                x[i]/=(j*j);
            }
            if(j*j>x[i])break;
        }
        edges.emplace_back(lp[x[i]],x[i]/lp[x[i]]);
    }
    vector<vector<int>> adj(N+1);
    for(auto& i:edges){
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    int ans = INT_MAX;
    for(auto& s:pr){
        if(s*s>m)break;
        queue<int> q;
        vector<int> dist(N,INT_MAX);
        vector<int> par(N,-1);
        dist[s] = 0;
        q.push(s);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto& c:adj[i]){
                if(c==par[i])continue;
                if(dist[c]==INT_MAX){
                    dist[c] = dist[i]+1;
                    par[c] = i;
                    q.push(c);
                }
                else{
                    ans = min(ans,dist[c]+dist[i]+1);
                }
            }
        }
    }
    if(ans==INT_MAX)cout<<"-1\n";
    else cout<<ans<<"\n";
}

//2*5 2*1 3*1 2*3 7*1 7*5
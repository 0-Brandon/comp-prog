#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<long long> x(n);
    vector<vector<int>> cnt(61);
    for(int i=0; i<n; i++){
        cin>>x[i];
        for(int j=0; j<61;j++){
            if((x[i]>>j)&1)cnt[j].push_back(i);
        }
    }
    for(auto& i:cnt)if(i.size()>=3){cout<<"3\n";return 0;}
    vector<set<int>> adj(n);
    for(int i=0; i<61; i++){
        if(cnt[i].size()==2){
            adj[cnt[i][0]].insert(cnt[i][1]);
            adj[cnt[i][1]].insert(cnt[i][0]);
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<61; i++)if(cnt[i].size()==2){
        adj[cnt[i][0]].erase(cnt[i][1]);
        adj[cnt[i][1]].erase(cnt[i][0]);
        int s = cnt[i][0];
        int t = cnt[i][1];
        vector<int> d(n,-1);
        queue<int> q;
        q.push(s);
        d[s]=0;
        while(!q.empty()){
            int cur = q.front();q.pop();
            for(auto& c:adj[cur]){
                if(d[c]==-1){
                    d[c]=d[cur]+1;
                    q.push(c);
                }
            }
        }
        adj[cnt[i][0]].insert(cnt[i][1]);
        adj[cnt[i][1]].insert(cnt[i][0]);
        if(d[t]==-1)continue;
        ans = min(ans,d[t]+1);
    }
    
    if(ans==INT_MAX)ans=-1;
    cout<<ans<<"\n";
}
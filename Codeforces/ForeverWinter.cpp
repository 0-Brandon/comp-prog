#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> adj(n);
vector<int> ind(n,0);
        for(int i=0; i<m;i++){
            int a, b;
            cin>>a>>b;
            a--,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
            ind[a]++;
            ind[b]++;
        }
        int s=0;
        for(int i=0; i<n; i++){
            if(ind[i]==1){
                s=i;
                break;
            }
        }
        int x=0;
        int y=adj[adj[s][0]].size()-1;
        for(auto& i:adj[adj[s][0]]){
            if(adj[i].size()!=1){
                x=adj[i].size();
                break;
            }
        }
        cout<<x<<" "<<y<<"\n";
    }
}
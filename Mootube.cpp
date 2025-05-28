#include <bits/stdc++.h>

using namespace std;
void bfs(int k, int v,vector<vector<pair<int,int>>>&x, vector<bool>&visited, int path, int& count){
    count++;
    for(auto i:x[v]){
        if(!visited[i.first]){
            visited[i.first]=true;
            int temp = min(path, i.second);
            if(temp>=k){
                bfs(k,i.first,x,visited,temp,count);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n, q;
    cin>>n>>q;
    vector<vector<pair<int,int>>> x(n+1,vector<pair<int,int>>());
    for(int i=0; i<n-1; i++){
        int a, b,c;
        cin>>a>>b>>c;
        x[a].push_back({b,c});
        x[b].push_back({a,c});
    }
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        vector<bool> visited(n+1,false);
        visited[b]=true;
        int count = -1;
        bfs(a,b,x,visited,INT_MAX,count);
        cout<<count<<"\n";
    }
}
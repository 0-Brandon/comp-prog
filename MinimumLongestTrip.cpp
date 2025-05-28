#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>> adj(n),radj(n);
    vector<int> ind(n,0);
    vector<int> ord;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[--a].push_back({--b,c});
        radj[--b].push_back({a,c});
        ind[a]++;
    }
    queue<int>
    for(int i=0; i<n; i++)if(ind[i]==0)q.push(i);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ord.push_back(cur);
        for(auto& [c,lol]:radj[cur])if(--ind[c]==0)q.push(c);
    }
    vector<int> len(n);
    vector<int> s(n);
    for(auto& i:ord){
        int m = 0, sc = 0;
        for(auto& [c,label]:adj[i]){
            if(len[c]>m){
                m = len[c];
                sc = label;
            }
            if(len[c]==m&&c<sc){
                sc = c;
            }
        }
        len[i] = len[c]+1;
    }
}
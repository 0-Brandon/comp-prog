#include <bits/stdc++.h>

using namespace std;
void dfs(int i,vector<vector<int>>& x, vector<bool>& visited){
    for(auto j:x[i]){
        if(!visited[j]){
            visited[j]=true;
            dfs(j,x,visited);
        }
    }
}
int main(){
    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout);
    int n;
    cin>>n;
    vector<vector<int>> x(n+1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        x[b].push_back(a);
    }
    bool done = false;
    for(int i=1; i<n+1; i++){
        vector<bool> visited(n+1,false);
        visited[0]=true;
        visited[i]=true;
        dfs(i,x,visited);
        bool l=true;
        for(auto j:visited){
            if(!j)l=false;
        }
        if(l) {
            cout<<i;
            done=true;
            break;
        }
    }
    if(!done)cout<<-1;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> dx{-1,1,0,0};
vector<int> dy{0,0,1,-1};
int ans = 0;
int n;
void dfs(int curr, int x, int y, vector<vector<int>>& arr, vector<vector<bool>>& visited){
    if(curr==25-n){ 
        if(x==4&&y==4){
            ans++;
           
        }
    }
    for(int i=0; i<4; i++){
        x=x+dx[i];
        y=y+dy[i];
        if(x>=0&&x<5&&y>=0&&y<5&&arr[x][y]==1&&!visited[x][y]){
            visited[x][y]=true;
            dfs(curr+1, x, y, arr, visited);
            visited[x][y]=false;
        }
        y-=dy[i];
        x-=dx[i];
    }
}
int main(){
    cin>>n;
    vector<vector<int>> x(5, vector<int>(5,1));
    for(int i=0; i<n; i++){
        int t, t1;
        cin>>t>>t1;
        x[t-1][t1-1]=0;
    }
    vector<vector<bool>> visited(5,vector<bool>(5,false));
    visited[0][0]=true;
    dfs(1,0,0,x,visited);
    cout<<ans;
}
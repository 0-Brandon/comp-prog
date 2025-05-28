#include <bits/stdc++.h>

using namespace std;
int counter = 0;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0}; 
void dfs(int i, int j, vector<vector<bool>>& visited,vector<vector<char>>& lol){
    if(!(i>=0&&i<visited.size()&&j>=0&&j<visited[0].size()&&!visited[i][j]&&lol[i][j]=='*'))
    return;
    visited[i][j] = true;
    counter++;
    for(int k=0; k<4; k++){
        int x = i+dx[k], y=j+dy[k];
        dfs(x,y,visited,lol);
    }
}
int main(){
    int w, h;
    cin>>w>>h;
    vector<vector<char>> x(h,vector<char>(w));
    for(int i=0; i<h; i++){
        string s;
        cin>>s;
        int j=0;
        for(auto k:s){
        x[i][j++] = k;
        }
    }
    vector<vector<bool>> visited(h, vector<bool>(w));
    int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(!visited[i][j]){
                dfs(i,j,visited,x);
                ans = max(ans,counter);
                counter = 0;
            }
        }
        
    }
    cout<<ans;
}
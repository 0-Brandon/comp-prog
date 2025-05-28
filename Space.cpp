#include <bits/stdc++.h>

using namespace std;

vector<int> dx{1,-1,0,0};
vector<int> dy{0,0,1,-1};
int n;
void dfs(int i, int j, vector<vector<char>> & a, vector<vector<bool>>& visited){
    for(int k=0; k<4; k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]=='*'&&!visited[x][y]){
            visited[x][y]=true;
            dfs(x,y,a,visited);
        }
    }
}
void bfs(int i, int j, vector<vector<char>> & a, vector<vector<bool>>& visited){
    queue<pair<int,int>> ord;
    ord.push({i,j});
    while(!ord.empty()){
        auto[nx,ny]=ord.front();
        ord.pop();
        for(int k=0; k<4; k++){
            int x = nx+dx[k];
            int y=ny+dy[k];
            if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]=='*'&&!visited[x][y]){
                visited[x][y]=true;
                ord.push({x,y});
            }
        }
    }
}
int main(){
    cin>>n;
    vector<vector<char>> x(n,vector<char>(n));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            x[i][j]=s[j];
        }
    }
    int count = 0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(x[i][j]=='*'&&!visited[i][j]){
                visited[i][j]=true;
                bfs(i,j,x,visited);
                count++;
            }
        }
    }
    cout<<count;
}
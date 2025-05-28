#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> dx({{0,-1},{0,1},{1,0},{-1,0}});
vector<int> blocks;
int n;
void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& x, int& count){
    if(visited[i][j]) return;
    visited[i][j]=true;
    blocks[count]++;
    for(int a=0; a<4; a++){
        int l=i+dx[a].first;
        int k=j+dx[a].second;
        if(l<n&&l>=0&&k<n&&k>=0&&x[l][k]==x[i][j]){
            dfs(l, k, visited, x, count);
        }
    }
}
int main(){
    freopen("multimoo.out","w",stdout);
    freopen("multimoo.in","r",stdin);
    cin>>n;
    vector<vector<int>> x(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>x[i][j];
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int c = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                blocks.push_back(0);
                dfs(i,j, visited, x, c);
                c++;
            }
        }
    }
    int ans1=0, ans2=0;
    for(auto& i:blocks){
        ans1=max(ans1,i);
    }
    ans2 = ans1*2;
    cout<<ans1<<"\n"<<ans2;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};
void dfs(vector<vector<char>>& x, vector<vector<bool>>& visited, int k,int j, int n, int& p, int& a){
    if(visited[k][j])return;
    visited[k][j]=true;
    a++;
    for(int i=0; i<4; i++){
        k+=dx[i];
        j+=dy[i];
        if(k<0||k>=n||j<0||j>=n){
            p++;
        }
        if(k>=0&&k<n&&j>=0&&j<n&&x[k][j]=='.'){
                p++;
        }
        if(k>=0&&k<n&&j>=0&&j<n&&x[k][j]=='#'){
            dfs(x,visited,k,j,n,p,a);
        }
        k-=dx[i];
        j-=dy[i];
    }
}
int main(){
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    int n;
    cin>>n;
    vector<vector<char>> x(n,vector<char>(n));
    for(int i=0; i<n; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<n; j++){
            x[i][j]=temp[j];
        }
    }
    int ansp = INT_MAX, ansa = 0;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int p=0; 
            int a=0;
            if(!visited[i][j]&&x[i][j]=='#'){
                dfs(x,visited,i,j,n,p,a);
                if(a>ansa){
                    ansa=a;
                    ansp=p;
                }
                else if(ansa==a){
                    ansp=min(ansp,p);
                }
            }
        }
    }
    cout<<ansa<<" "<<ansp;
}
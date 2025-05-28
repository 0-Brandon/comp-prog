#include <bits/stdc++.h>

using namespace std;
void dfs(int i,int j,vectorvector<char>>& x, vector<vector<bool>>& visited, int & count){
    int mcount = 0;
    for(int a=0; a<n; a++){
        
    }
}
int main(){
    int n;
    cin>>n;
    int sx,sy;
    vector<vector<char>> x(n,vector<char>(n));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            x[i][j]=s[j];
            if(s[j]=='C'){
                sx=i;
                sy=j;
            }
        }
    }
    int count = 0;

    dfs(sx,sy,x,visited,count);
    cout<<count;
}
#include <bits/stdc++.h>

using namespace std;
int n, m;
//dir is in the direction it comes from
//down is 1, up is 2, left is 3, right is 4
int calc(vector<vector<int>>& x, int i, int j, int dir){
    if(i<0||i>=n||j<0||j>=m) return 0;
    int count = 0;
    count++;
    if(x[i][j]=='\\'){
        if(dir==1){
            dir=4;
            j-=1;
        }
        else if(dir==2){
            dir=3;
            j+=1;
        }
        else if(dir==4){
            dir=1;
            i-=1;
        }else{
            dir=2;
            i+=1;
        }
    }else{// '/'
        if(dir==1){
            dir=3;
            j+=1;
        }
        else if(dir==2){
            dir=4;
            j-=1;
        }
        else if(dir==3){
            dir=1;
            i-=1;
        }else{
            dir=2;
            i+=1;
        }
    }
    count+=calc(x,i,j,dir);
    return count;
}

int main(){
    freopen("mirror.in","r",stdin);
    freopen("mirror.out","w",stdout);
    cin>>n>>m;
    vector<vector<int>>x(n,vector<int>(m));
    for(int i=0; i<n; i++){
        string t;
        cin>>t;
        for(int j=0; j<m; j++){
            x[i][j]=t[j];
        }
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        ans = max(ans,calc(x,0,i,2));
    }
    for(int i=0; i<n; i++){
        ans = max(ans,calc(x,i,0,3));
    }
    for(int i=0; i<n; i++){
        ans= max(ans, calc(x,i,m-1,4));
    }
    for(int i=0; i<m; i++){
        ans = max(ans,calc(x,n-1,i,1));
    }
    cout<<ans;
}
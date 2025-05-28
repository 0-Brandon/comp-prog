#include <bits/stdc++.h>

using namespace std;
int r,c;
int re(int i, int j, vector<vector<int>>& x){
    int ans = 0;
    if(i==r-1&&j==c-1) return 1;
    for(int k=i+1; k<r; k++){
        for(int y=j+1;y<c; y++){
            if(x[k][y]!=x[i][j]){
                ans+=re(k,y,x);
            }
        }
    }
    return ans;
}

int main(){
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    cin>>r>>c;
    vector<vector<int>> x(r,vector<int>(c));
    for(int i=0; i<r; i++){
        string temp;
        cin>>temp;
        for(int j=0; j<c; j++){
            x[i][j]=temp[j];
        }
    }
    cout<<re(0,0,x);
}
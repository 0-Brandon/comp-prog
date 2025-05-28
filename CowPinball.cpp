#include <bits/stdc++.h>

using namespace std;

int main(){
    int r;
    cin>>r;

    vector<vector<int>> x(r);
    for(int i=1; i<=r; i++){
        for(int j=0; j<i; j++){
            int temp;
            cin>>temp;
            x[i-1].push_back(temp);
        }
    }
    for(int i=r-2; i>=0; i--){
        for(int j=0; j<x[i].size(); j++){
            x[i][j]+=max(x[i+1][j], x[i+1][j+1]);
        }
    }
    cout<<x[0][0];
}
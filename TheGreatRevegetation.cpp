#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> x(n+1);
    for(int i=0; i<m; i++){
        int j,k;
        cin>>j>>k;
        x[j].push_back(k);
        x[k].push_back(j);
    }
    vector<int> d(n+1,-1);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<=4; j++){
            bool done = true;
            d[i]=j;
            for(auto k:x[i]){
                if(d[k]==j)
                done=false;
            }
            if(done){
                break;
            }
        }
    }
    for(int i=1; i<n+1; i++){
        cout<<d[i];
    }
}
#include <bits/stdc++.h>

using namespace std;
int n, m;

int main(){
    cin>>n>>m;
    vector<int> x(n);
    vector<int>cell(m);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<m; i++){
        cin>>cell[i];
    }
    cell.erase(unique(cell.begin(),cell.end()),cell.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    int ans = 0;
    int cellidx=0;
    for(int i=0; i<x.size(); i++){
        while(cellidx<cell.size()-1&&abs(cell[cellidx+1]-x[i])<abs(cell[cellidx]-x[i])){
            cellidx++;
        }
        ans = max(ans, abs(cell[cellidx]-x[i]));
    }
    cout<<ans;
}
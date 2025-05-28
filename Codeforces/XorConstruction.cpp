#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n,0);
    for(int i=0; i<n-1; i++){
        cin>>x[i+1];
        x[i+1]^=x[i];
    }
    for(int i=0; i<30; i++){
        vector<int> zo(2,0);
        for(int j=0; j<n; j++){
            zo[(x[j]>>i)&1]++;
        }
        if(zo[1]>zo[0]){
            for(int j=0; j<n; j++){
                x[j]^=(1<<i);
            }
        }
    }
    for(auto& i:x)cout<<i<<" ";
    cout<<"\n";
}
int main(){
    solve();
}
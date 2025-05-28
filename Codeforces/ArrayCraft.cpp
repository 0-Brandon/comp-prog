#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x, y;cin>>n>>x>>y;
    x--,y--;
    swap(x,y);
    int a = 1;
    if(x&1)a=-1;
    //x is smaller than y
    for(int i=0; i<n; i++){
        if(i==x)a=1;
        cout<<a<<" ";
        if(i>=y||i<x)a*=-1;
    }
    cout<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>


using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    int i=1, j=n;
    while(j>=i){
        for(int l=0; j>i&&l<k-1; l++){
            cout<<j--<<" ";
        }
        if(j>=i)cout<<i++<<" ";
    }
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
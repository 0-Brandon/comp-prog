#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int sumw=0, maxh=0;
    for(int i=0; i<n; i++){
        int h,w;
        cin>>h>>w;
        sumw+=w;
        maxh=max(h,maxh);
    }
    cout<<2*sumw+2*maxh<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> a(x);
    for(int i=0; i<x; i++){
        cin>>a[i];
    }
    x++;
    sort(a.begin(),a.end());
    a.push_back(a[0]+n);
    int c = 0;
    int cnt = 0;
    for(int i=1; i<x; i++){
        if((a[i]-a[i-1]-1)/2%2==0){
            c+=(a[i]-a[i-1]-1)/2;
        }
        else{
            c+=(a[i]-a[i-1]-1)/2+1;
        }
        if(a[i]-a[i-1]==2)cnt++;
    }
    if(c>=y){
        cout<<y*2+(x-3)+cnt<<"\n";
    }
    else{
        cout<<c*2+(x-3)+cnt+(y-c-2)<<"\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    int b=0,l=0;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(x[i]<x[i-1])b=i;
    }
    if(is_sorted(x.begin(),x.end())||(is_sorted(x.begin(),x.begin()+b)&&is_sorted(x.begin()+b,x.end())&&x.back()<=x[0]))cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}
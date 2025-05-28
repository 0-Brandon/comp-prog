//n takes n seconds
//n-1 takes max(x[n]-x[n-1]+1,0)+x[n-1]
//if n is shorter than [n-1], we take x[n-1] time
//if n is taller than [n-1] we take x[n]+1
//if n-1 is taller than n-2, we just take t[n-1]+1,
//else we are taller than n-2, so we take x[n]

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int>t(n);
    t.back()=x.back();
    for(int i=n-2; i>=0; i--){
        if(x[i]>x[i+1]){
            //we don't have to wait
            if(t[i+1]<x[i])t[i] = x[i];
            //we do
            else t[i] = t[i+1]+1;
        }
        else t[i] = t[i+1]+1;
    }
    cout<<*max_element(t.begin(),t.end())<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
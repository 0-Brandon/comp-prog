#include <bits/stdc++.h>
#define int long long
using namespace std;
void clear(stack<int>& s){
    while(!s.empty())s.pop();
}
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> nmax(n,n), pmax(n,-1), nmin(n,n), pmin(n,-1);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    x.push_back(-1);
    x.push_back(1e6+5);
    stack<int> s;
    s.push(n);
    for(int i=0; i<n; i++){
        while(x[s.top()]>=x[i])s.pop();
        pmin[i]=s.top();
        if(pmin[i]==n)pmin[i]=-1;
        s.push(i);
    }
    clear(s);
    s.push(n);
    for(int i=n-1; i>=0; i--){
        while(x[s.top()]>x[i])s.pop();
        nmin[i]=s.top();
        s.push(i);
    }
    clear(s);
    s.push(n+1);
    for(int i=0; i<n; i++){
        while(x[s.top()]<=x[i])s.pop();
        pmax[i]=s.top();
        if(pmax[i]==n+1)pmax[i]=-1;
        s.push(i);
    }
    clear(s);
    s.push(n+1);
    for(int i=n-1; i>=0; i--){
        while(x[s.top()]<x[i])s.pop();
        nmax[i]=s.top();
        if(nmax[i]==n+1)nmax[i]=n;
        s.push(i);
    }
    int smax=0, smin=0;
    for(int i=0; i<n; i++){
        smax+=((i-pmax[i])*(nmax[i]-i)-1)*x[i];
        smin+=((i-pmin[i])*(nmin[i]-i)-1)*x[i];
    }
    cout<<smax-smin<<"\n";
}
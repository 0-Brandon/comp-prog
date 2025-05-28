#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    int ans=0;
    vector<int> t(n);
    t[0]=-1;
    stack<int> s;
    for(int i=0; i<n; i++){
        t[i]=0;
        while(!s.empty()&&x[s.top()]<x[i]){
            t[i]=max(t[i],t[s.top()]+1);
            s.pop();
        }
        if(s.empty()) t[i]=-1;
        ans=max(ans,t[i]+1);
        s.push(i);
    }
    cout<<ans<<"\n";
}
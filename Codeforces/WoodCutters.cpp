#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n),h(n);
    for(int i=0; i<n; i++)cin>>x[i]>>h[i];
    int f=INT_MIN;
    int c=0;
    for(int i=0; i<n; i++){
        if(x[i]-h[i]>f)c++,f=x[i];
        else if (i==n-1||x[i]+h[i]<x[i+1])c++,f=x[i]+h[i];
        else f=x[i];
    }
    cout<<c<<"\n";
}
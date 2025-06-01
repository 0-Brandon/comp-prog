#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    vector<int> x(21);
    x[0]=1,x[1]=1;
    for(int i=2; i<21; i++)x[i]=x[i-1]+x[i-2];
    int n;cin>>n;cout<<x[n];
}
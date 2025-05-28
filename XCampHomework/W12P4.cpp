#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    cin>>n;
    vector<bitset<3005>> x(n);
    for(int i=0; i<n; i++){
        string s;cin>>s;
        for(int j=0; j<n; j++){
            if(s[j]=='0')x[i][j] = 0;
            else x[i][j]=1;
        }
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
           int co = (x[i]&x[j]).count();
           ans+=co*(co-1);
        }
    }
    cout<<ans/2<<"\n";
}
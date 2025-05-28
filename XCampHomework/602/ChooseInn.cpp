#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, k, p;
    cin>>n>>k>>p;
    int x[n];
    int c[n];
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(b>=102)b=101;
        x[i]=b;
        c[i]=a;
    }
    long long ans = 0;
    vector<int> s(k);
    int po = n-1;
    for(int i=n-1; i>=0; i--){
        if(x[i]<=p){
            while(po>i)s[c[po--]]++;
        }
        ans+=s[c[i]];
        if(x[i]<=p){
            s[c[po--]]++;
        }
    }
    cout<<ans<<"\n";
}
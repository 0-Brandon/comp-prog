#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    for(int i=1; i<=n; i++){
        vector<int> last(n+1,-1e9);
        int cc = n;
        for(int j=0; j<n; j++){
            if(j-last[x[j]]<=i)cc--;
            else last[x[j]] = j;
        }
        cout<<cc<<"\n";
    }
}
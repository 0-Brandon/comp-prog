#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> b;
    bitset<25005> dp;
    dp[0]=1;
    for(int i=0; i<n; i++){
        if(!dp[a[i]])b.push_back(a[i]);
        for(int j=0; j+a[i]<25005; j++)dp[j+a[i]] = dp[j+a[i]]|dp[j];
    }
    cout<<b.size()<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}
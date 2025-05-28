#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;
signed main(){
    int n, d;
    cin>>n>>d;
    int a, b;
    vector<int> x(n);
    cin>>a>>b;
    for(int i=0; i<n; i++)cin>>x[i];
    int NUM = 500;
    for(int i=0; i<min(NUM,d); i++){
        sort(x.rbegin(),x.rend());
        for(int j=b; j<a; j++)x[j]++;
    }
    if(d>NUM){
        int left = d-NUM;
        for(int i=0; i<a; i++)x[i]+=left/a*(a-b);
        for(int i=0; i<left%a; i++){
            sort(x.rbegin(),x.rend());
            for(int j=b; j<a; j++)x[j]++;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++)ans=(ans+x[i]*x[i]%mod)%mod;
    cout<<ans<<"\n";
}
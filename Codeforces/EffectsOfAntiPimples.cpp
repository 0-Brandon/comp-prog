#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;
int expo(int a, int b){
    int ans = 1;
    for(;b; b>>=1, a = (a*a)%mod){
        if(b&1)ans = (ans*(a))%mod;
    }
    return ans;
}
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j+=(i+1)){
            x[i] = max(x[i],x[j]);
        }
    }
    vector<int> cnt(1e6+1,0);
    for(int i=0; i<n; i++){
        cnt[x[i]]++;
    }
    int ans = 0;
    int s = 0;
    for(int i=0; i<cnt.size(); i++){
        int cur = (((expo(2,s+cnt[i])-expo(2,s)+mod)%mod) * i)%mod;
        ans = (ans+cur)%mod;
        s +=cnt[i];
    }
    cout<<ans;
}
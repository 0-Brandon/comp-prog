#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod, m, k, x;
int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
signed main(){
    cin>>mod>>m>>k>>x;
    cout<<(x%mod+m%mod*exp(10,k)%mod)%mod;
}
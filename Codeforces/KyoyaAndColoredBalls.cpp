#include <bits/stdc++.h>
//not working
using namespace std;

int mod = 1000000007;
int main(){
    int k;
    cin>>k;
    vector<int> x(k);
    for(int i=0; i<k; i++){
        cin>>x[i];
    }
    vector<long long int> fac(5001);
    fac[0]=1;
    for(int i=1; i<5000; i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    long long ans = 1;
    long long int s=0;
    for(int i=0; i<k; i++){
        s++;
        ans*=fac[s+x[i]-2]/((fac[s-1]*fac[x[i]-1])%mod);
        s+=x[i]-1;
        ans%=mod;
    }
    cout<<ans;
}
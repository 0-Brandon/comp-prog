#include<bits/stdc++.h>
using namespace std;
constexpr long long mod=998244353;
constexpr int N = 5005;
signed main(){
    int n, cur;
    cin>>n;
    vector<int> a(N);
    vector<long long> f(N),g(N);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++)if(a[i]){
        while(a[i]){
            cur++;
            for(int j=cur;j>=0;j--)g[j+a[i]]=(g[j+a[i]]+f[j])%mod, f[j]=(f[j]+f[j+1])%mod;
            a[i]--;
            f[0]=0;
        }
        for(int i=0;i<=cur;i++)f[i]=(f[i]+g[i])%mod, g[i]=0;
    }
    
    long long ans=0;
    for(int j=0;j<=cur;j++)ans+=f[j];
    cout<<ans%mod<<'\n';
}
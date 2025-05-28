#include <bits/stdc++.h>
#define int long long

using namespace std;
constexpr int mod = 998244353;
int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
signed main(){
    int n, m;cin>>n>>m;
    vector<int> fac(500000);
    fac[0]=1;
    for(int i=1; i<fac.size(); i++){
        fac[i] = fac[i-1]*i%mod;
    }
    auto c = [&](int i, int j){
        return fac[i]*exp(fac[j],mod-2)%mod*exp(fac[i-j],mod-2)%mod;
    };
    auto per =[&](int n, int k){
        return fac[n]*exp(fac[n-k],mod-2)%mod;
    };
    vector<int> x(n);
    int su=0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        su+=x[i];
    }
    if(su%2==1){
        //not possible to have two opposing ones
        cout<<exp(m,n)<<"\n";return 0;
    }
    map<int,bool> cnt;
    int p = 0;
    int cur = 0;
    for(int i=0; i<n; i++){
        cur+=x[i];
        if(cnt[cur-su/2])p++;
        cnt[cur]=true;
    }
    int e = n-2*p;
    int ans = 0;
    for(int i=0; i<=p; i++){
        int cur = c(p,i);//num ways to choose i pairs
        cur = cur*per(m,i)%mod; //num ways to give each chosen pair it own color
        if(m-i<=0&&e!=0)continue;
        if(m-i==1&&i!=p)continue;
        int d = m-i;
        cur = cur*exp(d,e+p-i)%mod; //num ways to give remaining nodes colors
        cur = cur*exp(d-1,p-i)%mod;
        ans = (ans+cur)%mod;
    }
    cout<<ans<<"\n";
    //each pair is its own color
    //the ones not a node can be any remaining color
    //the other pairs must be different colors
        //we have some pairs that are opposite each other let this number be p
        //let e be the ones that are not opposite any other node
        //iterate i up to p
        //P choose i pairs
        //to color these i pairs, we have mPi colors
        //we are left with d = m-i colors
        //for remaining pairs, we have (p-i)*(d-1)+ (e+p-i)*d
        //we can color the remainign ones any color, except the pairs must be different colors

}
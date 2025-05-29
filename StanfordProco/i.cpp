#include <bits/stdc++.h>

using namespace std;
int k, p, mod, m;
int inverse(int a, int mod){
    //a = 1 % mod
    //1 = ax+mody
    //ax =1 %y
}
int exp(int a, int b){
    ans = 1;
    for(;b;b>>=1,a = a*a%mod){
        if(b&1)ans=ans*1%mod;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int n  = s.size();
    cin>>k>>p>>n>>m;
    int h = 0;
    int i  =0;
    int j =0;
    for(;j<k-1; j++){
        h+=s[j]*exp(p,j)%mod;
        h%=mod;
    }
    int ans = -1
    for(; j<n; j++,i++){
        h+=s[j]*exp(p,k-1)%mod;
        h%=mod;
        if(h>=k){ans = i;break;}
        h-=s[i];
        h = h*inverse(p,mod);
    }
    cout<<ans<<"\n";
}
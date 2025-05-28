#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod = 998244353;
int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1, a = (a*a)%mod){
        if(b&1)ans = (ans*a)%mod;
    }
    return ans;
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    int ans = 1;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='?')ans=(ans*(i))%mod;
    }
    bool b = (s[0]!='?');
    if(!b){cout<<0<<"\n";}
    else {cout<<ans<<"\n";}
    for(int i=0; i<m; i++){
        int idx;
        char c;
        cin>>idx>>c;
        if(idx==1){
            s[0]=c;
            b=(s[0]!='?');
        }
        else{
            if(s[idx-1]=='?')ans = (ans*exp(idx-1,mod-2))%mod;
            s[idx-1]=c;
            if(s[idx-1]=='?')ans = (ans * (idx-1))%mod;
        }
        if(!b)cout<<0<<"\n";
        else cout<<ans<<"\n";
    }
}
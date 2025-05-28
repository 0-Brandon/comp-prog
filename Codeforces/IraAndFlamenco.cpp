#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1000000007;

int pow(int a, int b){
    int res=1;
    for(;b;b/=2,a=(a*a)%mod){
        if(b%2)res=(res*a)%mod;
    }
    return res;
}
void solve(){
    int n, m;
    cin>>n>>m;
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    int last=-1;
    int miss=0;
    int res=1, ans=0;
    for(auto&[num, c]:cnt){
        if(num!=last+1){
            miss=num;
            res=1;
        }
        res=(res*c)%mod;
        if(num-miss+1>m){
            res*=pow(cnt[num-m],mod-2);
            res%=mod;
        }
        if(num-miss+1>=m){
            ans+=res;
            ans%=mod;
        }
        last=num;
    }
    cout<<ans<<"\n"; 
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
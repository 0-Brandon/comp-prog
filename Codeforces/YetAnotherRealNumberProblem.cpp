#include <bits/stdc++.h>
#define int long long

using namespace std;
constexpr int mod = 1e9+7;
int expo(int a, int b){
    int ans = 1;
    for(;b;b/=2,a=a*a%mod){
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> v;
    vector<int> x(n),r(n);
    int ans = 0;
    int su = 0;
    int tc = 0;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        su+=a;
        ans = su;
        int t=a;
        int d=0;
        while(t%2==0)d++,t/=2;
        x[i] = a>>d;
        r[i] = d;
        int ma = 0;
        int p =i;
        int cnt = 0;
        for(int j=v.size()-1; j>=0; j--){
            while(p>v[j])ma = max(ma,x[p]<<r[p--]);
            if(x[v[j]]>ma){cnt+=r[v[j]];continue;}
            int t = r[v[j]];
            cnt+=t;
            int a = x[v[j]]<<r[v[j]];
            while(t--){
                ans-=a/2;
                a/=2;
                ans=(ma+ans)%mod;
                ma=ma*2%mod;
            }
            if(cnt>31)break;
        }
        ans=ans+ma*(expo(2,tc-cnt)-1)%mod;
        ans%=mod;
        cout<<ans<<" ";
        tc+=d;
        if(a%2==0)v.push_back(i);
        if(v.size()>31)v.erase(v.begin());
    }
    cout<<"\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}
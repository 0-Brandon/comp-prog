#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
vector<int> fac(2*10e5+1);
void solve(){
    string s;
    cin>>s;
    int sec = 0;
    int ans1 = 0, ans2 = 1;
    int cur = 0;
    for(int i=0; i<s.size(); i++){
        if(i>0&&s[i]!=s[i-1]){
            ans1+=cur-1;
            if(cur>1)ans2 = (ans2 * cur)%mod;
            cur=0;
        }
        cur++;
    }
    ans1+=cur-1;
    if(cur>1)ans2 = (ans2 * cur)%mod,sec++;
    cout<<ans1<<" "<<(ans2*fac[ans1])%mod<<"\n";
}
signed main(){
    fac[0]=1;
    for(int i=1; i<2e5+1; i++){
        fac[i] = (fac[i-1] * i)%mod;
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
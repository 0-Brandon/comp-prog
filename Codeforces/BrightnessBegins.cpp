#include <bits/stdc++.h>
#define int long long
using namespace std;

int sqrt(int x){
    int ans = 0;
    for(int k=1LL<<31; k; k/=2)if((ans+k)*(ans+k)<=x)ans+=k;
    return ans;
}
void solve(){
    int k;cin>>k;
    int cur = k;
    int l = 0;
    while(true){
        if(sqrt(cur)-sqrt(l)==0)break;
        int a = sqrt(cur)-sqrt(l);
        l = cur;
        cur+=a;
    }
    cout<<cur<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}
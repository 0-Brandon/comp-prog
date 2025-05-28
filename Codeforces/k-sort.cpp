#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    vector<int> dif(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(i>0)dif[i] = x[i-1]-x[i];
    }
    //dif contains how much we need to increase i to be euqla to i-1
    //if prev one increases by x, we need to increase by x +dif[i]
    for(int i=1; i<n; i++){
        dif[i] = max(0LL,dif[i-1])+dif[i];
    }
    //dif[i] contains how much we need to increase i by
    sort(dif.rbegin(),dif.rend());
    int pref = 0;
    int ans = 0;
    while(dif.size()&&dif.back()<=0)dif.pop_back();
    int acc = 0;
    while(dif.size()){
        int cur = dif.back();
        cur-=acc;
        ans+=cur*(dif.size()+1);
        acc+=cur;
        dif.pop_back();
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
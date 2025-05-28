#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, v;
    cin>>n>>m>>v;
    vector<int> pre(n+2);
    vector<int> x(n+2), pref(n+2),suf(n+2);
    for(int i=1; i<=n; i++){
        cin>>x[i];
        pre[i+1] = pre[i]+x[i];
    }
    for(int i=1; i<=n; i++){
        int l = 1, h = i;
        while(l<h){
            int mid = (l+h+1)/2;
            if(pre[i+1]-pre[mid]>=v){
                l = mid;
            }else{
                h = mid-1;
            }
        }
        if(pre[i+1]-pre[l]>=v)
        pref[i] = pref[l-1]+1;
    }
    for(int i=n; i>=0; i--){
        int l = i, h = n;
        while(l<h){
            int mid = (l+h-1)/2;
            if(pre[mid+1]-pre[i]>=v){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        if(pre[l+1]-pre[i]>=v)
        suf[i] = suf[l+1]+1;
    }
    int ans = -1;
    for(int i=1; i<=n; i++){
        int l = i, h = n;
        while(l<h){
            int mid = (l+h+1)/2;
            if(pref[i-1]+suf[mid+1]>=m){
                l = mid;
            }else{
                h = mid-1;
            }
        }
        if(pref[i-1]+suf[l+1]>=m)ans = max(ans,pre[l+1]-pre[i]);
    }
    if(suf[1]>=m)ans = max(ans,0LL);
    cout<<ans<<"\n";
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}